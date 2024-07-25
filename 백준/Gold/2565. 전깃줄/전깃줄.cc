#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
vector<int> dp;
vector<int> x;
int res = 0, n;

void LIS() {
    if (!arr.empty()) {
        x.push_back(arr[0].second);
        dp.push_back(1);
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].second > x.back()) {
            x.emplace_back(arr[i].second);
            dp.push_back(dp.back() + 1);
        } else {
            auto it = lower_bound(x.begin(), x.end(), arr[i].second);
            int idx = it - x.begin();
            x[idx] = arr[i].second;
        }
    }

    res = dp.back();  
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.emplace_back(a, b);
    }

   
    sort(arr.begin(), arr.end());

    LIS();
    cout << n - res << "\n";

    return 0;
}
