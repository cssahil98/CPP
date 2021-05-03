#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct student {
	int roll_no;
	char name[50];
	int m1, m2, m3, m4, m5;
}s[5],temp;

int main()
{
	int i,j,n;
	cout << "\n\tEnter the info. of students:\n";
	for (i = 0; i < 5; i++)
	{
		cout << "\n\tEnter the name of student " << i + 1 << ":";
		cin>>s[i].name;
		cout << "\tEnter the Roll number of student " << i + 1 << ":";
		cin >> s[i].roll_no;
		cout << "\tEnter the marks of student " << i + 1 << "in M1:";
		cin >> s[i].m1;
		cout << "\tEnter the marks of student " << i + 1 << "in M2:";
		cin >> s[i].m2;
		cout << "\tEnter the marks of student " << i + 1 << "in M3:";
		cin >> s[i].m3;
		cout << "\tEnter the marks of student " << i + 1 << "in M4:";
		cin >> s[i].m4;
		cout << "\tEnter the marks of student " << i + 1 << "in M5:";
		cin >> s[i].m5;
		cout << "\n";
	}
	system("cls");
	n = 5;

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

	cout << "Information of students by Roll Number:\n";

	for (i = 0; i < 5; i++)
	{
		cout << "\n\tName of student :"<< s[i].name;
		cout << "\n\tRoll number of student :"<< s[i].roll_no;
		cout << "\n\tMarks in M1:"<< s[i].m1;
		cout << "\n\tMarks in M2:"<< s[i].m2;
		cout << "\n\tMarks in M3:"<< s[i].m3;
		cout << "\n\tMarks in M4:"<< s[i].m4;
		cout << "\n\tMarks in M5:"<< s[i].m5;
		cout << "\n";
	}
	getch();
}
