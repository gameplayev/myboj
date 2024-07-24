#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        
        int cost[10101];
        int dp[10101] = {}; memset(dp,0,sizeof(dp));
        for(int i = 1;i<=n;i++){
            cin>>cost[i];
        }
        int m; cin>>m;
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = cost[i];j<=m;j++){
                dp[j] += dp[j-cost[i]];
            }
        }
        cout<<dp[m]<<"\n";
        


    }


    return 0;
}