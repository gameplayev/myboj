#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin>>n>>k;
    vector<int>v(1);
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.emplace_back(a);
    }
    vector<long long>suffix_sum(n+1,0);
    suffix_sum[1] = v[1];
    for(int i = 2;i<=n;i++){
        suffix_sum[i] = suffix_sum[i-1] + v[i];
    }
    
    int left = 1;
    int right = 1;
    int res = INT_MAX;
    while(true){
        long long value = (suffix_sum[right] - suffix_sum[left-1]);
        if(value >= k){
            res = min(res, right - left + 1);
            left++;
        }
        else{
            if(right == n){
                break;
            }
            right++;
        }
        
        
    }
    if(res == INT_MAX){
        cout<<"0\n";
        return 0;
    }
    cout<<res<<"\n";
    
    return 0;
}
