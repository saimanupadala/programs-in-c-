#include<iostream>
using namespace std;
class Rectangle{
	public:
		int length,width;
	    Rectangle(int l,int w){
			 
			 length=l;
			width=w;
		}
		int area(){
			return length*width;
	}
};
int main()
{
	Rectangle r1(10,5);
	Rectangle r2(8,4);
	cout<<"Area of r1:"<<r1.area()<<endl;
	cout<<"Area of r2:"<<r2.area()<<endl;
	return 0;
	}
	
