#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order;

void dfs1(int v) {        
    used[v] = true;
    for (int to : gt[v]) {
        if (!used[to]) dfs1(to);
    }
    order.push_back(v);    
}

void dfs2(int v) {           
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) dfs2(to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    gt.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
        gt[v].push_back(u);  
    }

    used.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!used[i]) dfs1(i);
    }


    reverse(order.begin(), order.end());

    used.assign(n + 1, false);

    int comp = 0;
    for (int v : order) {
        if (!used[v]) {
            dfs2(v);
            comp++;
        }
    }

    if (comp == 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
