#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

inline int mid(int s, int e) { return (e+s) /2; }

pii make_segment_tree(int node, int start, int end, vector<pii>& segment_tree, vector<int>& list) {
    if (start == end) return segment_tree[node] = {list[start], list[start]};
    int m = mid(start, end);

    pii l = make_segment_tree(node * 2, start, m, segment_tree, list);
    pii r = make_segment_tree(node * 2 + 1, m + 1, end, segment_tree, list);

    segment_tree[node].first = min(l.first, r.first);
    segment_tree[node].second = max(l.second, r.second);
    return segment_tree[node];
}

pii update_elements_in_segment_tree(int node, int start, int end, int index, vector<pii>& segment_tree, vector<int>& list) {
    if (index < start || index > end) return segment_tree[node];
    if (start == end) {
        segment_tree[node].first = segment_tree[node].second = list[index];
        return segment_tree[node];
    }

    int m = mid(start, end);

    pii l = update_elements_in_segment_tree(node * 2, start, m, index, segment_tree, list);
    pii r = update_elements_in_segment_tree(node * 2 + 1, m + 1, end, index, segment_tree, list);

    segment_tree[node].first = min(l.first, r.first);
    segment_tree[node].second = max(l.second, r.second);
    return segment_tree[node];
}

pii handle_query_with_segment_tree(int node, int start, int end, int left, int right, vector<pii>& segment_tree) {
    if (start > right || end < left) return {INT_MAX, INT_MIN};
    if (left <= start && end <= right) return segment_tree[node];

    int m = mid(start, end);

    pii l = handle_query_with_segment_tree(node * 2, start, m, left, right, segment_tree);
    pii r = handle_query_with_segment_tree(node * 2 + 1, m + 1, end, left, right, segment_tree);

    pii res;
    res.first = min(l.first, r.first);
    res.second = max(l.second, r.second);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pii> segment_tree(n * 4);
        vector<int> list(n);

        for (int i = 0; i < n; ++i) {
            list[i] = i;
        }

        make_segment_tree(1, 0, n - 1, segment_tree, list);

        for (int i = 0; i < m; ++i) {
            int q, a, b;
            cin >> q >> a >> b;

            if (q == 0) {
                if (a != b) {
                    swap(list[a], list[b]);
                    update_elements_in_segment_tree(1, 0, n - 1, a, segment_tree, list);
                    update_elements_in_segment_tree(1, 0, n - 1, b, segment_tree, list);
                }
            } else {
                pii res = handle_query_with_segment_tree(1, 0, n - 1, a, b, segment_tree);
                if (res.first == a && res.second == b) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
