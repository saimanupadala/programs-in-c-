#include<iostream>
using namespace std;
class Flower{
	string name;
	int petals;
	public:
		Flower(string n, int p){
			name = n;
			petals = p;
			cout<<name<<" created with "<<petals<<"petals."<<endl;
		}
		void show(){
			cout<<name<<" has "<<petals<<"petals."<<endl;
		}
};
int main(){
	Flower rose("Rose",5);
	Flower lily("lily",3);
	rose.show();
	lily.show();
	return 0;
}
