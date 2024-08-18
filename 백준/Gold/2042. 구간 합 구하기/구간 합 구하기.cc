#include <bits/stdc++.h>
using namespace std;

//funcs define
long long config_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list);
void update_segment_tree_elements(int node, int start, int end, long long index, long long diff, vector<long long>& segment_tree);
long long count_elements_in_segment_tree(int node, int start, int end, long long left, long long right, vector<long long>& segment_tree);

//main logic
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long int> segment_tree(n * 4);
    vector<long long int> list(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    config_segment_tree(1, 1, n, segment_tree, list);

    //handle qurey
    for (int i = 0; i < m + k; i++) {
        short qurey;
        cin >> qurey;

        if (qurey == 1) {
            long long int a, b;
            cin >> a >> b;
            long long int diff = b - list[a];
            list[a] = b;
            update_segment_tree_elements(1, 1, n, a, diff, segment_tree);
        } else {
            long long a, b;
            cin >> a >> b;
            cout << count_elements_in_segment_tree(1, 1, n, a, b, segment_tree) << "\n";
        }
    }

    return 0;
}

//funcs (backend)
long long config_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list) {
    if (start == end) {
        segment_tree[node] = list[start];
        return segment_tree[node];
    }

    int mid = (start + end) / 2;
    long long left = config_segment_tree(node * 2, start, mid, segment_tree, list);
    long long right = config_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list);

    return segment_tree[node] = left + right;
}

void update_segment_tree_elements(int node, int start, int end, long long index, long long diff, vector<long long>& segment_tree) {
    if (index < start || end < index) return;

    segment_tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update_segment_tree_elements(node * 2, start, mid, index, diff, segment_tree);
        update_segment_tree_elements(node * 2 + 1, mid + 1, end, index, diff, segment_tree);
    }
}

long long count_elements_in_segment_tree(int node, int start, int end, long long left, long long right, vector<long long>& segment_tree) {
    if (left > end || right < start) {
        return 0;
    }

    if (start >= left && end <= right) {
        return segment_tree[node];
    }

    int mid = (start + end) / 2;
    long long l = count_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree);
    long long r = count_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree);

    return l + r;
}
