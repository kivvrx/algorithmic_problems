#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<int>> gR, gB;
vector<bool> usedR, usedB;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& used) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) dfs(to, g, used);
    }
}

int main() {
    cin >> n;

    gR.assign(n + 1, {});
    gB.assign(n + 1, {});

    for (int i = 1; i <= n - 1; ++i) {
        string s;
        cin >> s;

        for (int j = 1; j <= (int)s.size(); ++j) {
            int to = i + j;      
            char c = s[j - 1]; 

            if (c == 'R') gR[i].push_back(to);
            else gB[i].push_back(to);
        }

    }

    for (int start = 1; start <= n; ++start) {
        usedR.assign(n + 1, false);
        usedB.assign(n + 1, false);

        dfs(start, gR, usedR);
        dfs(start, gB, usedB);

        for (int v = 1; v <= n; ++v) {
            if (v == start) continue;
            if (usedR[v] && usedB[v]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
