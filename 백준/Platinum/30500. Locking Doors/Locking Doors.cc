#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for(auto i : graph[node]) {
        if(!vis[i]) {
            DFS(i, graph, vis, st);
        }
    }
    st.push(node);
}

void DFS_rev(int node, vector<vector<int>>& graph_rev, vector<bool>& vis, vector<vector<int>>& cycle, int id) {
    vis[node] = true;
    cycle[id].push_back(node);
    for(auto i : graph_rev[node]) {
        if(!vis[i]) {
            DFS_rev(i, graph_rev, vis, cycle, id);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e; cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    vector<vector<int>> graph_rev(v + 1);
    vector<bool> vis(v + 1, false);
    vector<vector<int>> cycle(v + 1);
    stack<int> st;
    
    for(int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        graph[a].emplace_back(b);
        graph_rev[b].emplace_back(a);
    }

    // Perform DFS to fill stack
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            DFS(i, graph, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), false);

    int id = 0;
    while(!st.empty()) {
        int cur = st.top(); st.pop();
        if(!vis[cur]) {
            id++;
            DFS_rev(cur, graph_rev, vis, cycle, id);
        }
    }

    vector<int> indegree(id + 1, 0);
    vector<int> ids(v + 1);
    for(int i = 1; i <= id; i++) {
        for(auto nxt : cycle[i]) {
            ids[nxt] = i;
        }
    }

    for(int i = 1; i <= v; i++) {
        for(int nxt : graph[i]) {
            if(ids[nxt] != ids[i]) {
                indegree[ids[nxt]]++;
            }
        }
    }

    int count_zero_indegree = 0;
    for (int i = 1; i <= id; i++) {
        if (indegree[i] == 0) {
            count_zero_indegree++;
        }
    }
   
    cout << count_zero_indegree << endl;

    return 0;
}
