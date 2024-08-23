#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin() + 1, v.end());

    vector<long long int> ans(3);
    long long res = LLONG_MAX;

    for (int i = 1; i < n - 1; i++) {
        long long int start = i + 1;
        long long int end = n;

        while (start < end) {
            long long sum = v[start] + v[end] + v[i];

            if (abs(sum) < abs(res)) {
                res = sum;
                ans[0] = v[i];
                ans[1] = v[start];
                ans[2] = v[end];
            }

            if (sum < 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (auto nxt : ans) {
        cout << nxt << " ";
    }

    return 0;
}
