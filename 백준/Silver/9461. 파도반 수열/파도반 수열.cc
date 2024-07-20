#include <bits/stdc++.h>
using namespace std;
long long int mem[101] = {-1,};
long long int f(int x){
    if(x < 3){
        if(x == 0) return 0;
        return 1;
    }
    if(mem[x] != -1){
        return mem[x];
    }
    else{
        mem[x] = f(x-2) + f(x-3);
        return mem[x];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    memset(mem,-1,sizeof(mem));
    for(int i = 0;i<n;i++){
        int x; cin>>x;
        cout<<f(x)<<"\n";
    }
    
    
    return 0;
}
