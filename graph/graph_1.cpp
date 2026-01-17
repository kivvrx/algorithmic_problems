#include<iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
/*                                                                            
1 - 2 - 3
   \        |
     \      |
       \    |
         \  |
            4

 
 
4 3
2 3
4 3
1 2
3
*/

void dfs(int v, const vector<vector<int>>& g, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int to : g[v]) {
        if (!visited[to]) {
            dfs(to, g, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    int start;
    cin >> start;

    dfs(start, g, visited);

    return 0;
}
