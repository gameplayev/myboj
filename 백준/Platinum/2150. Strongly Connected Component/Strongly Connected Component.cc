#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a.empty() || b.empty()) return false;
    return (a[0] < b[0]);
}

void DFS(int x, vector<bool>& vis, vector<vector<int>>& graph, stack<int>& st) {
    vis[x] = true;
    for (int i : graph[x]) {
        if (!vis[i]) {
            DFS(i, vis, graph, st);
        }
    }
    st.push(x);
}

void DFS_rev(int x, vector<bool>& vis, vector<vector<int>>& graph_rev, vector<vector<int>>& cycle, int id) {
    vis[x] = true;
    cycle[id].emplace_back(x);
    for (int i : graph_rev[x]) {
        if (!vis[i]) {
            DFS_rev(i, vis, graph_rev, cycle, id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v + 1);
    vector<vector<int>> graph_rev(v + 1);
    vector<bool> vis(v + 1, false);
    vector<vector<int>> cycle(v + 1);
    int id = 0;
    stack<int> st;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        if (a > 0 && a <= v && b > 0 && b <= v) {
            graph[a].push_back(b);
            graph_rev[b].push_back(a);
        }
    }

    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            DFS(i, vis, graph, st);
        }
    }
    // First DFS

    fill(vis.begin(), vis.end(), false);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (!vis[cur]) {
            DFS_rev(cur, vis, graph_rev, cycle, id);
            id++;
        }
    }
    // Second DFS

    cout << id << "\n";
    for (int i = 0; i < id; i++) {
        sort(cycle[i].begin(), cycle[i].end());
    }
    cycle.resize(id);
    sort(cycle.begin(), cycle.end(), cmp);

    for (int i = 0; i < id; i++) {
        if (!cycle[i].empty()) {
            for (auto j : cycle[i]) {
                cout << j << " ";
            }
            cout << "-1\n";
        }
    }

    return 0;
}
