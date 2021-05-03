#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int i, n, j, tax_p;

struct {
	int eid,basic,da,hra,gross_sal, grade,tax_p;
	char ename[50];
	float net_sal, tax;
}s[50],temp;

void sort();
void display_g();
void display_gtax();
void display_ltax();
void set();
void sort_t();
void input();

int main()
{
	int choice;

	system("cls");

	for (;;)
	{
		cout << "\n\n\t\t  MENU";
		cout << "\n\t\t  ****";
		cout << "\n\t1.Enter the Information of Employee:";
		cout << "\n\t2.Display details of given sorted grade.";
		cout << "\n\t3.Display detail of employee who pays highest tax.";
		cout << "\n\t4.Display detail of employee who pays lowest tax.";
		cout << "\n\t5.EXIT.";
		cout << "\n\n\tEnter your choice:";
		cin >> choice;
		system("cls");

		switch (choice)
		{
			case 1:input();
				break;
			case 2:display_g();
				break;
			case 3:display_gtax();
				break;
			case 4:display_ltax();
				break;
			case 5:exit(0);
		}
	}
	getch();
}

void input()
{
	cout << "\n\tEnter the No. of Employee:";
	cin >> n;
	cout << "\n\tEnter the info. of Employee:\n";
	for (i = 0; i < n; i++)
	{
		cout << "\n\tEnter the name of Employee " << i + 1 << ":";
		cin >> s[i].ename;
		cout << "\tEnter the ID of Employee " << i + 1 << ":";
		cin >> s[i].eid;
		cout << "\tEnter the grade of Employee " << i + 1 << ":";
		cin >> s[i].grade;
		cout << "\tEnter the DA of Employee " << i + 1 << ":";
		cin >> s[i].da;
		cout << "\tEnter the HRA of Employee " << i + 1 << ":";
		cin >> s[i].hra;
		
		cout << "\n";
	}
	set();
}

void set()
{
	for (i = 0; i < n; i++)
	{
		if (s[i].grade == 1)
			s[i].basic = 30000;
		else if (s[i].grade == 2)
			s[i].basic = 25000;
		else if (s[i].grade == 3)
			s[i].basic = 20000;
		else if (s[i].grade == 4)
			s[i].basic = 15000;

		s[i].gross_sal = s[i].basic + s[i].da + s[i].hra;

		if (s[i].gross_sal <= 40000)
			s[i].tax_p = 0;
		else if (s[i].gross_sal > 40000 && s[i].gross_sal<=75000)
			s[i].tax_p = 10;
		else if (s[i].gross_sal > 75000)
			s[i].tax_p = 15;

		s[i].tax = s[i].gross_sal * (s[i].tax_p / 100);
		s[i].net_sal = s[i].gross_sal - s[i].tax;

	}
}

void sort()
{
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (s[j].eid > s[j + 1].eid)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void display_g()
{
	int grade;
	cout << "\n\tEnter the grade of the employee to display:";
	cin >> grade;
	
	sort();

	for (i = 0; i < n; i++)
	{
		if (s[i].grade == grade)
		{
			cout << "\n\tEmployee " << i + 1 << "\n";
			cout << "\n\tName:" << s[i].ename;
			cout << "\n\tID:" << s[i].eid;
			cout << "\n\tGrade:" << s[i].grade;
			cout << "\n\tBasic:" << s[i].basic;
			cout << "\n\tDA:" << s[i].da;
			cout << "\n\tHRA:" << s[i].hra;
			cout << "\n\tGross Salary:" << s[i].gross_sal;
			cout << "\n\tNet Salary:" << s[i].net_sal;
		}
	}

}

void sort_t()
{
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (s[j].tax > s[j + 1].tax)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void display_gtax()
{
	sort_t();
	cout << "\n\tEmployee who pays highest tax " << "\n";
	cout << "\n\tName:" << s[0].ename;
	cout << "\n\tID:" << s[0].eid;
	cout << "\n\tGrade:" << s[0].grade;
	cout << "\n\tBasic:" << s[0].basic;
	cout << "\n\tDA:" << s[0].da;
	cout << "\n\tHRA:" << s[0].hra;
	cout << "\n\tTAX:" << s[0].tax;
	cout << "\n\tGross Salary:" << s[0].gross_sal;
	cout << "\n\tNet Salary:" << s[0].net_sal;
}

void display_ltax()
{
	sort_t();
	cout << "\n\tEmployee who pays lowest tax " << "\n";
	cout << "\n\tName:" << s[n-1].ename;
	cout << "\n\tID:" << s[n - 1].eid;
	cout << "\n\tGrade:" << s[n - 1].grade;
	cout << "\n\tBasic:" << s[n - 1].basic;
	cout << "\n\tDA:" << s[n - 1].da;
	cout << "\n\tHRA:" << s[n - 1].hra;
	cout << "\n\tTAX:" << s[n - 1].tax;
	cout << "\n\tGross Salary:" << s[n - 1].gross_sal;
	cout << "\n\tNet Salary:" << s[n - 1].net_sal;
}
