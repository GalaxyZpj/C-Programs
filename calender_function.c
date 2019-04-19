#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


struct day{
  int dd;
  int mm;
  int yy;
};
struct day date;
struct day d1;
struct day d2;

COORD xy={0,0};
void gotoxy(int x, int y){
  xy.X=x;
  xy.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}
void plus(int *month, int *year){
  ++*month;
  if(*month>12){
    ++*year;
    *month=*month-12;
  }
}
void minus(int *month, int *year){
    --*month;
    if(*month<1){
      --*year;
      *month=*month+12;
    }
}
int leapyear(int year){
  if(year % 400 ==0||(year % 100 !=0 && year % 4 ==0))
     return(1);
  return(0);
}
void printmonth(int month, int year){
  gotoxy(20,2);
  printf("-----------------------------------------------------\n" );
  gotoxy(20,3);
  printf("-----------------------------------------------------\n" );
  gotoxy(40,4);
  printf("%d ",year );

  switch (month) {
    case 1:printf("JANUARY\n");break;
    case 2:printf("FEBRAURY\n");break;
    case 3:printf("MARCH\n");break;
    case 4:printf("APRIL\n");break;
    case 5:printf("MAY\n");break;
    case 6:printf("JUNE\n");break;
    case 7:printf("JULY\n");break;
    case 8:printf("AUGUST\n");break;
    case 9:printf("SEPTEMBER\n");break;
    case 10:printf("OCTOBER\n");break;
    case 11:printf("NOVEMBER\n");break;
    case 12:printf("DECEMBER\n");break;

  }
  gotoxy(20,5);
  printf("-----------------------------------------------------\n" );
  gotoxy(20,6);
  printf("-----------------------------------------------------\n" );
  gotoxy(20,7);
}
int days(int month ,int year){
  switch (month) {
    case 1: return(31);
    case 2: if(leapyear(year)==1)
              return(29);
            else
              return(28);
    case 3: return(31);
    case 4: return(30);
    case 5: return(31);
    case 6: return(30);
    case 7: return(31);
    case 8: return(31);
    case 9: return(30);
    case 10: return(31);
    case 11: return(30);
    case 12: return(31);

  }
}
int countdays(struct day d1,struct day d2){
  int c1=365*(d2.yy-1)+d2.dd;
  for(int i=0;i<d2.mm-1;i++){
    c1+=days(d2.mm,d2.yy);
  }
  int c2=365*(d1.yy-1)+d1.dd;
  for(int i=0;i<d1.mm-1;i++){
    c2+=days(d1.mm,d1.yy);
  }
  return(c1-c2);
}
int getDayNumber(int day,int mon,int year){
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while(year >= 100){
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = (year-1)-t1;
    t1 = (t1*2)+t2;
    t1 = (t1%7);
    res = res + t1;
    res = res%7;
    t2 = 0;
    for(t1 = 1;t1 < mon; t1++){
        t2 += days(t1,y);
    }
    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;
    if(y > 2000)
        res = res + 1;
    res = res % 7;
    return res;
}
void printcalender(int month, int year, int x, int y){
  int d=1, count,x1=x;
  if(month<1 || month >12 ){
    printf("INVALID MONTH!\n");
//    break;
  }
  if(year<1600){
    printf("INVALID YEAR!\n" );
//    break;
  }
  gotoxy(20,y);
  printmonth(month,year);
  y+=4;
  gotoxy(x,y);
  printf("S\t    M\t    T\t    W\t    T\t    F\t    S\n");
  int n=days(month,year);
  int day=getDayNumber(d,month,year);
  y++;
  switch (day) {
    case 0:{
      x=x;
      count=1;
      break;
    }
    case 1:{
      x+=8;
      count=2;
      break;
    }
    case 2:{
      x+=16;
      count=3;
      break;
    }
    case 3:{
      x+=24;
      count=4;
      break;
    }
    case 4:{
      x+=32;
      count=5;
      break;
    }
    case 5:{
      x+=40;
      count=6;
      break;
    }
    case 6:{
      x+=48;
      count=7;
      break;
    }
  }
  gotoxy(x,y);
  printf("%d",d);
  for(d=2;d<=n;d++){
    if(count%7==0){
//      printf("\n" );
      y++;
      count=0;
      x=x1-8;
    }
    x=x+8;
    gotoxy(x,y);
    count++;
    printf("%d\t",d );
  }
  gotoxy(8, y+2);
  printf("\nPress 'UP'  to Next, Press 'DOWN' to Previous and '0' to Quit");
}
struct day calendermain(){
  char c;
  printf("Enter month and year(MM YYYY):\n");
  scanf("%d %d",&date.mm ,&date.yy);
  system("cls");

  while(c!=0){
    printcalender(date.mm,date.yy,20,5);
    c=getch();
    if(GetAsyncKeyState(VK_UP)){
      plus(&date.mm,&date.yy);
      system("cls");
      printcalender(date.mm,date.yy,20,5);
      }
    if(GetAsyncKeyState(VK_DOWN)){
      minus(&date.mm,&date.yy);
      system("cls");
      printcalender(date.mm,date.yy,20,5);
      }
    }
    system("cls");
    printf("Enter a date(DD MM YYYY)\n");
    scanf("%d %d %d",&d1.dd, &d1.mm, &d1.yy);
  return(d1);
}

void main(){
  struct day start= calendermain();
}
