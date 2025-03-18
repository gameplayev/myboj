#include <iostream>
#include <vector>
using namespace std;
int n,m;

void update(int node, int start, int end,int index,long long int value,vector<long long int>& segtree){
    if(index < start || index > end){
        return;
    }
    segtree[node] += value;
    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, value, segtree);
        update(node * 2 + 1,  mid + 1, end, index, value, segtree);
    }
}

long long count(int node, int start, int end, int left, int right, vector<long long int>& segtree){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) {
        return segtree[node];
    }
    int mid = (start+end)/2;
    long long left_res = count(node*2, start,mid,left,right,segtree);
    long long right_res = count(node*2 + 1, mid +1, end,left,right,segtree);
    return left_res+ right_res;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<long long int>segtree(4040404,0);
    vector<long long int>list(1010101,0);
    for(int i = 0;i<m;i++){
        int q; cin>>q;
        if(!q){
            int a,b; cin>>a>>b;
            if(a<b)cout<<count(1,1,n,a,b,segtree)<<"\n";
            else cout<<count(1,1,n,b,a,segtree)<<"\n";
        }else{
            int a,b; cin>>a>>b;
            long long int buf = b - list[a];
            list[a] = b;
            update(1, 1, n, a, buf, segtree);
        }
    }
    return 0;
}
