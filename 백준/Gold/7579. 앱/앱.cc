#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    int dp[110][10101] = {};//앱 i개까지 고려했을때 비용 j로 만들 수 있는 최대 비용을 구하고 m보다 큰 dp 모든 값에 대한 최소값이 정답..
    int value[110] = {}; int cost[110] = {};
    for(int i = 1;i<=n;i++){
        cin>>value[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>cost[i];
    }
    int ans = INT_MAX;
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=10101;j++){
            if(j < cost[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + value[i]);
                if(dp[i][j] >= m){
                    ans = min(ans,j);
                }
            }
        }
    }
    cout<<ans<<"\n";
    
    
    return 0;
}

