#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> v;
unsigned long long int l;
int n, k;
unsigned long long int limit;
short dx[2] = {1, -1};

void BFS(int x) {
    queue<pair<long long int, long long int>> q;
    q.emplace(x, 0);
    v[x] = 0; // Start point distance is 0
    while (!q.empty()) {
        long long cur = q.front().first;
        long long cost = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            long long cx = dx[i] + cur;
            if (cx < 0 || cx > limit) continue;
            if (v[cx] == INT_MAX || v[cx] > cost + 1) {
                v[cx] = cost + 1;
                q.emplace(cx, cost + 1);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l;
    cin >> n >> k;
    
    unsigned long long iter = min(l, (unsigned long long)n * k);
    limit = min(l, (unsigned long long)500505);

    // Initialize the vector `v` with size `limit + 1` to handle all possible positions up to `limit`
    v.resize(limit + 1, INT_MAX); 

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a <= limit) {
            BFS(a);
        }
    }

    // Collect non-INT_MAX values for sorting
    vector<int> results;
    for (unsigned long long i = 0; i <= limit; i++) {
        if (v[i] != INT_MAX) {
            results.push_back(v[i]);
        }
    }

    sort(results.begin(), results.end());

    for (int i = 0; i < k; i++) {
        if (i < results.size()) {
            cout << results[i] << "\n";
        } else {
            cout << -1 << "\n"; // Output -1 if there are not enough results
        }
    }

    return 0;
}
