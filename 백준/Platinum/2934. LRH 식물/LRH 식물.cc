#include <iostream>
#include <vector>
using namespace std;

void handle_lazy_propagation_algorithm_in_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& lazy) {
    if (lazy[node]) {
        segment_tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long find_height_in_segment_tree(int node, int start, int end, int index, vector<long long>& segment_tree, vector<long long>& lazy) {
    handle_lazy_propagation_algorithm_in_segment_tree(node, start, end, segment_tree, lazy);
    if (end < index || start > index) return 0;
    if (start == end) return segment_tree[node];
    int mid = (start + end) / 2;
    return find_height_in_segment_tree(node * 2, start, mid, index, segment_tree, lazy) + find_height_in_segment_tree(node * 2 + 1, mid + 1, end, index, segment_tree, lazy);
}

void update_height_values_in_segment_tree(int node, int start, int end, int left, int right, long long buffer, vector<long long>& segment_tree, vector<long long>& lazy) {
    handle_lazy_propagation_algorithm_in_segment_tree(node, start, end, segment_tree, lazy);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        lazy[node] += buffer;
        handle_lazy_propagation_algorithm_in_segment_tree(node, start, end, segment_tree, lazy);
        return;
    }
    int mid = (start + end) / 2;
    update_height_values_in_segment_tree(node * 2, start, mid, left, right, buffer, segment_tree, lazy);
    update_height_values_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, buffer, segment_tree, lazy);
    segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int MAX = 100000;
    vector<long long> segment_tree(4 * MAX, 0);
    vector<long long> lazy(4 * MAX, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        long long left = find_height_in_segment_tree(1, 1, MAX, l, segment_tree, lazy);
        long long right = find_height_in_segment_tree(1, 1, MAX, r, segment_tree, lazy);
        cout << left + right << "\n";

        update_height_values_in_segment_tree(1, 1, MAX, l, l, -left, segment_tree, lazy);
        update_height_values_in_segment_tree(1, 1, MAX, r, r, -right, segment_tree, lazy);
        update_height_values_in_segment_tree(1, 1, MAX, l + 1, r - 1, 1, segment_tree, lazy);
    }

    return 0;
}
