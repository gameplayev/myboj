#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; 
    cin >> n >> k;
    
    vector<int> cost(n);
    vector<int> dp(k + 1, INT_MAX);
    

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    
    dp[0] = 0;
    
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i >= cost[j] && dp[i - cost[j]] != INT_MAX){
                dp[i] = min(dp[i], dp[i - cost[j]] + 1);
            }
        }
    }
    
    if(dp[k] == INT_MAX){
        cout << "-1\n";
    }
    else{
        cout << dp[k] << "\n";
    }
    
    return 0;
}