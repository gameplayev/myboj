#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    
    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        arr.emplace_back(a,b);
    }
    
    vector<int> dp(n, 1);
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i].second > arr[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int lis_length = *max_element(dp.begin(), dp.end());
    cout << n - lis_length;
    
    return 0;
}
