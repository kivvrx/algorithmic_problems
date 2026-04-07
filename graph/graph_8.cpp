#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> deg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
            deg[u]++;
            deg[v]++;
    }

    for (int v = 1; v <= n; v++) {
        if (deg[v] < n - 1) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
