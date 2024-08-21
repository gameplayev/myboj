#include <bits/stdc++.h>
using namespace std;

struct qur1 {
    int i, j;
};

struct qur2 {
    int k, i, j;
    int seq;
    long long ans;
};

long long config_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list);
void update_elements_in_segment_tree(int node, int start, int end, int index, long long buffer, vector<long long>& segment_tree);
long long count_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<long long>& segment_tree);
bool cmp(qur2& a, qur2& b);
bool com(qur2& a, qur2& b);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> list(n + 1);
    vector<long long> segment_tree(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    int m;
    cin >> m;

    config_segment_tree(1, 1, n, segment_tree, list);

    vector<qur1> qurey1(1); 
    vector<qur2> qurey2;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            qur1 d;
            d.i = b;
            d.j = c;
            qurey1.emplace_back(d);
        } else {
            int b, c, d;
            cin >> b >> c >> d;
            qur2 e;
            e.k = b;
            e.i = c;
            e.j = d;
            e.seq = i;
            e.ans = -1;
            qurey2.emplace_back(e);
        }
    }

    sort(qurey2.begin(), qurey2.end(), cmp);

    int stack = 0;
    for (auto& nxt : qurey2) {
        while (stack < nxt.k) {
            stack++;
            qur1 c = qurey1[stack];
            long long diff = c.j - list[c.i];
            update_elements_in_segment_tree(1, 1, n, c.i, diff, segment_tree);
            list[c.i] = c.j;
        }
        nxt.ans = count_elements_in_segment_tree(1, 1, n, nxt.i, nxt.j, segment_tree);
    }

    sort(qurey2.begin(), qurey2.end(), com);

    for (const auto& nxt : qurey2) {
        cout << nxt.ans << "\n";
    }

    return 0;
}

long long config_segment_tree(int node, int start, int end, vector<long long>& segment_tree, vector<long long>& list) {
    if (start == end) {
        return segment_tree[node] = list[start];
    }
    int mid = (start + end) / 2;
    long long left = config_segment_tree(node * 2, start, mid, segment_tree, list);
    long long right = config_segment_tree(node * 2 + 1, mid + 1, end, segment_tree, list);
    return segment_tree[node] = left + right;  // Fixed the incorrect addition
}

void update_elements_in_segment_tree(int node, int start, int end, int index, long long buffer, vector<long long>& segment_tree) {
    if (start > index || index > end) return;
    segment_tree[node] += buffer;
    if (start != end) {
        int mid = (start + end) / 2;
        update_elements_in_segment_tree(node * 2, start, mid, index, buffer, segment_tree);
        update_elements_in_segment_tree(node * 2 + 1, mid + 1, end, index, buffer, segment_tree);
    }
}

long long count_elements_in_segment_tree(int node, int start, int end, int left, int right, vector<long long>& segment_tree) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    long long l = count_elements_in_segment_tree(node * 2, start, mid, left, right, segment_tree);
    long long r = count_elements_in_segment_tree(node * 2 + 1, mid + 1, end, left, right, segment_tree);
    return l + r;
}

bool cmp(qur2& a, qur2& b) {
    return a.k < b.k;
}

bool com(qur2& a, qur2& b) {
    return a.seq < b.seq;
}
