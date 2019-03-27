#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


void newreg();
void details();
void rnc_hwh(int &aaa);
void rnc_del(int &aaa);
void hwh_del(int &aaa);

int main()
{
void reg();
reg();
return 0;
}

void reg(){
clrscr();
char choice;
cout<<"********************************************************************************"<<endl<<"Welcome to the D.P.S Ranchi's Train Reservation System \nCreated by Bob (programmer) and Rupam (debugger)"<<endl<<"********************************************************************************"<<endl;
cout<<"Are you a New or a Registered User? (Reply with 'N' as in \"New\" or 'R' as in \"Registered\"):";
cin>>choice;
   if(choice=='N'||choice=='n')
    {
    newreg();}
    else if(choice=='R'||choice=='r')
    {
    details();}
    else if(choice!='R'||choice!='r'||choice!='N'||choice!='n')
    cerr<<"\nError, input cannot be registered! Please try again!";reg();}

struct data{
    char usrnm[50];
    char psswrd[20];
    char email[50];
    long number;
    char answer[50];
}dat;

struct dpstrs{
int num;
char name[50];
char from[10];
char to[10];
double arrival;
double departure;
}l;

void newreg(){
clrscr();
ofstream user;
user.open("User.dat",ios::ate|ios::binary);

cout<<"Thank you for considering our train reservation system. Our aim is to provide the best service we can. \nPlease fill in the details below for your account to be created\n\n";
cout<<"Please select a username: ";
gets(dat.usrnm);

cout<<endl<<"Please type-in your password: ";
gets(dat.psswrd);
cout<<endl<<"Please enter your email address: ";
gets(dat.email);

cout<<endl<<"Please enter you personal mobile number: ";
cin>>dat.number;
cout<<endl<<"What is the name of your favourite train? (Secret Question): ";
gets(dat.answer);
user.write((char*)&dat,sizeof(dat));
user.close();
reg();
}

void details(){
clrscr();
char usrnm[50],psswrd[20];
cout<<"Please fill in your login credentials...\n\n";
cout<<"Username: ";
gets(usrnm);
cout<<"\nIn case if you have forgotten your password, please type \"password\" in the section below.\n";
cout<<"\nPassword: ";
gets(psswrd);

char ans[50]; int flag=0;

fstream user;
user.open("User.dat",ios_base::in);
while(!user.eof())
    {
        user.read((char*)&dat,sizeof(dat));
        if(strcmp(dat.usrnm,usrnm)==0)
            {flag=flag+1;
         if(strcmp(psswrd,"password")==0||strcmp(psswrd,"Password")==0||strcmp(psswrd,"PASSWORD")==0)
            {
                clrscr();

                cout<<"You have opted for a non-password login\n";
                cout<<"What is your favourite train? ";
                gets(ans);
                if(strcmp(dat.answer,ans)==0)
                {   flag=flag+1;
                    break;
                }
                else
                    {cerr<<"Your Response does not match! Logging out! Press Enter to Continue!";getch(); reg();}}

                    else if(strcmp(dat.psswrd,psswrd)==0){
                        flag=flag+1; break; }
                        else {flag=1; break;}
                        if(user.eof()==0)
                            break;

                    }}


if(flag==0)
{
    cout<<"\nYour Credentials Do Not Match! Press Enter to Continue!";getch(); details();

}
else if(flag==1){
    cout<<"\nEither Your Username or Password is Incorrect! Press Enter To Continue!";getch(); details();
}
else if(flag==2){
    void counter(); counter();
}

}

void counter(){
    clrscr();
cout<<"\nWelcome To Our Counter Screen. \nSelect the appropriate choice: \n1.Book One Way Ticket \n2.Book Return Journey Ticket \n3.Help \n4.Logout \nChoice: ";
int ch; cin>>ch;
switch(ch){
case 1:
    {void book1w();
    book1w();}
    break;
case 2:
    {void book2w();
    book2w();}
    break;
case 3:
    {ifstream lst;
    lst.open("List.dat",ios_base::in);
    while(!lst.eof()){

        for(int i=0; i<12; i++){
        lst.read((char*)&l,sizeof(l));
        cout<<"\nTrain Number: "<<l.num<<"\t"<<"Name: "<<l.name<<"\t"<<"From: "<<l.from<<"\t"<<"To: "<<l.to<<"\t"<<"Arrival At: "<<l.arrival<<"\t"<<"Departure On: "<<l.departure<<endl;}break;}
    lst.close();
    cout<<"\nPress Enter to Go Back to the Main Menu Screen!";
    getch();
    counter();}
    break;
case 4:
    reg();
    break;
}}

void book1w(){
    char from[10], to[10], c;
    int p, cost,aaa, date;
clrscr();
cout<<"At the Moment We Have Our Booking Available For Three Stations ONLY. \nType \"RNC\" for Ranchi, \"HWH\" for Howrah, and \"NDLS\" for New Delhi";
cout<<"\nType 'Y' to Continue or 'N' to go back: "; cin>>c;
if(c=='Y'||c=='y'){
cout<<"\nFrom: "; gets(from);
cout<<"\nTo: "; gets(to);
cout<<"\nNumber of People: "; cin>>p;
cout<<"\nDate of Journey (ddmmyyyy): "; cin>>date;


if(strcmp(from,"RNC")==0||strcmp(from,"rnc")==0){
    if(strcmp(to,"HWH")==0||strcmp(to,"hwh")==0){
         rnc_hwh(aaa);}
        else if(strcmp(to,"NDLS")==0||strcmp(to,"ndls")==0){
           rnc_del(aaa);}
       else
        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!";
        getch();
        book1w();}
    }
else if(strcmp(from,"HWH")==0||strcmp(from,"hwh")==0){
    if(strcmp(to,"RNC")==0||strcmp(to,"rnc")==0){
        rnc_hwh(aaa);}
    else if(strcmp(to,"NDLS")==0||strcmp(to,"ndls")==0){
        hwh_del(aaa); }  else{
        cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book1w();}
}

else if(strcmp(from,"NDLS")==0||strcmp(from,"ndls")==0){
    if(strcmp(to,"RNC")==0||strcmp(to,"rnc")==0)
    {
        rnc_del(aaa);
    }
    else if(strcmp(to,"HWH")==0||strcmp(to,"hwh")==0){
        hwh_del(aaa);
    }
    else

        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book1w();}
}
 else
        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book1w();}

