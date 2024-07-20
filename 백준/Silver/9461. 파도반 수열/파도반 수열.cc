#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    long long int dp[101] = {};
    dp[0] = 0; dp[1] = 1; dp[2] = 1; //init
    for(int i = 3;i<101;i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    for(int i = 0;i<n;i++){
        int x; cin>>x;
        cout<<dp[x]<<"\n";
    }
    
    
    return 0;
}
