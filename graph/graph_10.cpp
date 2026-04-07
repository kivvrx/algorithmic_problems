#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs_exit(int v, const vector<vector<int>>& gt, vector<bool>& used, vector<int>& order) {
    cout << "dfs_exit: вошли в " << v << "\n";
    used[v] = true;

    for (int to : gt[v]) {
        cout << "  смотрим ребро " << v << " -> " << to << " в G^T\n";
        if (!used[to]) {
            cout << "    идём в " << to << "\n";
            dfs_exit(to, gt, used, order);
        } else {
            cout << "    " << to << " уже посещена\n";
        }
    }

    cout << "dfs_exit: выходим из " << v << " (добавляем в order)\n";
    order.push_back(v);
}

void dfs_collect(int v, const vector<vector<int>>& g, vector<bool>& used, vector<int>& comp) {
    cout << "dfs_collect: вошли в " << v << "\n";
    used[v] = true;
    comp.push_back(v);

    for (int to : g[v]) {
        cout << "  смотрим ребро " << v << " -> " << to << " в G\n";
        if (!used[to]) {
            cout << "    идём в " << to << "\n";
            dfs_collect(to, g, used, comp);
        } else {
            cout << "    " << to << " уже посещена\n";
        }
    }

    cout << "dfs_collect: выходим из " << v << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<vector<int>> gt(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    cout << "\n=== Исходный граф G ===\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int to : g[i]) cout << to << " ";
        cout << "\n";
    }

    cout << "\n=== Транспонированный граф G^T ===\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int to : gt[i]) cout << to << " ";
        cout << "\n";
    }

    vector<bool> used(n + 1, false);
    vector<int> order;

    cout << "\n=== Шаг 1: DFS на G^T (сбор времени выхода) ===\n";
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            cout << "\nЗапускаем dfs_exit из " << v << "\n";
            dfs_exit(v, gt, used, order);
        }
    }

    cout << "\nПорядок выхода (order): ";
    for (int x : order) cout << x << " ";
    cout << "\n";

    fill(used.begin(), used.end(), false);
    vector<vector<int>> comps;

    cout << "\n=== Шаг 2: DFS на G в порядке убывания order ===\n";
    cout << "Порядок обхода: ";
    for (int i = (int)order.size() - 1; i >= 0; i--) cout << order[i] << " ";
    cout << "\n\n";

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int v = order[i];
        if (!used[v]) {
            cout << "\nЗапускаем dfs_collect из " << v << "\n";
            vector<int> comp;
            dfs_collect(v, g, used, comp);

            cout << "Найдена компонента (до сортировки): ";
            for (int x : comp) cout << x << " ";
            cout << "\n";

            sort(comp.begin(), comp.end());
            comps.push_back(comp);
        }
    }

    cout << "\n=== Компоненты после сортировки внутри ===\n";
    for (auto& comp : comps) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    sort(comps.begin(), comps.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
         });

    cout << "\n=== Компоненты после финальной сортировки ===\n";
    for (auto& comp : comps) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== Итог ===\n";
    cout << comps.size() << "\n";
    for (auto& comp : comps) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
