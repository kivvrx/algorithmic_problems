#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;
vector<int> g[MAXN + 1], gt[MAXN + 1];
vector<bool> used;
vector<int> order;

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            dfs1(to);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    for (int to : gt[v])
        if (!used[to])
            dfs2(to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    used.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n + 1, false);
    reverse(order.begin(), order.end());

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
