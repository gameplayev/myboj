#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

pii config_segment_tree(int node, int start, int end, vector<pii>& segment_tree, vector<int>& list);
void update_segment_tree_elements(int node, int start, int end, int index, int new_value, vector<pii>& segment_tree);
pii find_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<pii>& segment_tree);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> list(n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> list[i];
    }
    
    vector<pii> segment_tree(n * 4);
    config_segment_tree(1, 1, n, segment_tree, list);
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        if(q == 1){
            int v, e;
            cin >> v >> e;
            update_segment_tree_elements(1, 1, n, v, e, segment_tree);
            list[v] = e;
        } else {
            
            pii c = find_elements_in_segment_tree(1, 1, n, 1, n, segment_tree);
            cout<<c.second<<"\n";
        }
    }

    return 0;
}

pii config_segment_tree(int node, int start, int end, vector<pii>& segment_tree, vector<int>& list){
    if(start == end){
        return segment_tree[node] = {list[start] , start};
    }
    
    int mid = (start + end) / 2;
    pii left = config_segment_tree(node * 2, start, mid, segment_tree, list);
    pii right = config_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list);
    if(left.first > right.first){
        return segment_tree[node] = right;
    }
    else{
        return segment_tree[node] = left;
    }
}

void update_segment_tree_elements(int node, int start, int end, int index, int new_value, vector<pii>& segment_tree){
    if(index < start || end < index) return;
    if(start == end){
        segment_tree[node] = {new_value,index};
        return;
    }
    int mid = (start + end) / 2;
    update_segment_tree_elements(node * 2, start, mid, index, new_value, segment_tree);
    update_segment_tree_elements(node * 2 + 1, mid + 1, end, index, new_value, segment_tree);
    
    segment_tree[node] = min(segment_tree[node * 2], segment_tree[node * 2 + 1]);
}

pii find_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<pii>& segment_tree){
    if(right < start || left > end){
        return {INT_MAX,INT_MAX};
    }
    
    if(left <= start && right >= end){
        return segment_tree[node];
    }
    
    int mid = (start + end) / 2;
    pii l = find_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree);
    pii r = find_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree);
    return min(l, r);
}
