#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct graph{
    int u,v;
    int w;
};
//data define

void init(int x,vector<int>& par);
int find(int x,vector<int>& par);
bool cmp(graph& a, graph& b);
void unite(int a,int b,vector<int>& par);
//funcs define

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //fastio

    vector<int> par(10101); //union find par
    int v,e; //vertex edges
    graph g[100101] = {}; //grap
    int res = 0;// result
    //vars

    cin>>v>>e;
    for(int i = 0;i<e;i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    //input
    
    init(v,par);
    sort(g,g+e,cmp);

    for(int i = 0;i<e;i++){
        if(find(g[i].u,par) == find(g[i].v,par)){continue;}
        unite(g[i].u,g[i].v,par);
        res += g[i].w;
    }
    //main logic(cal mst)

    cout<<res<<"\n";
    //print res
    return 0;
}

//funcs
void init(int x , vector<int>& par){
    for(int i = 1;i<=x;i++){
        par[i] = i;
    }
}

int find(int x,vector<int>& par){
    if(par[x] == x) return x;
    else return par[x] = find(par[x],par);
}

void unite(int a,int b, vector<int>& par){
    a = find(a,par); b = find(b,par);
    if(a == b) return;
    par[a] = b;
}


bool cmp(graph&a, graph&b){
    return (a.w < b.w);
}

