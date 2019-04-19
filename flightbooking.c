# include<stdio.h>
# include<conio.h>
#include<string.h>
#include<stdlib.h>


//Khushi's Functions
/*struct day{
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
  printf("\nPress 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
}
int calendermain(){
  char c;
  printf("Enter month and year(MM YYYY):\n");
  scanf("%d %d",&date.mm ,&date.yy);
  system("cls");

  while(c!='q'){
    printcalender(date.mm,date.yy,20,5);
    c=getch();
    if(c=='n'){
      plus(&date.mm,&date.yy);
      system("cls");
      printcalender(date.mm,date.yy,20,5);
      }
    if(c=='p'){
      minus(&date.mm,&date.yy);
      system("cls");
      printcalender(date.mm,date.yy,20,5);
      }
    }
    system("cls");
    printf("Enter a date(DD MM YYYY)\n");
    scanf("%d %d %d",&d1.dd, &d1.mm, &d1,yy);
  return(d1);
}*/

//**********************
struct node
{
  char name[30];
  char clas[20];
  int adults;
  int children;
  int infants;
  int trip_type;
  int routing;
  char mobileno[11];
  struct node*next;

}*head=NULL;
//***********************************

struct filenode
{
  char src[15],desti[15];
  int flightno;
  int fare ;
  struct filenode*next;
}*headd=NULL;

//**************************************
void reserve();
void cancel();
void display();
void confirmation();
int pay();


int main()
{
int choice;
  printf("****************WELCOME TO TRAVELISTA FLIGHT BOOKING MODE********************\n");
  printf("While booking flights with TRAVELISTA, you can expect the ultimate online booking experience.\n With premium customer service, 24/7 dedicated helpline for support, TRAVELISTA takes great pride in enabling customer satisfaction.\n With a cheapest flight guarantee, book your tickets at the lowest airfares.\n Avail great offers, exclusive deals for loyal customers and get instant updates for your flight status and fare drops.");

printf("\n\n\n\t\t**************MENU********************\n");
printf("choose a number to perform any of these functions");
do {

    printf("\n\t  1.BOOK TICKET ");
    printf("\n\t  2.CHECK FOR ALL FLIGHTS AVAILABLE AS PER CHOICE DOMAIN");
    printf("\n\t  3.CANCEL BOOKING ");
    printf("\n\t  4. EXIT SYSTEM");
    scanf("%d", &choice);


    switch (choice) {

    case 1: reserve();
        break;
    case 3: cancel();
        break;
    case 2: display();
        break;
    case 4: exit(0);
        break;
    default:
        printf("\nInvalid Choice");
    }

 } while (choice != 4);
 return 0;
}//end of main()
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BOOKING^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void reserve()
{
struct node*ptr,*current;
ptr=(struct node*)malloc(sizeof(struct node));

//taking details of the node
  printf("Dear Customer ,kindly enter your details please:- \n NAME:\n");
  scanf("%s",ptr->name);

  printf("Enter a valid mobile number\n");                           //check for validity
  scanf("%s",ptr->mobileno);

  printf("\t\tchoose the class :-\n1)bussiness\t2)economy\t3)premium economy\n please DO NOT  use CAPS while typing \n");
  scanf("%s",ptr->clas);                                          //make it int type
    system("cls");

 printf("\n\t\t\t**************************************************\n");
  printf("\t\t\tnow please enter the details of the traveller(s)\n" );                     //column wise representation
  printf("\t\t\t**************************************************\n\n");


  printf("Number of children (age group 2-12)\n");
  scanf("%d",&ptr->children);

  printf("Number of adults(age above 12)\n");
  scanf("%d",&ptr->adults);

  printf("Number of infants(age group below 2)\n\n\n");
  scanf("%d",&ptr->infants);

  printf("Your trip type? ONE WAY or TWO WAY ROUND TRIP \n\n Type 1 for one way trip \n\n 2 for a two way trip\n\n\n");
  scanf("%d",&ptr->trip_type);

  printf("Tell us about your comfortable routing style\n \nPress 1 for DIRECT FLIGHTS \n\npress 2 for CONNECTING(VIA) FLIGHTS");
  scanf("%d",&ptr->routing);

  ptr->next=NULL;

  if(head==NULL)
  {
    head=ptr;
    current=ptr;
  }

  else{
    current->next=ptr;
    current=ptr;
  }

  //printing individual ticket details for each new noode -> each time new record in ticket.txt
  FILE*f;
  f=fopen("C:\\Users\\Pranav Jain\\Documents\\Travalista\\FLIGHT FILES\\ticket.txt","w");
  fprintf(f,"NAME:%s\nMOBILE_NO%s\nCLASS%s\nNUMBER OF ADULTS:%d\nNUMBER OF CHILDREN%d\nNUMBER OF INFANTS%d\nTRIP_TYPE:%d\nROUTING:%d\n",ptr->name,ptr->mobileno,ptr->clas,ptr->adults,ptr->children,ptr->infants,ptr->trip_type,ptr->routing);
  fclose(f);
//printing all details of everyone to a record book ALL_RECORDS ->appending data
FILE*fp;
fp=fopen("C:\\Users\\Pranav Jain\\Documents\\Travalista\\FLIGHT FILES\\allrecords.txt","a");
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp=head;
while (temp!=NULL){
fprintf(fp,"NAME:%s\nMOBILE_NO%s\nCLASS%s\nNUMBER OF ADULTS:%d\nNUMBER OF CHILDREN%d\nNUMBER OF INFANTS%d\nTRIP_TYPE:%d\nROUTING:%d\n",temp->name,temp->mobileno,temp->clas,temp->adults,temp->children,temp->infants,temp->trip_type,temp->routing);
temp=temp->next;}
fclose(fp);

}//end of reserve()


