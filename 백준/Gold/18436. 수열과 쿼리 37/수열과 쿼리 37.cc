#include <bits/stdc++.h>
using namespace std;

using pii = pair<long long,long long>; //odd first even second

pii config_segment_tree(int node, int start, int end,vector<pii>& segment_tree, vector<long long>& list);
void update_elements_in_segment_tree(int node, int start, int end,int index,int even,int odd,vector<pii>& segment_tree);
pii find_elements_in_segment_tree(int node, int start, int end, int left , int right,vector<pii>& segment_tree);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<long long>list(n+1);
    vector<pii>segment_tree(n*4 + 1);
    for(int i = 1;i<=n;i++){
        cin>>list[i];
    }
    config_segment_tree(1, 1, n,segment_tree, list);
    
    int m; cin>>m;
    
    for(int i = 0;i<m;i++){
        short q; cin>>q;
        if(q == 1){
            int v,e; cin>>v>>e;
            if(list[v]%2 == 0 && e%2 == 1){
                update_elements_in_segment_tree(1, 1, n, v, -1, 1, segment_tree);
            }
            else if(list[v]%2 == 1 && e %2 == 0){
                update_elements_in_segment_tree(1, 1, n, v, 1, -1, segment_tree);
            }
            list[v] = e;
            
        }
        else if(q == 2){
            int v,e; cin>>v>>e;
            pii c = find_elements_in_segment_tree(1, 1, n, v, e, segment_tree);
            cout<<c.second<<"\n";
        }
        else{
            int v,e; cin>>v>>e;
            pii c = find_elements_in_segment_tree(1, 1, n, v, e, segment_tree);
            cout<<c.first<<"\n";
        }
    }
    
    
    return 0;
}

pii config_segment_tree(int node, int start, int end,vector<pii>& segment_tree, vector<long long>& list){
    if(start == end){
        if(list[start]%2 == 0){
            return segment_tree[node] = {0,1};
        }
        else{
            return segment_tree[node] = {1,0};
        }
    }
    int mid = (start +end)/2;
    pii left = config_segment_tree(node *2, start, mid,segment_tree, list);
    pii right = config_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list);
    return segment_tree[node] = {left.first +right.first, right.second + left.second};
}

void update_elements_in_segment_tree(int node, int start, int end,int index,int even,int odd,vector<pii>& segment_tree){
    if(index < start || end < index) return;
    segment_tree[node].first += odd;
    segment_tree[node].second += even;
    
    if(start != end){
        int mid = (start + end)/2;
        update_elements_in_segment_tree(node * 2, start, mid, index,even,odd,segment_tree);
        update_elements_in_segment_tree(node * 2 + 1, mid + 1, end,index,even,odd ,segment_tree);
    }
}

pii find_elements_in_segment_tree(int node, int start, int end, int left , int right,vector<pii>& segment_tree){
    if(right < start || left > end){return {0,0};}
    if(left <= start && end <= right) return segment_tree[node];
    int mid = (start + end)/2;
    pii l = find_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree);
    pii r = find_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree);
    
    return {l.first + r.first , l.second + r.second};
}

