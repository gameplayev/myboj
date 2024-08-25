#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    long long int dp[101][11];
    for(int i = 1;i<=9;i++){
        dp[1][i] = 1;
    }
    
    dp[1][0] = 0;
    for(int i = 2;i<=100;i++){
        dp[i][0] = dp[i-1][1]%MOD;
        dp[i][9] = dp[i-1][8]%MOD;
        for(int j = 1;j<=8;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
        
    }
    long long ans = 0;
    for(int i = 0;i<=9;i++){
        ans += dp[n][i]%MOD;
    }
    ans %= MOD;
    cout<<ans<<"\n";
    
    return 0;
}
