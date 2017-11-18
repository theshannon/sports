#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

class MEMBER
{
 int memid,age;
 char game[10],name[40],gender,username[15],gametype[8];
 long telno,password;

public:
 void newmember();
 void login();
 void search();
 void design();
 void menu();

 long number()
 {
  return telno;
 }

 int idno()
 {
  return memid;
 }

 char* uname()
 {
  return username;
 }

 long pawor()
 {
  return password;
 }
};

void MEMBER::login()
{
  MEMBER M;
 char identity[10];
 long pwd;
 int flag;
 ifstream fin;
 fin.open("SPORTS.DAT",ios::in|ios::binary);
 do
 {
  flag=0;
  gotoxy(20,10);
  cout<<"Enter username:";
  gotoxy(20,12);
  cout<<"Enter password:";
  gotoxy(40,10);
  cin>>identity;
  gotoxy(40,12);
  cin>>pwd;
  fin.seekg(0,ios::beg);
  while(fin.read((char*)&M,sizeof(M)))
  {
	if(strcmp(M.uname(),identity)==0&&M.pawor()==pwd)
	{
		flag=1;
	}
  }
  clrscr();
 }
 while(flag==0);
 fin.close();
}

 void MEMBER::newmember()
  {
  clrscr();
  MEMBER M;
  char details[10][20]={"Name","Game","MemberID","Age","Gender","Username","TellNo","Password"};
  ofstream fout;
  fout.open("SPORTS.DAT",ios::app|ios::binary);
  gotoxy(10,3);
  cout<<"Enter the Details: ";
  for(int i=0;i<8;i++)
  {
	gotoxy(10,7+2*i);
	cout<<details[i];
	gotoxy(20,7+2*i);
	cout<<":";
  }
  gotoxy(22,7);
  gets(M.name);
  gotoxy(22,9);
  gets(M.game);
  gotoxy(22,11);
  cin>>M.memid;
  gotoxy(22,13);
  cin>>M.age;
  gotoxy(22,15);
  cin>>M.gender;
  gotoxy(22,17);
  gets(M.username);
  gotoxy(22,19);
  cin>>M.telno;
  gotoxy(22,21);
  cin>>M.password;
  fout.write((char*)&M,sizeof(M));
  fout.close();
}

void MEMBER::search()
{
 clrscr();
 MEMBER M;
 char details[10][20]={"Name","Username","Mem ID","Age","Gender","TellNo"};
 int id;
 cout<<"Enter id:";
 cin>>id;
 cout<<'\n';
 ifstream fin;
 fin.open("SPORTS.DAT",ios::in|ios::binary);
 while(fin.read((char*)&M,sizeof(M)))
 {
  if(M.idno()==id)
  {
	for(int i=0;i<6;i++)
  {
	gotoxy(10,5+2*i);
	cout<<details[i];
	gotoxy(20,5+2*i);
	cout<<":";
  }
  gotoxy(22,5);
  cout<<M.name;
  gotoxy(22,7);
  cout<<M.username;
  gotoxy(22,9);
  cout<<M.memid;
  gotoxy(22,11);
  cout<<M.age;
  gotoxy(22,13);
  cout<<M.gender;
  gotoxy(22,15);
  cout<<M.telno<<'\n'<<'\n';
	break;
  }
 }
 fin.close();
}

void delay()
{
 long k;
 for(k=0;k<10000;k++)
 {}
}

void MEMBER::design()
{
 int i,j;
 for(i=39,j=40;i>=0;i--,j++)
 {
  gotoxy(i,0);
  cout<<"*";
  delay();
  gotoxy(j,0);
  cout<<"*";
  delay();
 }
 for(i=0,j=0;i<25;i++,j++)
 {
 gotoxy(0,i);
  cout<<"*";
  delay();
  gotoxy(79,i);
  cout<<"*";
  delay();
 }
}

void menupage()
{
	gotoxy(20,3);
	cout<<" MAIN MENU ";
	gotoxy(10,6);
	cout<<"1. NEWMEMBER";
	gotoxy(10,10);
	cout<<"2. SEARCH";
	gotoxy(10,14);
	cout<<"3. SPORTCHOICE";
	gotoxy(10,18);
	cout<<"4. EXIT";
}

void box(int x,int y)
{
 gotoxy(x-1,y-1);
 cout<<"* * * * * * * * *";
 gotoxy(x-1,y);
 cout<<"*               *";
 gotoxy(x-1,y+1);
 cout<<"*               *";
 gotoxy(x-1,y+2);
 cout<<"* * * * * * * * *";
}

void MEMBER::menu()
{
 int option,j,i;
 char ch='8';
 do
 {
  i=6;
  ch=0;
  while(ch!=13)
  {
	box(10,i);
	menupage();
	ch=getch();
	switch(ch)
	{
	case '8':if(i==6)
				i=18;
				else
				i-=4;
				break;
	case '2':if(i==18)
				i=6;
				else
				i+=4;
				break;
	default :break;
	}
	clrscr();
  }
  j=(i-2)/4;
  switch(j)
  {
	case 1:newmember();
				break;
	case 2:search();
				break;
	case 3:break;
	case 4:break;
	default:cout<<"INVALID";
				break;
  }
  gotoxy(10,20);
  cout<<"PRESS ANY KEY TO CONTINUE...";
  getch();
  clrscr();
 }
while(j!=4);
cout<<"THANKS FOR USING MYSPORTS";
cout<<'\n';
cout<<"Special Credits goes to Shannon and Joshua \n";
cout<<"NO THANKS TO VINAYAK";
}

void slow()
{
int k;
for(k=0;k<5000;k++)
{}
}

void load()
{
 int k;
 gotoxy(10,10);
 cout<<".............................LOADING...........................";
 for(k=0;k<=1000;k++)
  {
	slow();
	cout<<k;
  }
 cout<<"%";
}

void main()
{
 MEMBER M;
 M.login();
 M.menu();
}
