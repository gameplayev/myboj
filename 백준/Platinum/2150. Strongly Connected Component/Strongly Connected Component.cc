#include <bits/stdc++.h>
using namespace std;

// Correct comparator function to compare vectors based on their first element
bool cmp(const vector<int>& left, const vector<int>& right) {
    if(left.empty()) return false;  // Assume empty vectors go last
    if(right.empty()) return true;
    return left[0] < right[0];
}

vector<int> graph[101010];
vector<int> graph_rev[101010];
stack<int> st;
vector<int> cycle[101010];
int v, e, cnt = 0;
bool vis[101010] = {false,};

void DFS(int x) {
    vis[x] = true;
    for(int i : graph[x]) {
        if(!vis[i]) {
            DFS(i);
        }
    }
    st.push(x);
}

void DFS_rev(int x, int id) {
    vis[x] = true;
    cycle[id].push_back(x);
    for(int i : graph_rev[x]) {
        if(!vis[i]) {
            DFS_rev(i, id);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph_rev[b].push_back(a);
    }
    
    // Run DFS from all nodes to ensure we consider disconnected parts of the graph
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }

    memset(vis, false, sizeof(vis));
    
    // Run DFS on the reversed graph to find strongly connected components
    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        if (!vis[cur]) {
            cnt++;
            DFS_rev(cur, cnt);
        }
    }
    
    cout << cnt << "\n";
    // Sort each SCC vector
    for(int i = 1; i <= cnt; i++){
        sort(cycle[i].begin(), cycle[i].end());
    }
    
    // Sort the array of vectors (SCCs) using the custom comparator
    sort(cycle + 1, cycle + cnt + 1, cmp);
    
    // Print the sorted SCCs
    for (int i = 1; i <= cnt; i++) {
        for(int j : cycle[i]) {
            cout << j << " ";
        }
        cout << "-1\n";
    }
    
    return 0;
}
	
