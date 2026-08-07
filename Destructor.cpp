#include<iostream>
using namespace std;
class Light{
	public:
		Light(){
			cout<<"Light turn On"<<endl;
		}
		~Light(){
			cout<<"Light turn Off"<<endl;
		}
};
int main(){
	cout<<"Room Fan switched on"<<endl;
	Light l1;
	cout<<"Using the light.."<<endl;
	return 0; 
}
