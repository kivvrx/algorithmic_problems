#include<iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
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
// ������� ������ ������� � ���� �� �� ������� ����� ������ � ������ ���� ����� ��� ������� � ���� 
// ����� ��� �� ��� ������� 
using namespace std;

void bfs(int start, const vector<vector<int>>& g, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int to : g[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
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
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int to : g[i]) {
            cout << to << " ";
        }
        cout << "\n";
    }

    int start;
    cin >> start;

    bfs(start, g, visited);

    return 0;
}
