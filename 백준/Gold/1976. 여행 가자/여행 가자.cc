#include <iostream>
#include <vector>
using namespace std;

int par[101010];
int n, m;
vector<vector<int>> graph;

void init(int x) {
    for (int i = 1; i <= x; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) par[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    graph.resize(n + 1, vector<int>(n + 1, 0));
    init(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int identifier; cin >> identifier;
            if (identifier) {
                graph[i][j] = 1;
                unite(i, j);
            }
        }
    }

    vector<int> rout(m);
    for (int i = 0; i < m; i++) {
        cin >> rout[i];
    }

    string ans = "YES";
    for (int i = 1; i < m; i++) {
        if (find(rout[i - 1]) != find(rout[i])) {
            ans = "NO";
            break;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
