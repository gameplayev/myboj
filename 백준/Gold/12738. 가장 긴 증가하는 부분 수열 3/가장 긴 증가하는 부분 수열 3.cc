#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> dp;
vector<int> x;
int res = 0, n;

void LIS() {
    if (!arr.empty()) {
        x.push_back(arr[0]);
        dp.push_back(1);
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > x.back()) {
            x.emplace_back(arr[i]);
            dp.push_back(x.size());
        } else {
            auto it = lower_bound(x.begin(), x.end(), arr[i]);
            int idx = it - x.begin();
            x[idx] = arr[i];
            dp.push_back(idx + 1);
        }
    }

    res = *max_element(dp.begin(), dp.end());  
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.emplace_back(a);
    }

    LIS();
    cout << res << "\n";

    return 0;
}
