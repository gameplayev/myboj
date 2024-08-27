#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void update_segment_tree_elements(int node, int start,int end, int index,vector<long long int>& segment_tree){
    if(start == end){
        segment_tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    if(index  <= mid) update_segment_tree_elements(node * 2,start, mid,index,segment_tree);
    else update_segment_tree_elements(node * 2+ 1, mid + 1,end,index,segment_tree);
    segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2+ 1];
}

long long int count_swap_number_with_segment_tree(int node , int start, int end,int left,int right,vector<long long int>& segment_tree){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return segment_tree[node];
    int mid = (start + end) / 2;
    int left_res = count_swap_number_with_segment_tree(node *2 ,start, mid ,left,right,segment_tree);
    int right_res = count_swap_number_with_segment_tree(node *2 + 1,mid + 1, end,left,right,segment_tree);
    return left_res + right_res;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n; cin>>n; long long ans = 0;
    vector<pair<long long int,long long int>>list(n+1);
    vector<long long int>segment_tree(n*4 + 1);
    for(int i = 1;i<=n;i++){
        long long int a;cin>>a;
        list[i] = {a,i};
    }
    sort(list.begin(), list.end());
    for(int i = 1;i<=n;i++){
        ans +=  (long long)count_swap_number_with_segment_tree(1,1,n,list[i].second + 1, n ,segment_tree);
        update_segment_tree_elements(1,1,n,list[i].second,segment_tree);
    }
    cout<<ans;
}