#include<iostream>
using namespace std;
class Employee
{
	int id;
	char name[30];
	public:
		void getdata();
		void putdata();
};
void Employee::getdata()
{
	cout<<"Enter Employee ID:";
	cin>>id;
	cout<<"Enter Employee Name:";
	cin>>name;
}
void Employee::putdata()
{
	cout<<"Employee ID:"<<id<<endl;
	cout<<"Employee Name:"<<name<<endl;
}
int main()
{
Employee emp[30];
int n;
cout<<"Enter Number of Employees:";
cin>>n;
for(int i=0;i<n;i++)
{
	cout<<"\n Employee"<<i+1<<endl;
	emp[i].getdata();
}
cout<<"\n Emplyee Details\n";
for(int i=0;i<n;i++)
{
	emp[i].putdata();
	cout<<endl;
}
return 0;
}

