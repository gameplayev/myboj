#include <iostream>
#include <string.h>
using namespace std;
#define mad 1000000
int main(void){
	char s[mad],ans;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>s;
	int a[30] = {};
	int max = 0;
    int sz = strlen(s);
	for(int i = 0;i<sz;i++){
		if(s[i] >= 'a'){
			a[s[i] - 'a']++;
		}
		else{
			a[s[i] - 'A']++;
		}
	}
	for(int i = 0;i<26;i++){
		if(a[i] == max){
			ans = '?';
		}
		else if(a[i] > max){
			max = a[i];
			ans = 'A' + i;
		}
	}
	cout<<ans;
	return 0;
}