#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned int n;
	cin>>n;
	int a[10001] = {};
	int b;
	for(int i = 1;i<=n;i++){
		cin>>b;
		a[b]++;
	}
	for(int i = 1;i<=10000;i++){
		for(int k =0;k<a[i];k++){
			cout<<i<<"\n";
		}
	}
	
	return 0;
}