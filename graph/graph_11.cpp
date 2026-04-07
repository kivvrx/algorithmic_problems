#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> tin, tout;
vector<bool> used;
int timer = 0;

void dfs(int v) {
    used[v] = true;
    tin[v] = timer++; 

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }

    tout[v] = timer++; 
}

int main() {
    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    used.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << tin[i] << " " << tout[i] << "\n";
    }

    return 0;
}
