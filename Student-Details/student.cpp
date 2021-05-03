/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int i,j,n,st,a;
void average();
void sort();
void display();
void input();
struct student {
	int roll_no;
	char name[50];
	int m1, m2, m3, m4, m5;
	float total,av;
}s[100],temp;

int main()
{
	int choice;
	
	system("cls");

	for(;;)
	{
			cout<<"\n\n\tMENU";
			cout<<"\n\t1.Enter the Information of Student:";
			cout<<"\n\t2.Average Marks of Student.";
			cout<<"\n\t3.Sorting of Student.";
			cout<<"\n\t4.Display Information of Student:";
			cout<<"\n\t5.EXIT.";
			cout<<"\n\tEnter your choice:";
			cin>>choice;
			system("cls");

			switch(choice)
			{
				case 1:input();
					break;
				case 2:average();
					break;
				case 3:sort();
					break;
				case 4:display();
					break;
				case 5:exit(0);
			}
	}
	getch();
}

void average()
{
	int av[100];
	for (i = 0; i < n; i++)
	{
		s[i].total=s[i].m1+s[i].m2+s[i].m3+s[i].m4+s[i].m5;
		s[i].av=s[i].total/5;
	}
	a=1;
}

void sort()
{
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (s[j].roll_no > s[j+1].roll_no)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	st=0;
}

void display()
{
	if(st==1)
		cout << "Information of students sorted by Roll Number:\n";

		for (i = 0; i < n; i++)
		{
			cout << "\n\tName of student :"<< s[i].name;
			cout << "\n\tRoll number of student :"<< s[i].roll_no;
			cout << "\n\tMarks in M1:"<< s[i].m1;
			cout << "\n\tMarks in M2:"<< s[i].m2;
			cout << "\n\tMarks in M3:"<< s[i].m3;
			cout << "\n\tMarks in M4:"<< s[i].m4;
			cout << "\n\tMarks in M5:"<< s[i].m5;
			if(a==1)
				cout << "\n\tAverage Marks of Student:"<< s[i].av;

			cout << "\n";
		}
}

void input()
{
		cout<<"\n\tEnter the No. of Students:";
		cin>>n;
		cout << "\n\tEnter the info. of students:\n";
		for (i = 0; i < n; i++)
		{
			cout << "\n\tEnter the name of student " << i + 1 << ":";
			cin>>s[i].name;
			cout << "\tEnter the Roll number of student " << i + 1 << ":";
			cin >> s[i].roll_no;
			cout << "\tEnter the marks of student " << i + 1 << " in M1:";
			cin >> s[i].m1;
			cout << "\tEnter the marks of student " << i + 1 << " in M2:";
			cin >> s[i].m2;
			cout << "\tEnter the marks of student " << i + 1 << " in M3:";
			cin >> s[i].m3;
			cout << "\tEnter the marks of student " << i + 1 << " in M4:";
			cin >> s[i].m4;
			cout << "\tEnter the marks of student " << i + 1 << " in M5:";
			cin >> s[i].m5;
			cout << "\n";
		}
}
