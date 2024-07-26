#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(int node, vector<vector<int>>& graph,vector<bool>& vis, stack<int>& st){
    vis[node] = true;
    for(auto i : graph[node]){
        if(!vis[i]){
            DFS(i,graph,vis,st);
        }
    }
    st.push(node);
}

void DFS_rev(int node, vector<vector<int>>& graph_rev, vector<bool>& vis, vector<vector<int>>& cycle, int id){
    vis[node] = true;
    cycle[id].push_back(node);
    for(auto i : graph_rev[node]){
        if(!vis[i]){
            DFS_rev(i,graph_rev,vis,cycle,id);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v,e; cin>>v>>e;
    vector<vector<int>>graph(101010);
    vector<vector<int>>graph_rev(101010);
    vector<bool>vis(101010, false);
    vector<vector<int>>cycle(101010);
    stack<int>st;
    for(int i = 0;i<e;i++){
        int a,b;cin>>a>>b;
        graph[a].emplace_back(b);
        graph_rev[b].emplace_back(a);
    }
    // make graph

    for(int i = 1;i<=v;i++){
        if(!vis[i]){
            DFS(i,graph,vis,st);
        }
    }
    // fir DFS
    
    fill(vis.begin(),vis.end(),false);

    int id = 0;
    while(!st.empty()){
        int cur = st.top(); st.pop();
        if(!vis[cur]){
            id++;
            DFS_rev(cur,graph_rev,vis,cycle,id);
        }
    }
    //find scc group

    vector <int> indegree(id,0);
    vector <int> ids(v+1);
    for(int i = 0;i<id;i++){
        for(auto nxt : cycle[i]){
            ids[nxt] = i;
        }
    }
    for(int i = 1;i<=v;i++){
        for(int nxt : graph[i]){
            if(ids[nxt] != ids[i]){
                indegree[ids[nxt]] ++;
            }
        }
    }
    cout<<count(indegree.begin(),indegree.end(),0);

    return 0;
}