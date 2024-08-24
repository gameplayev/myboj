#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1010][1010] = {};
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
int res = -1;

void BFS(int y, int x) {
    bool vis[1010][1010][2] = {};
    queue<tuple<int, int, int, bool>> q;
    vis[y][x][0] = true;
    q.emplace(y, x, 1, false);
    
    while (!q.empty()) {
        int curx = get<1>(q.front());
        int cury = get<0>(q.front());
        int cost = get<2>(q.front());
        bool walls = get<3>(q.front());
        q.pop();
        
        if (curx == m - 1 && cury == n - 1) {
            res = cost;
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int cx = curx + dx[i];
            int cy = cury + dy[i];
            if (cx >= m || cx < 0 || cy >= n || cy < 0) continue;
            
            if (grid[cy][cx] == 1 && !walls && !vis[cy][cx][1]) {
                vis[cy][cx][1] = true;
                q.emplace(cy, cx, cost + 1, true);
            }
            else if (grid[cy][cx] == 0 && !vis[cy][cx][walls]) {
                vis[cy][cx][walls] = true;
                q.emplace(cy, cx, cost + 1, walls);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (int)s[j] - 48;
        }
    }
    
    BFS(0, 0);
    if(res == -1){
        cout<<"-1\n";
    }
    else{
        cout<<res<<"\n";
    }
    
    return 0;
}
