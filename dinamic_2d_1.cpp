// 1 dp матрица dp[i][j] максимально возможное число цветков которое можно собрать добравшись до 
// участка (i,j)
// 2 база это dp[0][0] = matrix[0][0]
// 3 в каждую клетку допустим [i][j] можно прийти либо снизу тоесть из [i-1][j] либо слева тоесть из
// [i][j-1]
// формула перехода dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + matrix[i][j]
// 4 чтобы вычислить очередное значение нужно знать что слева и снизу от элемента это получится
// если обходить матрицу сначала по строкам потом по столбцам тоесть сверху вниз слева направо
// 5 в ячейке (n-1,m-1) ответ (если представить что координаты матрица начинаются с левого нижнего угла)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    const long long NEG_INF = LLONG_MIN / 4;
    vector<vector<long long>> a(n + 2, vector<long long>(m + 2, NEG_INF));
    // 101
    // каждая строка вводится как строка цифр
    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = row[j - 1] - '0'; // преобразуем символ в число
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2, NEG_INF));
    dp[n][1] = a[n][1];

    // Заполнение DP таблицы
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i == n && j == 1) continue;
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[1][m] << "\n";

    int i = 1, j = m;
    vector<pair<int, int>> path;
    path.push_back({ 1, m }); // добавляем начальную точку
    vector<char> go;

    while (!(i == n && j == 1)) {
        long long fromLeft = dp[i][j - 1];
        long long fromDown = dp[i + 1][j];

        if (fromLeft >= fromDown) {
            --j; // идём влево
            go.push_back('R');
        }
        else {
            ++i; // идём вниз
            go.push_back('U');
        }
        path.push_back({ i, j });
    }
    std::reverse(go.begin(), go.end());
    // Вывод пути
    cout << path.size() << "\n";
    for (auto [r, c] : path) {
        cout << r << " " << c << "\n";
    }
    for (auto g : go) {
        std::cout << g;
    }
    std::cout << std::endl;
    return 0;
}