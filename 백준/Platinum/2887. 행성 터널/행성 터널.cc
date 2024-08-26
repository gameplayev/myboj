#include <bits/stdc++.h>
using namespace std;

int par[101010] = {};

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int a,int b){
    a = find(a); b = find(b);
    if(a == b) return;
    par[a] = b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<vector<pair<int,int>>>v(3);
    vector<tuple<int,int,int>>vec(101010);
    for(int i = 0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        v[0].emplace_back(a,i);
        v[1].emplace_back(b,i);
        v[2].emplace_back(c,i);
        par[i] = i;
    }
    
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    
    for(int i = 0;i<n-1;i++){
        vec.emplace_back(abs(v[0][i].first - v[0][i+1].first),v[0][i].second,v[0][i+1].second);
        vec.emplace_back(abs(v[1][i].first - v[1][i+1].first),v[1][i].second,v[1][i+1].second);
        vec.emplace_back(abs(v[2][i].first - v[2][i+1].first),v[2][i].second,v[2][i+1].second);
    }
    sort(vec.begin(),vec.end());
    long long res = 0;
    int len = vec.size();
    for(int i = 0;i<len;i++){
        if(find(get<2>(vec[i])) != find(get<1>(vec[i]))){
            res += get<0>(vec[i]);
            Union(get<1>(vec[i]), get<2>(vec[i]));
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
