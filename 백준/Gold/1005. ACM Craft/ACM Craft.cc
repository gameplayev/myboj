#include <bits/stdc++.h>
using namespace std;
int t,n,k,w;
vector<int>cost(1010);
vector<int>G[1010];
vector<int>degree(1010);
vector<int>dp(1010);
void topologicalSort(){
    queue<int>q;
    for(int i = 1;i<=n;i++){
        if(degree[i] == 0){
            q.push(i);
            dp[i] = cost[i];
        }
    }
    while (!q.empty()) {
        int cur = q.front();q.pop();
        for(int nxt : G[cur]){
            dp[nxt] = max(dp[nxt],dp[cur]+cost[nxt]);
            if(--degree[nxt] == 0){
                q.push(nxt);
            }
        }
    }
    cout<<dp[w]<<endl;
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>t;
    for(int j = 1;j<=t;j++){
        for(int i = 0;i<1001;i++){
            G[i].clear();
        }
        fill(cost.begin(),cost.end(),0);
        fill(degree.begin(),degree.end(),0);
        fill(dp.begin(),dp.end(),0);
        cin>>n>>k;
        for(int i = 1;i<=n;i++){
            cin>>cost[i];
        }
        for(int i = 0;i<k;i++){
            int a,b;cin>>a>>b;
            G[a].push_back(b);
            degree[b]++;
        }
        cin>>w;
        topologicalSort();
    }
    
    return 0;
}
