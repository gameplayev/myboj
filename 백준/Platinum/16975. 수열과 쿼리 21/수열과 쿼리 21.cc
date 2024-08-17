#include <bits/stdc++.h>
using namespace std;
vector<long long> lazy;

long long make_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list) {
    if (start == end) {
        segment_tree[node] = list[start];
        return segment_tree[node];
    } else {
        int mid = (start + end) / 2;
        long long left_res = make_segment_tree(node * 2, start, mid, segment_tree, list);
        long long right_res = make_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list);
        segment_tree[node] = left_res + right_res;
        return segment_tree[node];
    }
}

void lazy_update_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& lazy) {
    if (lazy[node] != 0) {
        segment_tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_segment_tree_indexes(int node, int start, int end, int start_range, int end_range, long long buffer, vector<long long>& segment_tree, vector<long long>& lazy) {
    lazy_update_segment_tree(node, start, end, segment_tree, lazy);
    if (start > end_range || end < start_range) return;
    if (start >= start_range && end <= end_range) {
        segment_tree[node] += (end - start + 1) * buffer;
        if (start != end) {
            lazy[node * 2] += buffer;
            lazy[node * 2 + 1] += buffer;
        }
    } else {
        int mid = (start + end) / 2;
        update_segment_tree_indexes(node * 2, start, mid, start_range, end_range, buffer, segment_tree, lazy);
        update_segment_tree_indexes(node * 2 + 1, mid + 1, end, start_range, end_range, buffer, segment_tree, lazy);
        segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
    }
}

long long count_segment_tree_elements(int node, int start, int end, int start_range, int end_range, vector<long long>& segment_tree, vector<long long>& lazy) {
    lazy_update_segment_tree(node, start, end, segment_tree, lazy);
    if (start_range > end || end_range < start) return 0;
    if (start_range <= start && end_range >= end) return segment_tree[node];
    int mid = (start + end) / 2;
    long long left_res = count_segment_tree_elements(node * 2, start, mid, start_range, end_range, segment_tree, lazy);
    long long right_res = count_segment_tree_elements(node * 2 + 1, mid + 1, end, start_range, end_range, segment_tree, lazy);
    return left_res + right_res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> list(n + 1); // Resize to n + 1 for 1-based index
    vector<long long> segment_tree(n * 4);
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }
    make_segment_tree(1, 1, n, segment_tree, list);
    lazy.resize(n * 4);
    int m;cin>>m;
    for (int i = 0; i < m; i++) {
        int query_identifier; 
        cin >> query_identifier;
        if (query_identifier == 1) {
            long long int b, c, d; 
            cin >> b >> c >> d;
            update_segment_tree_indexes(1, 1, n, b, c, d, segment_tree, lazy);
        } else {
            long long int b;
            cin >> b;
            cout << count_segment_tree_elements(1, 1, n, b, b, segment_tree, lazy) << "\n";
        }
    }
    return 0;
}
