#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int N = 1 << n;
    const int START = 0;
    const int INF_NEG = -1e9;

    
    vector<vector<int>> dp(N, vector<int>(n, INF_NEG));
    dp[1 << START][START] = a[START];

    int ans = a[START];

    for (int mask = 0; mask < N; ++mask) {
        if (((mask >> START) & 1) == 0) continue; 
        for (int v = 0; v < n; ++v) {
            int cur = dp[mask][v];
            if (cur == INF_NEG) continue;
            ans = max(ans, cur);
            for (int u : adj[v]) {
                if ((mask >> u) & 1) continue; 
                int nmask = mask | (1 << u);
                dp[nmask][u] = max(dp[nmask][u], cur + a[u]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
