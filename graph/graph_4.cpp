#include <vector>
#include <iostream>

using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& visited, vector<int>& order) {
    visited[v] = true;
    for (int to : g[v]) {
        if (!visited[to]) {
            dfs(to, g, visited, order);
        }
    }
    order.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, g, visited, order);
        }
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
