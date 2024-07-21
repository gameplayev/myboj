#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    vector<vector<int>> costs(N + 1, vector<int>(3));
    for (int i = 1; i <= N; ++i) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    int result = INF;

    for (int startColor = 0; startColor < 3; ++startColor) {
        vector<vector<int>> dp(N + 1, vector<int>(3, INF));

        dp[1][startColor] = costs[1][startColor];

        for (int i = 2; i <= N; ++i) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }


        for (int lastColor = 0; lastColor < 3; ++lastColor) {
            if (lastColor != startColor) {
                result = min(result, dp[N][lastColor]);
            }
        }
    }

    cout << result << endl;

    return 0;
}