clrscr();
{if(aaa==1)
    cost=750*p;
    else if(aaa==2)
    cost=250*p;
    else
        {cout<<"Error! Please Fill the Data Again! Press Enter to Continue!"; getch(); book1w();}}

cout<<"Thank You for Using Our Service! You have successfully booked your ticket for your journey from "<<from<<" to "<<to<<" on "<<date<<" for "<<p<<" people, costing you Rs"<<cost<<".";
cout<<"\nPress Enter to Logout!";
getch(); reg();}
else if(c=='N'||c=='n'){
    counter();}
else
    {cout<<"Invalid Data!"; book1w();}


}



void book2w(){
    char from[10], to[10], c;
    int p, cost, aaa, date1, date2;
clrscr();
cout<<"At the Moment We Have Our Booking Available For Three Stations ONLY. \nType \"RNC\" for Ranchi, \"HWH\" for Howrah, and \"NDLS\" for New Delhi";
cout<<"\nType 'Y' to Continue or 'N' to go back: "; cin>>c;
if(c=='Y'||c=='y'){
cout<<"\nFrom: "; gets(from);
cout<<"\nTo: "; gets(to);
cout<<"\nNumber of People: "; cin>>p;
cout<<"\nDate of Journey (ddmmyyyy): "; cin>>date1;
cout<<"\nDate of Returning (ddmmyyyy): "; cin>>date2;

    if(strcmp(from,"RNC")==0||strcmp(from,"rnc")==0){
    if(strcmp(to,"HWH")==0||strcmp(to,"hwh")==0){
         rnc_hwh(aaa);}
        else if(strcmp(to,"NDLS")==0||strcmp(to,"ndls")==0){
           rnc_del(aaa);}
       else
        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!";
        getch();
        book2w();}
    }
else if(strcmp(from,"HWH")==0||strcmp(from,"hwh")==0){
    if(strcmp(to,"RNC")==0||strcmp(to,"rnc")==0){
        rnc_hwh(aaa);}
    else if(strcmp(to,"NDLS")==0||strcmp(to,"ndls")==0){
        hwh_del(aaa); }  else{
        cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book2w();}
}

else if(strcmp(from,"NDLS")==0||strcmp(from,"ndls")==0){
    if(strcmp(to,"RNC")==0||strcmp(to,"rnc")==0)
    {
        rnc_del(aaa);
    }
    else if(strcmp(to,"HWH")==0||strcmp(to,"hwh")==0){
        hwh_del(aaa);
    }
    else

        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book2w();}
}
 else
        {cerr<<"\nError! Please Fill the Data Again! Press Enter to Continue!"; getch(); book2w();}

clrscr();
{if(aaa==1)
    cost=2*750*p;
    else if(aaa==2)
    cost=2*250*p;
    else
        {cout<<"Error! Please Fill the Data Again! Press Enter to Continue!"; getch(); book2w();}}


cout<<"Thank You for Using Our Service! You have successfully booked your ticket for your journey from "<<from<<" to "<<to<<" on "<<date1<<" for "<<p<<" people, costing you Rs"<<cost<<" with a return ticket on "<<date2<<".";
cout<<"\nPress Enter to Logout!";
getch();
reg();}
else if(c=='N'||c=='n'){
    counter();}
else
    {cout<<"Invalid Data!"; book2w();}
}


void rnc_hwh(int &aaa){
    int aa;
        cout<<"\nSelect 1 For Howrah Hatia Express or 2 For Shatabdi Express: ";
        cin>>aa;
        switch(aa){
case 1:
    {
        cout<<"\nSelect 1 for A.C. Class or 2 for General Class: ";
        cin>>aaa;}
        break;
case 2:
    {
        cout<<"\nSelect 1 for A.C. Chair Car or 2 for General Chair Car: ";
        cin>>aaa;}
        break;
    }


       }
void rnc_del(int &aaa){
    int aa;
    cout<<"\nSelect 1 For Rajdhani Express or 2 For Garib Rath: ";
            cin>>aa;
            switch(aa){
case 1:
    {
        cout<<"\nSelect 1 for A.C. Class or 2 for General Class: ";
        cin>>aaa;}
        break;
case 2:
    {
        cout<<"\nSelect 1 for A.C. Class or 2 for General Class: ";
        cin>>aaa;}
        break;
    }

}

void hwh_del(int &aaa){
    int aa;
    cout<<"\nSelect 1 For Poorva Express or 2 For Rajdhani Express: ";
        cin>>aa;
        switch(aa){
case 1:
    {
        cout<<"\nSelect 1 for A.C. Class or 2 for General Class: ";
        cin>>aaa;}
        break;
case 2:
    {
        cout<<"\nSelect 1 for A.C. Class or 2 for General Class: ";
        cin>>aaa;}
        break;
    }
}
