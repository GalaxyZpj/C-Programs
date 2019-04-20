#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int ID_init = 16142300, hcount = 0, fcount = 0;

//Linked Lists for the Program
typedef struct user {
  char username[25];
  char password[16];
  struct details {
    char fName[25];
    char lName[25];
    struct birthdate {
      int day;
      int month;
      int year;
    }eb;
    char contact[25];
    char city[25];
    char state[25];
  }ed;
  struct user *next;
}USER;
USER *newNode, *head = 0, *temp = 0, *temp1 = 0;

typedef struct ufile {
  char key;
  int id;
  char name[50];
  int cin_day, cin_month, cin_year;
  int cout_day, cout_month, cout_year;
  int amount;
  struct ufile *next;
}UFILE;
UFILE *newNodef, *headf = 0, *tempf = 0, *temp1f = 0;

//Hotel's
typedef struct hotel {
  char name[50], location[50]; int avgFare, no;
  struct ROOM {
    char type[10];
    int rfare;
  }e[6];
  struct hotel *next;
}HOTEL;
HOTEL *newNodeH, *headH = 0, *tempH = 0, *tempH1 = 0;

typedef struct hbook {
  char key;
  int id;
  char name[50];
  int cin_day, cin_month, cin_year;
  int cout_day, cout_month, cout_year;
  int amount;
  struct hbook *next;
}HK;
HK *newNodeHK, *headHK = 0, *tempHK = 0, *temp1HK = 0;


//Flight's
struct node {
  char name[30];
  char clas[20];
  int adults;
  int children;
  int infants;
  int trip_type;
  int routing;
  char mobileno[11];
  struct node*next;

}*headi=NULL;

struct filenode{
  char src[15],desti[15];
  int flightno;
  int fare ;
  struct filenode*next;
}*headd=NULL;

typedef struct fbook {
  char key;
  int id;
  char name[50];
  int cin_day, cin_month, cin_year;
  int cout_day, cout_month, cout_year;
  int amount;
  struct fbook *next;
}FK;
FK *newNodeFK, *headFK = 0, *tempFK = 0, *temp1FK = 0;


//FunctionPrototypes
void clrscr();
void currentTime();
void paymentPortal(int);
void arrorHere(int, int);
void fileEntry();
void sortList(HOTEL *headS);

//void gotoxy(int , int);
//void plus(int, int);
//void minus(int, int);
//int leapyear(int);
//void printmonth(int, int);
//int days(int, int);
//int countdays(struct day, struct day);
//int getDayNumber(int, int, int);
//void printcalender(int, int, int, int);
//struct day calendermain();

void flightRecords(int amount, int tid);
void confirmation();
void reserve();
void cancel();
void display();

void hotelRecords(int amount, int tid);
void hotelFinalizing(HOTEL *op);
void hotelPrinting(char country[]);

void flightBooking();
void hotelBooking();
void emergencyEnquiry();
void feedback();
void aboutUs();

void menu();

void fileToList();
void createUser();
void loginCheck(char uname[], char upass[]);
void login();
void userPortal();



