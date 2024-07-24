#include <bits/stdc++.h>
using namespace std;

void lazy_update_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& lazy) {
    if (lazy[node] % 2 == 1) {
        segment_tree[node] = (end - start + 1) - segment_tree[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<long long>& segment_tree, vector<long long>& lazy) {
    lazy_update_segment_tree(node, start, end, segment_tree, lazy);
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        segment_tree[node] = (end - start + 1) - segment_tree[node];
        if (start != end) {
            lazy[node * 2] += 1;
            lazy[node * 2 + 1] += 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree, lazy);
    update_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree, lazy);
    segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

long long count_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<long long>& segment_tree, vector<long long>& lazy) {
    lazy_update_segment_tree(node, start, end, segment_tree, lazy);
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return segment_tree[node];
    int mid = (start + end) / 2;
    return count_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree, lazy) +
           count_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree, lazy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> segment_tree(n * 4);
    vector<long long> lazy(n * 4);
    for (int i = 0; i < m; i++) {
        int qur,a,b;
        cin >> qur>>a>>b;
        if (qur == 0) {
            
            update_elements_in_segment_tree(1, 1, n, a, b, segment_tree, lazy);
        } else {
          
            cout << count_elements_in_segment_tree(1, 1, n, a, b, segment_tree, lazy) <<"\n";
        }
    }
    return 0;
}