void display()
{
int sum;
struct filenode *s=0,*temp=0;
char source [10],destination[15];
system("cls");
  printf("For checking the details of available flights,\n please enter nearest INTERNATIONAL AIRPORT\n\t ->INDIRA GANDHI INTERNATIONAL AIRPORT \n\t->CHHATRAPATI SHIVAJI INTERNATIONAL AIRPORT\n\t->CHENNAI INTERNATIONAL AIRPORT\n ");
  printf("enter source name as DELHI \t / MUMBAI \t /CHENNAI ");
  scanf("%s",source );
  printf("*******************************************");
  system ("cls");
  printf("\n\n\n Now enter the destination  \n");
  printf("choose from the below given list ");
  printf("\n\nRUSSIA\nUK\nSPAIN\nFRANCE\nTORONTO\nSINGAPORE\nSOUTHKOREA\nEUROPE\nHONGKONG\nDUBAI \n");
  scanf("%s",destination);
  printf("*********************************************");
  system("cls");
  FILE *f;
  f=fopen("C:\\Users\\Pranav Jain\\Documents\\Travalista\\FLIGHT FILES\\Flights.txt","r");

  //copying the content of file to structure nodes
  while(!feof(f))
  {
  s=(struct filenode*)malloc(sizeof(struct filenode));
  fscanf(f,"%s %s %d %d\n",s->src,s->desti,&s->flightno,&s->fare);
  if(headd!=0)
  {
    temp->next=s;
    temp=s;
  }
  else{
    headd=temp=s;
  }
}
temp->next=NULL;
fclose(f);
//now extracting the values from these nodes to get desired output
temp=headd;
while(temp!=0)
{
  if(strcmpi(temp->src,source)==0&&strcmpi(temp->desti,destination)==0)
  { printf("SOURCE\t\t\tDESTINATION\t\tFLIGHT_NO\t\tFARE\n");
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%d\t\n",temp->src,temp->desti,temp->flightno,temp->fare);

  }
  temp=temp->next;
}
// nested function ->calling confirmation() inside display function
confirmation();

}

//definition of nested function confirmation()

void confirmation()
{ int flno;
  int payout;
  printf("Choose the desired flight from the list \n");
  printf("enter the flight no");
  scanf("%d",&flno);
  system("cls");
  printf("*************************************\n");
  printf("*     BOOKING SUCCESSFULLY DONE!!   *\n");
  printf("*************************************\n");
   int pay()
  {
 struct filenode*ptrr;
 ptrr=headd;
  while(ptrr!=0)
  {
    if(ptrr->flightno==flno)
    {
      payout=ptrr->fare;
    }
    ptrr=ptrr->next;
  }
  printf("Your NET payable amount is:-");
  return payout;
  //return payout;

}}

void cancel()
{  char str[20];
   char mobile[11];
  struct node*temp,*temp1;
  //temp=(struct node*)malloc(sizeof(struct node));
  temp=head;
  printf("Please enter your name ");
  scanf("%s",str);

  printf("enter your mobile number which was registered during booking of ticket");
  scanf("%s",mobile);

  while(temp!=NULL&&strcmpi(temp->name,str)!=0&&strcmp(temp->mobileno,mobile)!=0)
  {
    temp1=temp;
    temp=temp->next;
  }
  if(strcmpi(temp->name,str)==0&&strcmp(temp->mobileno,mobile)==0)
  {
    temp1->next=temp->next;
    free(temp);

  }
  printf("\t\t\nYour BOOKING has been cancelled\n\n");

  }
