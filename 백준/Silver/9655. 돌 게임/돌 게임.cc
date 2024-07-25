#include <iostream>
bool winer = false;//sk
using namespace std;
void change(){
	if(winer == true){
		winer = false;
	}
	else{
		winer = true;
	}
}
int main(void){
	int n;
	cin>>n;
	while(n > 0){
		if(n>=3){
			n-=3;
			change();
		}
		else{
			n--;
			change();
		}
	}
	if(!winer){
		cout<<"CY";
	}
	else{
		cout<<"SK";
	}
	return 0;
}