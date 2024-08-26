#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    deque<pair<int, int>> dq;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
      
        while (!dq.empty() && dq.back().first >= A[i]) {
            dq.pop_back();
        }

       
        dq.push_back({A[i], i});

       
        if (dq.front().second <= i - L) {
            dq.pop_front();
        }

        
        result.push_back(dq.front().first);
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
