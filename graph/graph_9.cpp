#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int start, const vector<vector<int>>& g, vector<bool>& used, vector<int>& comp) {
    queue<int> q;
    used[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        comp.push_back(v);

        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<bool> used(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> comps;

    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            vector<int> comp;
            bfs(v, g, used, comp);
            sort(comp.begin(), comp.end());
            comps.push_back(comp);
        }
    }

    sort(comps.begin(), comps.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
         });

    cout << comps.size() << "\n";
    for (const auto& comp : comps) {
        for (int x : comp) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}















/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& used, vector<int>& comp) {
    used[v] = true;
    comp.push_back(v);

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, g, used, comp);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<bool> used(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> comps;

    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            vector<int> comp;
            dfs(v, g, used, comp);
            sort(comp.begin(), comp.end());
            comps.push_back(comp);
        }
    }

    sort(comps.begin(), comps.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
         });

    cout << comps.size() << "\n";
    for (const auto& comp : comps) {
        for (int x : comp) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
*/