#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct dpstrs{
int num;
char name[50];
char from[10];
char to[10];
double arrival;
double departure;
}l;


void main(){
    clrscr();
    char k='Y';
    while(k=='y'||k=='Y'){
        cout<<"Train Number: ";   cin>>l.num;
        cout<<"\nTrain's Name: "; gets(l.name);
        cout<<"\nFrom: ";         gets(l.from);
        cout<<"\nTo: ";           gets(l.to);
        cout<<"\nArrival At: ";   cin>>l.arrival;
        cout<<"\nDeparture At: "; cin>>l.departure;
        ofstream list;
        list.open("List.dat",ios::binary|ios::ate);
        list.write((char*)&l,sizeof(l));
        list.close();
        cout<<"\nWant To Enter More Data? (Y: Yes / N: No) ";
        cin>>k;
        cout<<endl;}
}

