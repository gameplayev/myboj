#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    int arr[101010] = {};
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int l = 0,r = 0;
    int res = INT_MAX;
    
    int start = 0, end = n-1;
    
    while(start != end){
        int cal = arr[start] + arr[end];
        if(res > abs(cal)){
            res = abs(cal);
            l = arr[start];
            r = arr[end];
        }
        if(cal > 0){
            end --;
        }
        else{
            start ++;
        }
    }
    int ans[5] = {l,r};
    sort(ans,ans+2);
    for(int i = 0;i<2;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}