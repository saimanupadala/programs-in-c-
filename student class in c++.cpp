#include<iostream>
#include<string>
using namespace std;
class student
	{
	private:
	    int rollno;
		string name;
	public:
		void setData(int r,string n)
			{
			rollno = r;
			name = n;
		}
		void display(){
			cout<<"Roll No:"<<rollno<<",Name:"<<name<<endl;
		}
};
int main(){
	student s1,s2;
	s1.setData(101,"Amit");
	s2.setData(102,"priya");
	s1.display();
	s2.display();
	return 0;
}
