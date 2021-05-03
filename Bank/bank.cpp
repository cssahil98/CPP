#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;

int n, k, p, q, m, i, j;

class bank {

private:
	int acc_no, balance, amt;
	string name, password, pa, q;

public:
	bank()
	{
		acc_no = 0;
		balance = 0;
		amt = 0;
	}
	void create_acc();
	void deposit();
	int generate_acc(int i);
	void withdraw();
	void transfer(bank);
	void display();
	static void sort(bank[]);
	void del_acc();
}b[50];

int main()
{
	int choice;
		system("cls");
	for (;;)
	{
		cout << "\n\n\t\t  MENU";
		cout << "\n\t\t  ****";
		cout << "\n\t1.Create a Account.";
		cout << "\n\t2.Deposit amount to Account.";
		cout << "\n\t3.Withdraw for Account.";
		cout << "\n\t4.Transfer money to another Account.";
		cout << "\n\t5.Display the Details of Acoounts.";
		cout << "\n\t6.Sort on basis of Balance. ";
		cout << "\n\t7.Delete the Account.";
		cout << "\n\t8.EXIT.";
		cout << "\n\n\tEnter your choice:";
		cin >> choice;

		switch (choice)
		{
			case 1: cout << "\n\tEnter the No. of Account(s) to create.";
					cin >> n;
					cout << "\n\tEnter the Information of " << n << " Accounts:\n";
					for (i = 0; i < n; i++)
					{
						b[i].create_acc();
					}
					break;

			case 2: cout << "\n\tEnter the Account No. to deposit:";
					cin >> k;
					b[k].deposit();
					break;

			case 3:	cout << "\n\tEnter the Account No. to Withdraw:";
					cin >> k;		
					b[k].withdraw();
					break;

			case 4: cout << "\n\tEnter Account No. of bank:";
					cin >> k;
					cout << "\n\tEnter Account No. of bank to Transfer:";
					cin >> m;
					b[k].transfer(b[m]);
					break;
		
			case 5: for (i = 0; i <n; i++)
					{	
						b[i].display();
					}
					break;

			case 6: bank::sort(b);
					break;

			case 7:	cout << "\n\tEnter the Account No. to Delete:";
					cin >> k;
					b[k].del_acc();
					break;

			case 8: exit(0);
		}
	}
	_getch();
}

void bank::create_acc()
{
		cout << "\n\n\tEnter Name:";
		cin >> name;
		cout << "\tEnter Password:";
		cin >> password;
		acc_no = generate_acc(i);
		cout << "\tYour Account No. is: " << acc_no;
		cout << "\n\tEnter Balance:";
		cin >> balance;
}

void bank::deposit()
{
	cout << "\n\tEnter password:";
	cin >> pa;
	if (pa == password)
	{
		cout << "\n\tEnter Amount to deposit:";
		cin >> amt;
		balance = balance + amt;
		cout << "\n\tUpdated Balance: " << balance;
	}
	else
	{
		cout << "\n\tINCORRECT PASSWORD!!";
	}
}

void bank::withdraw()
{
	cout << "\n\tEnter password:";
	cin >> pa;
	if (pa == password)
	{
		cout << "\n\tEnter Amount to Withdraw:";
		cin >> amt;

		if (amt <= balance)
			balance = balance - amt;
		else
			cout << "\n\tINSUFFICIENT FUNDS!!";
	}
	else
	{
		cout << "\n\tINCORRECT PASSWORD!!";
	}
}

void bank::transfer(bank a)
{
	cout << "\n\tEnter password of the account from transfer:";
	cin >> pa;
	cout << "\n\tEnter the password of the account to transfer:";
	cin >> q;
	if (pa == password && q == a.password)
	{
		cout << "\n\tEnter Amount to transfer:";
		cin >> amt;
		if (amt <= balance)
		{
			a.balance = a.balance + amt;
			balance = balance - amt;
			cout << "\n\tBALANCE OF THE ACCOUNT THAT TRANSFER:" << balance;
			cout << "\n\tBALANCE OF THE ACCOUNT WHERE TRANSFER:" << a.balance;
		}
		else
			cout << "\n\tINSUFFICIENT FUNDS!!";
	}
	else
	{
		cout << "\n\tINCORRECT PASSWORD!!";
	}
}

void bank::display()
{
	if (acc_no == -1)
	{

	}
	else
	{
		cout << "\n\tAccount " << i + 1 << " Info.\n";
		cout << "\n\tName:" << name;
		cout << "\n\tAccount Number:" << acc_no;
		cout << "\n\tBalance:" << balance;
		cout << "\n\n";
	}
}

int bank::generate_acc(int c)
{
	int acc_nos=0;
	acc_nos += c;
	return acc_nos;
}

void bank::del_acc()
{
	name = "xxx";
	acc_no= - 1;
	balance= - 1;
}

void bank::sort(bank b[])
{
	bank temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (b[i].balance < b[j].balance)
			{
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		b[i].display();
	}

}