//MiscelleneousFunctions
int position = 1; int keyPressed = 0;
void clrscr() {
  system("@cls||clear");
}
void currentTime() {
  time_t rawtime;
    struct tm*  time_;

    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i | %i-%i-%i\n", time_->tm_hour, time_->tm_min,
            time_->tm_sec, time_->tm_mday, time_->tm_mon+1,
            time_->tm_year+1900);

}
void paymentPortal(int amount) {
  int traveliz_id, traveliz_cvv, month, year, tid; char c;
  clrscr();
  printf("AMOUNT: %d\n\n", amount);
  printf("Enter the TRAVLIZ Card id: ");
  scanf("%d", &traveliz_id);
  printf("Enter CVV: ");
  scanf("%d", &traveliz_cvv);
  printf("Enter month: ");
  scanf("%d", &month);
  printf("Enter year: ");
  scanf("%d", &year);
  printf(":::CONFIRM PAYMENT:::\nPress 1 to confirm else 0 to reenter card details:-\n");
  c = getch();
  if(c == '1') {
    tid = (1*69) + ID_init;
    printf("Your transaction id is: %d\n\nPress any key to display booking details\n", tid);
    getch();
    hotelRecords(amount, tid);
  }
  else {
    paymentPortal(amount);
  }


}
void arrorHere(int realPosition, int arrowPosition) {
  if(realPosition == arrowPosition) {
    printf(">>>>  ");
  }
  else {
    printf("      ");
  }
}
void fileEntry() {
  tempf = headf;
  char tname[100];
  char path[] = "C:\\Users\\Pranav Jain\\Documents\\Travalista\\USERS\\";
  strcpy(tname, path);
  strcat(tname, temp->username);
  strcat(tname, ".txt");
  FILE *fp = fopen(tname, "w");
  while(tempf != NULL) {
    fprintf(fp, "%c %d %s %d-%d-%d %d-%d-%d %d\n", tempf->key, tempf->id, tempf->name, tempf->cin_day, tempf->cin_month, tempf->cin_year, tempf->cout_day, tempf->cout_month, tempf->cout_year, tempf->amount);
    tempf = tempf->next;
  }
  printf("Entry Successful!!!\n\nPress any key to return to main menu.");
  getch();
  menu(temp->username);
  fclose(fp);
}
void sortList(HOTEL *headS) {
    HOTEL *tempS, *tempS1, *etemp;
    for(tempS = headS; tempS != NULL; tempS = tempS->next) {
      for(tempS1 = tempS->next; (tempS1 != NULL) && (tempS != NULL); tempS1 = tempS1->next) {
        if(tempS->avgFare < tempS1->avgFare) {
          etemp = tempS->next;
          tempS->next = tempS1->next;
          tempS1->next = etemp;
        }
      }
   }
}


//CalenderFunctions
struct day{
  int dd;
  int mm;
  int yy;
};
struct day date;
struct day d;
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
struct day calendermain(){
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
    scanf("%d %d %d",&d.dd, &d.mm, &d.yy);
  return(d);
}

