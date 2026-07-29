#include<iostream>
using namespace std;
   class Employee{
   	string name;
   	int empId;
   	double salary;
   	public:
   		void setData(string n, int id, double s){
   			name= n;empId = id; salary=s;
		   }
		   void display()
		   {
		   	cout<<empId<<"|"<<name<<"|Rs."<<salary<<endl;	
		   }
	};
	int main()
	{
		Employee staff[3];
		staff[0].setData("Ravi",101,45000);
		staff[1].setData("Priya",102,52000);
		staff[2].setData("Kumar",103,39000);
		for(int i=0;i<3;i++)
		staff[i].display();
		return 0;
	}

