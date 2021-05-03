#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class employee
{
	string name;
	int number;
public:
	void getdata()
	{
		cout<<endl<<"  enter the name:";
		cin>>name;
		cout<<"  enter the number:";
		cin>>number;
	}
	void putdata()
	{
		cout<<"\tname:"<<name<<endl;
		cout<<"\tnumber:"<<number<<endl;
	}
};

class manager : public employee
{
private:
	string title;
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout<<"  enter title: ";
		cin>>title;
		cout<<"  enter golf club dues :";
		cin>>dues;
	}
	void putdata()
	{
		employee::putdata();
		cout<<"\ttitle:" <<title;
		cout<<"\tgolf club dues:"<<dues;
	}
};
    class scientist :public employee
    {
	private:
		int pubs;
	public:
		void getdata()
		{
			employee::getdata();
			cout<<"  enter the number of publications:";
			cin>>pubs;
		}
		void putdata()
		{
			employee::putdata();
			cout<<"number of publications:"<<pubs;
		}
	};
	class labourer:public employee
	{
	};
	int main()
	{
		manager m1,m2;
		scientist s1;
		labourer l1;
		cout<<"\n enter the details of manager 1:"<<endl;
		m1.getdata();
        cout<<"\n enter the details of manager 2:"<<endl;
		m2.getdata();
        cout<<"\n enter the details of scientist 1:"<<endl;
		s1.getdata();
        cout<<"\n enter the details of labourer 1:"<<endl;
		l1.getdata();

		cout<<"\n\n details of manager:"<<endl;
		m1.putdata();
		m2.putdata();
		cout<<"\n\n details of scientist:"<<endl;
		s1.putdata();
		cout<<"\n\n details of labourer:"<<endl;
		l1.putdata();
		getch();
	}
 
