#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin>>n;
    int w[101];
    for(int i = 1;i<=n;i++){
        cin>>w[i];
    }
    cin>>k;
    //input
    bool dp[101][40404];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    for(int i = 1;i <=n;i++){
        for(int j = 0;j<=40000;j++){
            if(!dp[i-1][j]) continue; //impossible

            dp[i][j] = true; //chose nothing
            if(abs(j - w[i]) >= 0) dp[i][abs(j-w[i])] = true; // chose - weight
            if(j + w[i] <= 40000) dp[i][j+w[i]] = true; // chose + weight
        }
    }
    //dp cal
    for(int i = 0;i<k;i++){
        int a; cin>>a;
        if(dp[n][a]) cout<<"Y ";
        else cout<<"N ";
    }

    //query
    return 0;
}