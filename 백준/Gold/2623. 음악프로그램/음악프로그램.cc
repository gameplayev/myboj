#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>G[200001];
vector<int>degree(200001);
vector<int>ans;
void topologicalSort(){
    queue<int>q;
    for(int i = 1;i<=n;i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();q.pop();
        ans.push_back(cur);
        for(int nxt : G[cur]){
            if(--degree[nxt] == 0){
                q.push(nxt);
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int num;cin>>num;
        int a,b;
        if(num == 0){continue;}
        cin>>a;
        if(num == 1){continue;}
        for(int j = 0;j<num-1;j++){
            cin>>b;
            G[a].push_back(b);
            degree[b]++;
            a = b;
        }
    }
    topologicalSort();
    if(ans.size() !=  n){
        cout<<"0\n";
        return 0;
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}
