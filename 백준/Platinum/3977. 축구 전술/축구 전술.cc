#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

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
    
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> graph(101010);
        vector<vector<int>> graph_rev(101010);
        vector<bool> vis(101010, false); 
        vector<vector<int>> cycle(101010);
        int id = 0, cnt = 0;
        stack<int> st;
        
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph_rev[b].push_back(a);
        }
        
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                DFS(i, vis, graph, st);
            }
        }
        // first DFS
        
        fill(vis.begin(), vis.end(), false); 
        
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            if (!vis[cur]) {
                DFS_rev(cur, vis, graph_rev, cycle, id);
				id++;
            }
        }
        // second DFS
        
		vector<int>indegree(id , 0);
		vector<int>ids(v);

		for(int i = 0;i<id;i++){
			for(int nxt : cycle[i]){
				ids[nxt] = i;
			}
		}
		bool flag = false;
		for(int i = 0; i < v;i++){
			for(int nxt : graph[i]){
				if(ids[nxt] != ids[i]){
					indegree[ids[nxt]]++;
				}
			}
		}
		vector<int>ans;
		int temp = count(indegree.begin(),indegree.end(), 0);
		if(temp > 1 || temp == 0){
			flag = true;
		}
		if(flag){
			cout<<"Confused\n";
		}
		else{
			for(int i = 0;i<id;i++){
				for(int nxt : cycle[i]){
					if(indegree[ids[nxt]] == 0){
						ans.push_back(nxt);
					}
				}
			}
			sort(ans.begin(),ans.end());
			for(int i = 0;i<ans.size();i++){
				cout<<ans[i]<<"\n";
			}
		}
		
		cout<<"\n";

    }

    return 0;
}
