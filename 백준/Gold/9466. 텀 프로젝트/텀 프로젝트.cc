#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for (auto& nxt : graph[node]) {
        if (!vis[nxt]) {
            DFS(nxt, graph, vis, st);
        }
    }
    st.emplace(node);
}

void DFS_rev(int node, vector<vector<int>>& graph_rev, vector<bool>& vis, vector<vector<int>>& cycle, int id) {
    vis[node] = true;
    cycle[id].emplace_back(node);
    for (auto& nxt : graph_rev[node]) {
        if (!vis[nxt]) {
            DFS_rev(nxt, graph_rev, vis, cycle, id);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n + 1);
        vector<vector<int>> graph_rev(n + 1);
        vector<bool> vis(n + 1, false);
        vector<vector<int>> cycle(n + 1);
        vector<bool> hasSelfLoop(n + 1, false);
        stack<int> st;

        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            graph[i].emplace_back(a);
            graph_rev[a].emplace_back(i);
            if (i == a) {
                hasSelfLoop[i] = true;  // Mark self-loop nodes
            }
        }

        
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                DFS(i, graph, vis, st);
            }
        }

        
        fill(vis.begin(), vis.end(), false);
        int id = 1;

        
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            if (!vis[cur]) {
                DFS_rev(cur, graph_rev, vis, cycle, id);
                id++;
            }
        }

        
        int result = 0;
        for (int i = 1; i < id; i++) {
            if (cycle[i].size() == 1) {
                int cur = cycle[i][0];
                if (!hasSelfLoop[cur]) {
                    result++;
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}
