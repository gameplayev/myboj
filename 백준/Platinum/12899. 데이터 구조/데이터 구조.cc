#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void update_elements_in_segment_tree(int node, int start, int end, int index, int buffer, vector<int>& segment_tree) {
    if(start > index || index > end) return;
    if (start == end) {
        segment_tree[node] += buffer;
        return;
    }
    int mid = (start + end) / 2;
    update_elements_in_segment_tree(node * 2, start, mid, index, buffer, segment_tree);
    update_elements_in_segment_tree(node * 2 + 1, mid + 1, end, index, buffer, segment_tree);
    segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int find_elements_in_segment_tree(int node, int start, int end, int index, vector<int>& segment_tree) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (index <= segment_tree[node * 2]) 
        return find_elements_in_segment_tree(node * 2, start, mid, index, segment_tree);
    else 
        return find_elements_in_segment_tree(node * 2 + 1, mid + 1, end, index - segment_tree[node * 2], segment_tree);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> segment_tree(2000001 * 4, 0);
    int tree_size = 2000001;
    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;
        int x;
        cin >> x;
        if (query == 1) {
            update_elements_in_segment_tree(1, 1, tree_size, x, 1, segment_tree);
        } else {
            int del = find_elements_in_segment_tree(1, 1, tree_size, x, segment_tree);
            cout << del << "\n";
            update_elements_in_segment_tree(1, 1, tree_size, del, -1, segment_tree);
        }
    }
    return 0;
}
