#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct node{
    int node;
    int linked_node;
    int cost;
};

vector<int> init(vector<int>& par){
    for(int i = 1;i<par.size();i++){
        par[i] = i;
    }
    return par;
}

int find(int x,vector<int>& par){
    if(par[x] == x) return x;
    return par[x] = find(par[x],par);
}

void unite(int a,int b, vector<int>& par){
    a = find(a,par); b = find(b,par);
    if(a == b) return;
    par[a] = b;
}

bool cmp(node & a, node & b){
    return(a.cost < b.cost);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<node>graph;
    for(int i = 0;i<m;i++){
        node d; int a,b,c; cin>>a>>b>>c;
        d.node = a; d.linked_node = b; d.cost = c;
        graph.emplace_back(d);
    }
    vector<int>par(n+1);
    init(par);
    sort(graph.begin(),graph.end(),cmp);
    
    long long res = 0;
    for(int i = 0;i<m;i++){
        node cur = graph[i];
        if(find(cur.node,par) == find(cur.linked_node,par)){continue;}
        unite(cur.node,cur.linked_node,par);
        res += cur.cost;
    }
    cout<<res<<"\n";
    return 0;
}
