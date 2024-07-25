#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l;
    int n, k;
    cin >> l >> n >> k;

    unordered_map<unsigned long long, int> m;
    vector<int> res(500050, 0);
    queue<unsigned long long> q;
    int limit = 0;

    for (int i = 0; i < n; i++) {
        unsigned long long a;
        cin >> a;
        if (m.find(a) == m.end()) {
            m[a] = 0;
            q.push(a);
            res[0]++;
            limit++;
        }
    }

    int iter = 1;
    while (limit < k && !q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            unsigned long long cur = q.front();
            q.pop();
            if (cur > 0 && cur - 1 <= l && m.find(cur - 1) == m.end()) {
                m[cur - 1] = iter;
                q.push(cur - 1);
                res[iter]++;
                limit++;
                if (limit >= k) break;
            }
            if (cur + 1 <= l && m.find(cur + 1) == m.end()) {
                m[cur + 1] = iter;
                q.push(cur + 1);
                res[iter]++;
                limit++;
                if (limit >= k) break;
            }
        }
        iter++;
    }

    int count = 0;
    for (int i = 0; res[i] != 0; i++) {
        for (int j = 0; j < res[i]; j++) {
            if (count >= k) break;
            cout << i << "\n";
            count++;
        }
    }

    return 0;
}