//FlightBooking SubFunctions
void flightRecords(int amount, int tid) {
  newNodeFK = (FK *)malloc(sizeof(FK));
  newNodef = (UFILE *)malloc(sizeof(UFILE));
  newNodeFK->key = newNodef->key = 'f';
  newNodeFK->id  = newNodef->id = tid;
  //newNodeFK->name = newNodef->name = tempH1->name;
  newNodeFK->cin_day  = newNodef->cin_day = d1.dd;
  newNodeFK->cin_month  = newNodef->cin_month = d1.mm;
  newNodeFK->cin_year  = newNodef->cin_year  = d1.yy;
  newNodeFK->cout_day  = newNodef->cout_day  = d2.dd;
  newNodeFK->cout_month  = newNodef->cout_month = d2.mm;
  newNodeFK->cout_year  = newNodef->cout_year  = d2.yy;
  newNodeFK->amount  = newNodef->amount  = amount;

  if(headFK != 0) {
    tempFK->next = newNodeFK;
    tempFK = newNodeFK;
  }
  else {
    headFK = tempFK = newNodeFK;
  }
  tempFK->next = NULL;

  if(headf != 0) {
    tempf->next = newNodef;
    tempf = newNodef;
  }
  else {
    headf = tempf = newNodef;
  }
  tempf->next = NULL;
  clrscr();
  //printf("\n:::BOOKING DETAILS:::\n");
  fileEntry();

}
void confirmation() { int flno;
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
void reserve() {
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

  if(headi==NULL)
  {
    headi=ptr;
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
temp=headi;
while (temp!=NULL){
fprintf(fp,"NAME:%s\nMOBILE_NO%s\nCLASS%s\nNUMBER OF ADULTS:%d\nNUMBER OF CHILDREN%d\nNUMBER OF INFANTS%d\nTRIP_TYPE:%d\nROUTING:%d\n",temp->name,temp->mobileno,temp->clas,temp->adults,temp->children,temp->infants,temp->trip_type,temp->routing);
temp=temp->next;}
fclose(fp);

}
void cancel() {  char str[20];
   char mobile[11];
  struct node*temp,*temp1;
  //temp=(struct node*)malloc(sizeof(struct node));
  temp=headi;
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
void display() {
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


//HotelBooking SubFunctions
void hotelRecords(int amount, int tid) {
  newNodeHK = (HK *)malloc(sizeof(HK));
  newNodef = (UFILE *)malloc(sizeof(UFILE));
  newNodeHK->key = newNodef->key = 'h';
  newNodeHK->id  = newNodef->id = tid;
  //newNodeHK->name = newNodef->name = tempH1->name;
  newNodeHK->cin_day  = newNodef->cin_day = d1.dd;
  newNodeHK->cin_month  = newNodef->cin_month = d1.mm;
  newNodeHK->cin_year  = newNodef->cin_year  = d1.yy;
  newNodeHK->cout_day  = newNodef->cout_day  = d2.dd;
  newNodeHK->cout_month  = newNodef->cout_month = d2.mm;
  newNodeHK->cout_year  = newNodef->cout_year  = d2.yy;
  newNodeHK->amount  = newNodef->amount  = amount;

  if(headHK != 0) {
    tempHK->next = newNodeHK;
    tempHK = newNodeHK;
  }
  else {
    headHK = tempHK = newNodeHK;
  }
  tempHK->next = NULL;

  if(headf != 0) {
    tempf->next = newNodef;
    tempf = newNodef;
  }
  else {
    headf = tempf = newNodef;
  }
  tempf->next = NULL;
  clrscr();
  //printf("\n:::BOOKING DETAILS:::\n");
  fileEntry();

}
void hotelFinalizing(HOTEL *op) {
  clrscr();
  int choice; int fday, fmonth, fyear, tday, tmonth, tyear, days, nights, price, tprice;
  keyPressed = 0; position = 1;
  while(keyPressed != 13) {
    clrscr();
    printf("Hotel: %s\n\nChoose room type:-\n", op->name);
    printf("--------------------------------------------------------------------------------\n");
    printf("SerialNo.\t\tTYPE\t\t\t\t\tFARE\n");
    arrorHere(1, position); printf("%d. %20s\t\t\t\t\t%d\n", 1, op->e[0].type, op->e[0].rfare);
    printf("--------------------------------------------------------------------------------\n");
    arrorHere(2, position); printf("%d. %20s\t\t\t\t\t%d\n", 2, op->e[1].type, op->e[1].rfare);
    printf("--------------------------------------------------------------------------------\n");
    arrorHere(3, position); printf("%d. %20s\t\t\t\t\t%d\n", 3, op->e[2].type, op->e[2].rfare);
    printf("--------------------------------------------------------------------------------\n");
    arrorHere(4, position); printf("%d. %20s\t\t\t\t\t%d\n", 4, op->e[3].type, op->e[3].rfare);
    printf("--------------------------------------------------------------------------------\n");
    arrorHere(5, position); printf("%d. %20s\t\t\t\t\t%d\n", 5, op->e[4].type, op->e[4].rfare);
    printf("--------------------------------------------------------------------------------\n");
    arrorHere(6, position); printf("%d. %20s\t\t\t\t\t%d\n", 6, op->e[5].type, op->e[5].rfare);
    printf("--------------------------------------------------------------------------------\n");
    keyPressed = getch();
    if(keyPressed == 80 && position != 6) {
      position++;
    }else if(keyPressed == 72 && position != 1) {
      position--;
    }else {
      position = position;
    }
  }
  switch(position) {
    case 1: price = op->e[0].rfare; break;

    case 2: price = op->e[1].rfare; break;

    case 3: price = op->e[2].rfare; break;

    case 4: price = op->e[3].rfare; break;

    case 5: price = op->e[4].rfare; break;

    case 6: price = op->e[5].rfare; break;

    default: printf("Invalid choice, press any key to try again."); getch(); hotelFinalizing(op);
  }
  printf("Choose checkin date: \n");
  d1 = calendermain();

  printf("Choose checkout date: \n");
  d2 = calendermain();

  nights = countdays(d1, d2);
  days = nights + 1;
  tprice = op->avgFare + (price * days);
  keyPressed = 0; position = 1;
  while(keyPressed != 13) {
    clrscr();
    printf("\n\n\n--Summary--\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\t\t\t\tCHECKIN\t\t\t\tCHECKOUT\t\t\t\t\tFARE\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%s\t\t\t%10d-%d-%d\t\t\t\t%d-%d-%d\t\t\t\t\t%d\n", op->name, d1.dd, d1.mm, d1.yy, d2.dd, d2.mm, d2.yy, tprice);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nProceed for the payment:-\n");
    arrorHere(1, position); printf("  YES\n");
    arrorHere(2, position); printf("  NO\n");
    keyPressed = getch();
    if(keyPressed == 80 && position != 2) {
      position++;
    }else if(keyPressed == 72 && position != 1) {
      position--;
    }else {
      position = position;
    }
  }
  switch(position) {
    case 1: paymentPortal(tprice); break;
    case 2: hotelFinalizing(op); break;
  }

}
void hotelPrinting(char country[]) {
  clrscr();
  char path[100] = "C:\\Users\\Pranav Jain\\Documents\\Travalista\\COUNTRY\\"; int choice;
  strcat(path, country);
  strcat(path, ".txt");
  FILE *fp = fopen(path, "r+");
  for(int i=0; i<5; i++) {
    newNodeH = (HOTEL *)malloc(sizeof(HOTEL));
    fscanf(fp, "%s %s %d\n", newNodeH->name, newNodeH->location, &newNodeH->avgFare);
    for(int i=0; i<6; i++) {
      fscanf(fp, "%s %d\n", newNodeH->e[i].type, &newNodeH->e[i].rfare);
    }

    if(headH != 0) {
      tempH->next = newNodeH;
      tempH = newNodeH;
    }
    else {
      headH = tempH = newNodeH;
    }
  }
  temp->next = NULL;
  sortList(headH);
  keyPressed = 0; position = 1;
  while(keyPressed != 13) {
    clrscr();
    printf("Choose a Hotel:-\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("SerialNo.\t\t\t\t\tNAME\t\t\t\t  LOCATION  \t\t\t\t\t\t\t\tAVG FARE\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    tempH = headH;
    arrorHere(1, position); printf("%d. %45s %35s %70d\n", 1, tempH->name, tempH->location, tempH->avgFare);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    tempH = tempH->next;
    arrorHere(2, position); printf("%d. %45s %35s %70d\n", 2, tempH->name, tempH->location, tempH->avgFare);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    tempH = tempH->next;
    arrorHere(3, position); printf("%d. %45s %35s %70d\n", 3, tempH->name, tempH->location, tempH->avgFare);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    tempH = tempH->next;
    arrorHere(4, position); printf("%d. %45s %35s %70d\n", 4, tempH->name, tempH->location, tempH->avgFare);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    tempH = tempH->next;
    arrorHere(5, position); printf("%d. %45s %35s %70d\n", 5, tempH->name, tempH->location, tempH->avgFare);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    tempH = tempH->next;
    fclose(fp);
    keyPressed = getch();
    if(keyPressed == 80 && position != 5) {
      position++;
    }else if(keyPressed == 72 && position != 1) {
      position--;
    }else {
      position = position;
    }
  }
  switch(position) {
    case 1:
    tempH1 = headH;
    hotelFinalizing(tempH1);
    break;

    case 2:
    tempH1 = headH->next;
    hotelFinalizing(tempH1);
    break;

    case 3:
    tempH1 = headH->next->next;
    hotelFinalizing(tempH1);
    break;

    case 4:
    tempH1 = headH->next->next->next;
    hotelFinalizing(tempH1);
    break;

    case 5:
    tempH1 = headH->next->next->next->next;
    hotelFinalizing(tempH1);
    break;

    default:
    printf("Invalid choice, press any key to try again.");
    getchar();
    hotelPrinting(country);
  }
  getch();
}

//TravalistaCoreFunctions
void flightBooking() {
  clrscr();
  int choice;
    printf("****************WELCOME TO TRAVELISTA FLIGHT BOOKING MODE********************\n");
    printf("While booking flights with TRAVELISTA, you can expect the ultimate online booking experience.\n With premium customer service, 24/7 dedicated helpline for support, TRAVELISTA takes great pride in enabling customer satisfaction.\n With a cheapest flight guarantee, book your tickets at the lowest airfares.\n Avail great offers, exclusive deals for loyal customers and get instant updates for your flight status and fare drops.");

  printf("\n\n\n\t\t**************MENU********************\n");
  printf("choose a number to perform any of these functions");
  do {

      printf("\n\t  1.BOOK TICKET ");
      printf("\n\t  2.CHECK FOR ALL FLIGHTS AVAILABLE AS PER CHOICE DOMAIN");
      printf("\n\t  3.CANCEL BOOKING ");
      printf("\n\t  4.RETURN TO MAIN MENU ");
      scanf("%d", &choice);


      switch (choice) {

      case 1: reserve();
          break;
      case 3: cancel();
          break;
      case 2: display();
          break;
      case 4: menu(temp->username);
          break;
      default:
          printf("\nInvalid Choice");
      }

   } while (choice != 4);
  }
void hotelBooking() {
  keyPressed = 0; position = 1;
  clrscr();
  while(keyPressed != 13) {
    clrscr();
    printf("Choose among the following countries:-\n");
    arrorHere(1, position); printf("1.\tDubai\n");
    arrorHere(2, position); printf("2.\tEurope\n");
    arrorHere(3, position); printf("3.\tFrance\n");
    arrorHere(4, position); printf("4.\tHong Kong\n");
    arrorHere(5, position); printf("5.\tRussia\n");
    arrorHere(6, position); printf("6.\tSingapure\n");
    arrorHere(7, position); printf("7.\tSouth Korea\n");
    arrorHere(8, position); printf("8.\tSpain\n");
    arrorHere(9, position); printf("9.\tToronto\n");
    arrorHere(10, position); printf("10.\tUK\n");
    keyPressed = getch();
    if(keyPressed == 80 && position != 10) {
      position++;
    }else if(keyPressed == 72 && position != 1) {
      position--;
    }else {
      position = position;
    }

  }

  switch(position) {
    case 1: hotelPrinting("Dubai"); break;

    case 2: hotelPrinting("Europe"); break;

    case 3: hotelPrinting("France"); break;

    case 4: hotelPrinting("HongKong"); break;

    case 5: hotelPrinting("Russia"); break;

    case 6: hotelPrinting("Singapure"); break;

    case 7: hotelPrinting("SouthKorea"); break;

    case 8: hotelPrinting("Spain"); break;

    case 9: hotelPrinting("Toronto"); break;

    case 10: hotelPrinting("UK"); break;

    default: printf("Invalid Choice, Press any key to try again.\n"); hotelBooking();
  }
  getch();
}
void emergencyEnquiry() {

}
void feedback() {

}
void aboutUs() {

}


//MainMenuFunction
void menu(char mname[]) {
  position = 1; keyPressed = 0;
  clrscr();
  while(keyPressed != 13) {
    clrscr();
    printf("\n---------------------------------------- TRAVALISTA ----------------------------------------\n");
    printf("Welcome @%s\t\t\t\t\t\t\t\tLogin Date and Time\n\t\t\t\t\t\t\t\t\t", mname);
    currentTime();
    printf("\nChoose among the following:-\n");
    arrorHere(1, position); printf("1. Flight Booking\n");
    arrorHere(2, position); printf("2. Hotel Booking\n");
    arrorHere(3, position); printf("3. Emergency Enquiry\n");
    arrorHere(4, position); printf("4. Feedback\n");
    arrorHere(5, position); printf("5. About us\n");
    keyPressed = getch();

    if(keyPressed == 80 && position != 5) {
      position++;
    }else if(keyPressed == 72 && position != 1) {
      position--;
    }else {
      position = position;
    }
  }
  switch(position) {
    case 1:flightBooking(); break;

    case 2: hotelBooking(); break;

    case 3: emergencyEnquiry(); break;

    case 4: feedback(); break;

    case 5: aboutUs(); break;

    default: printf("Invalid Choice, Press any key to try again.\n"); getchar(); menu(mname);
  }
  getch();

}


//LoginIntoDatabaseFunctions
void fileToList() {
  clrscr();
  printf("LOADING DATABASE......\n");
  FILE *fp = fopen("C:\\Users\\Pranav Jain\\Documents\\Travalista\\Database.txt", "r");
  while(!feof(fp)) {
    newNode = (USER *)malloc(sizeof(USER));
    fscanf(fp, "%s %s %s %s %d %d %d %s %s %s\n", newNode->username, newNode->password, newNode->ed.fName, newNode->ed.lName,
     &newNode->ed.eb.day, &newNode->ed.eb.month, &newNode->ed.eb.year, newNode->ed.contact, newNode->ed.state, newNode->ed.city);
     if(head != 0) {
       temp->next = newNode;
       temp = newNode;
     }
     else {
       head = temp = newNode;
     }
  }
  temp->next = NULL;

  fclose(fp);
}
void createUser() {
  newNode = (USER *)malloc(sizeof(USER));
  printf("Username: ");
  scanf("%s", newNode->username);
  printf("Password: ");
  scanf("%s", newNode->password);
  printf("\n-----Fill the form-----\n");
  printf("First Name: ");
  scanf("%s", newNode->ed.fName);
  printf("Last Name: ");
  scanf("%s", newNode->ed.lName);
  printf("Birth Date (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &newNode->ed.eb.day, &newNode->ed.eb.month, &newNode->ed.eb.year);
  printf("Contact number: ");
  scanf("%s", newNode->ed.contact);
  printf("State: ");
  scanf("%s", newNode->ed.state);
  printf("City: ");
  scanf("%s", newNode->ed.city);

  if(head != 0) {
    temp->next = newNode;
    temp = newNode;
  }
  else {
    head = temp = newNode;
  }
  temp->next = NULL;
  FILE *fp = fopen("C:\\Users\\Pranav Jain\\Documents\\Travalista\\Database.txt", "a");
  fprintf(fp,"%s %s %s %s %d %d %d %s %s %s\n", temp->username, temp->password, temp->ed.fName, temp->ed.lName,
   temp->ed.eb.day, temp->ed.eb.month, temp->ed.eb.year, temp->ed.contact, temp->ed.state, temp->ed.city);
  printf("\nUser registered successfully.\n");
  fclose(fp);

  //File for the user created
  char tname[100];
  char path[] = "C:\\Users\\Pranav Jain\\Documents\\Travalista\\USERS\\";
  strcpy(tname, path);
  strcat(tname, temp->username);
  strcat(tname, ".txt");

  fp = fopen(tname, "w+");

  fclose(fp);
}
void loginCheck(char uname[], char upass[]) {
  temp = head;
  while(temp != NULL) {
    if(strcmp(uname, temp->username) == 0) {
      if(strcmp(upass, temp->password) == 0) {
        menu(temp->username);
        temp = head;
        break;
      }
      else {
        printf("Invalid Password!\nPress any key to login again.\n\n");
        getch();
        clrscr();
        login();
        break;
      }
    }
    else if (strcmp(uname, temp->username) != 0) {
      temp = temp->next;
    }
  }
  if(temp == NULL) {
    printf("User not found, Consider registering first.\n");
    //printf("Enter Username and Password to register.\n");
    userPortal();
    //createUser();
  }
}
void login() {
  char tuname[25], tupass[25];
  printf("Username: ");
  scanf("%s", tuname);
  printf("Password: ");
  scanf("%s", tupass);
  loginCheck(tuname, tupass);
}
void userPortal() {
  #define MAX 2
  #define MIN 1
  while(keyPressed != 13) {
    clrscr();
    printf("**********TRAVALISTA**********\n");
    arrorHere(1, position); printf("1. Login\n");
    arrorHere(2, position); printf("2. Signup\n");
    keyPressed = getch();

    if(keyPressed == 80 && position != MAX) {
      position++;
    }else if(keyPressed == 72 && position != MIN) {
      position--;
    }else {
      position = position;
    }
  }

  switch(position) {
    case 1: login(); break;

    case 2: createUser(); break;

    default: printf("Invalid choice.\n"); clrscr(); userPortal();

  }
  getch();
}

int main() {
  fileToList();
//  temp = head;
/*  while(temp != NULL) {
    printf("%s %s %s %s %d %d %d %s %s %s\n", temp->username, temp->password, temp->ed.fName, temp->ed.lName,
     temp->ed.eb.day, temp->ed.eb.month, temp->ed.eb.year, temp->ed.contact, temp->ed.state, temp->ed.city);
     temp = temp->next;
  }*/
  userPortal();
  return 0;
}
