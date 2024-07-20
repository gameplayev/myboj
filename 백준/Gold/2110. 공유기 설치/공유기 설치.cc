#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,r;cin>>n>>r;
    vector<int>pos;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        pos.emplace_back(a);
    }
    sort(pos.begin(),pos.end());
    int ans = 0;
    int start = 1;
    int end = pos[n-1] - pos[0];
    while(start <= end){
        int mid = (start +end) /2;
        int prev = pos[0]; int cnt = 1;
        for(int i = 1;i<n;i++){
            if(pos[i] - prev >= mid){
                cnt++;
                prev = pos[i];
            }
        }
        if(cnt >= r){
            ans = max(ans,mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}