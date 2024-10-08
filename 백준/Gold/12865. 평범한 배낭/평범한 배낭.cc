#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int dp[1001][100001];
int n,k;
int w[1001];
int v[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;

    for(int i = 1;i<=n;i++){
        cin>>w[i] >> v[i];
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1; j <= k;j++){
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][k]<<"\n";
    return 0;
}
