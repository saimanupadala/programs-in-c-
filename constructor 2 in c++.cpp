#include<iostream>
using namespace std;
class Employee{
	public:
		string name;
		float salary;
		void setData(string n,float s){
			name = n;
			salary = s;
		}
		void display(){
			cout<<name<<" earns "<<salary<<endl;
		}
};
int main(){
	Employee emp[3];
	emp[0].setData("Ravi",50000);
	emp[1].setData("Sara",60000);
	emp[2].setData("John",55000);
	for(int i=0;i<3;i++){
		emp[i].display();
	}
	return 0;
}
