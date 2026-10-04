#include<iostream>
using namespace std;
class Point{
	int x, y;
	public:
		Point(int a,int b){
			x = a;
			y = b;
		}
		Point(const Point &p){
			x = p.x;
			y = p.y;
			cout<<"Copy constructor called"<<endl;
		}
		void show(){
			cout<<"x = "<< x <<", y = "<< y <<endl;
		}
};
int main(){
	Point p1(10,20);
	Point p2 = p1;
	p1.show();
	p2.show();
	return 0;
}
