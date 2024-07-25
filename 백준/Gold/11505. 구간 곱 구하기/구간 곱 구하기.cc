#include <iostream>
#include <vector>
#define modifier 1000000007
using namespace std;

long long int make_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list) {
    if (start == end) return segment_tree[node] = list[start];

    int mid = (start + end) / 2;
    long long left_res = make_segment_tree(node * 2, start, mid, segment_tree, list)%modifier;
    long long right_res = make_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list)%modifier;
    segment_tree[node] = (left_res * right_res)%modifier;

    return segment_tree[node];
}

long long int multiple_count(int node, int start, int end, int left, int right, vector<long long>& segment_tree, vector<long long>& list) {
    if (left > end || right < start) return 1;  
    if (left <= start && end <= right) return segment_tree[node];
    
    int mid = (start + end) / 2;
    long long left_res = multiple_count(node * 2, start, mid, left, right, segment_tree, list)%modifier;
    long long right_res = multiple_count(node * 2 + 1, mid + 1, end, left, right, segment_tree, list)%modifier;

    return (left_res * right_res)%modifier;
}

void update_segment_tree_index(int node, int start, int end, int index, long long int value, vector<long long>& segment_tree, vector<long long>& list) {
    if (index < start || index > end) return;
    if (start == end) {
        segment_tree[node] = value;
        return;
    }
    
    int mid = (start + end) / 2;
    update_segment_tree_index(node * 2, start, mid, index, value, segment_tree, list);
    update_segment_tree_index(node * 2 + 1, mid + 1, end, index, value, segment_tree, list);
    segment_tree[node] = (segment_tree[node * 2] * segment_tree[node * 2 + 1])%modifier;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> segment_tree(n * 4);
    vector<long long> list(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    make_segment_tree(1, 1, n, segment_tree, list);
    for (int i = 0; i < m + k; i++) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            long long int b, c;
            cin >> b >> c;
            list[b] = c;
            update_segment_tree_index(1, 1, n, b, c, segment_tree, list);
        } else {
            long long int b, c;
            cin >> b >> c;
            cout << multiple_count(1, 1, n, b, c, segment_tree, list) << "\n";
        }
    }

    return 0;
}
