//4 4
//1 2 1
//2 3 3
//3 4 5
//1 4 2
//1 ---- - 2
// |            |
// |            |
//4 ---- - 3
//0: (1, 1) (3, 2)
//1 : (0, 1) (2, 3)
//2 : (1, 3) (3, 5)
//3 : (2, 5) (0, 2)
// основная идея в том что мы берем по одной вершине и прогоняем пути до всех остальных вершин от этой
// ищем минимальные пути затем делаем тоже самое уже с другой вершины таким образом матрица
// смежности будет заполнена 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

struct Edge {
    int to, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v; 
        adj[u].push_back({ v, d });
        adj[v].push_back({ u, d }); // граф неориентированный
    }

    // список смежности
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto e : adj[i]) {
            cout << "(" << e.to << "," << e.w << ") ";
        }
        cout << "\n";
    }
    cout << "\n";

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int s = 0; s < n; s++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[s][s] = 0;
        pq.push({ 0, s });

        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();

            cout << "pop " << v << " " << d << "\n";

            if (d > dist[s][v]) continue;

            for (auto [to, w] : adj[v]) {
// без приоритетной очереди тоесть если взять обычную то 
// если запустить алгоритм видно что происходит намного больше лишних проверок тоесть 
// в обычную очередь кладется много лишних проверок которых не было бы если использовать приоритетную
// с приоритетной очередью каждая вершина обрабатывается один раз 
                cout << "edge " << v << "->" << to << " w=" << w
                    << " dist=" << dist[s][to]
                    << " new=" << dist[s][v] + w << "\n";

                if (dist[s][to] > dist[s][v] + w) {
                    dist[s][to] = dist[s][v] + w;
                    pq.push({ dist[s][to], to });
                    cout << "update " << to << " " << dist[s][to] << "\n";
                }
                cout << "\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][j] == INF) cout << -1 << " ";
                        else cout << dist[i][j] << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }

    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}



//const int INF = 1e9;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<int>> dist(n, vector<int>(n, INF));
//
//    // расстояние до себя = 0
//    for (int i = 0; i < n; i++) dist[i][i] = 0;
//
//    // читаем рёбра
//    for (int i = 0; i < m; i++) {
//        int u, v, d;
//        cin >> u >> v >> d;
//        --u; --v; // переводим в 0-индексацию
//        dist[u][v] = min(dist[u][v], d); // так как кратные ребра могут быть ищем минимальный путь 
//        dist[v][u] = min(dist[v][u], d); // граф неориентированный
//    }
//
//    // алгоритм Флойда–Уоршелла
//    for (int k = 0; k < n; k++) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (dist[i][k] < INF && dist[k][j] < INF)
//                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//            }
//        }
//    }
//
//    // вывод матрицы
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (dist[i][j] == INF) cout << -1 << " ";
//            else cout << dist[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}

