#include<iostream>
using namespace std;
class Test
{
	int a,b;
	public:
		void getdata();
		void putdata();
		Test sum(Test t);
};
void Test::getdata()
{
	cout<<"Enter a,b values";
	cin>>a>>b;
}
void Test::putdata()
{
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}
Test Test::sum(Test t2)
{
	Test t3;
	t3.a= a+t2.a;
	t3.b= b+t2.b;
	return t3;
}
int main()
{ 
Test t1,t2,t3;
t1.getdata();
t2.getdata();
t3 = t1.sum(t2);
t1.putdata();
t2.putdata();
t1.putdata();
t2.putdata();
cout<<"\n t3 obj data in"<<endl;
t3.putdata();
}
