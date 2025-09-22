// 1 dp[i][j] матрица где каждый элемент это минимальное число изменений для получения одинаковых слов 
// в обоих строках
// 2 база это число букв в первой строке и столбце если бы мы добавлями по одной букве 
// тоесть если в первой строке нет букв то при увеличении другой мы будем добавлять по одному изменению
// неважно какому
// 3 если буквы равны ничего не делаем берем предыдущее вычисление без этих букв 
// а если буквы не равны тут 3 ситуации нужно объяснить почему именно такой расчет
// у нас есть 3 пути от клетки чтобы посомтреть что было до 
// влево вверх и по диагонали вверх влево 
//Рассмотрим клетку [i][j] — мы хотим превратить первые i букв S в первые j букв T.
// i ПО ВЕРТИКАЛИ j ПО ГОРИЗОНТАЛИ важно сказать что в t мы никогда ничего не меняем мы просто смотрим
// на то как выглядит t
// 1) удаление из s (мы все действия рассматриваем с s строкой) было i букв стало i-1, в t ничего не меняем
// значит после удаления у нас стало i-1 букв в s и j букв в t
// теперь думаем где было такое состояние такое состояние было сверху от текущей клетки 
// dp[i-1][j] но надо еще прибавить + 1 так как удаление это операция 
// 2) вставка в s было i букв стало i+1 букв в s, в t также ничего не меняем 
// после вставки i+1 букв в s и j букв в t но заметим что одна буква уже точно обработана которую мы вставили
// поэтому можно ее уже не рассматривать она уже рассмотрена мы ее уже вставили мы просто добавим +1 
// к клетке в dp значит если эта бууква рассмотрена то надо рассмотреть лишь случай поменьше и прибавить
//  +1 а этот случай это i и j-1 (еще раз повторю потому что то что мы вставили уже учитывается она уже не нужна
// для рассмотрения на данном шаге)
// 3) замена было i остало тоже i а j так и осталось это значит мы уже рассмотрели заменненную букву учтем ее
// как +1 в dp значит расссмотрим если бы ее не было так как мы уже поняли что это замена то значит это
// i-1 и j-1 потому что +1 учтена как замена а значит осталось прибавить к единице то что было вычислено без нее
// 4 идем опять же по строке сверху вниз и по столбцам слева направо
// 5 ответ это когда у нас все буквы рассмотрены и в первом и во втором строке тоесть это самая нижняя по диа
// гонали справа клетка
//abacaba
//abaabc
//innokentiy
//innnokkentia
//r
//x
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

enum Operation {
    MATCH,     
    DELETE,     
    INSERT,     
    REPLACE     
};

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    int m = t.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    std::vector<std::vector<Operation>> parent(n + 1, std::vector<Operation>(m + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
        if (i > 0) parent[i][0] = DELETE;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
        if (j > 0) parent[0][j] = INSERT;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                parent[i][j] = MATCH;
            }
            else {
                int delete_cost = dp[i - 1][j] + 1;
                int insert_cost = dp[i][j - 1] + 1;
                int replace_cost = dp[i - 1][j - 1] + 1;

                dp[i][j] = std::min({ delete_cost, insert_cost, replace_cost });

                if (dp[i][j] == delete_cost) {
                    parent[i][j] = DELETE;
                }
                else if (dp[i][j] == insert_cost) {
                    parent[i][j] = INSERT;
                }
                else {
                    parent[i][j] = REPLACE;
                }
            }
        }
    }

    std::cout << "DP table:\n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j)
            std::cout << dp[i][j] << ' ';
        std::cout << std::endl;
    }

    std::cout << "\nMinimum number of operations: " << dp[n][m] << "\n\n";

    std::stack<std::string> operations;
    int i = n, j = m;

    while (i > 0 || j > 0) {
        switch (parent[i][j]) {
        case MATCH:
            operations.push("Match: '" + std::string(1, s[i - 1]) +
                "' and '" + std::string(1, t[j - 1]) + "'");
            i--;
            j--;
            break;

        case DELETE:
            operations.push("Delete: '" + std::string(1, s[i - 1]) + "'");
            i--;
            break;

        case INSERT:
            operations.push("Insert: '" + std::string(1, t[j - 1]) + "'");
            j--;
            break;

        case REPLACE:
            operations.push("Replace: '" + std::string(1, s[i - 1]) +
                "' with '" + std::string(1, t[j - 1]) + "'");
            i--;
            j--;
            break;
        }
    }

    std::cout << "Sequence of operations:\n";
    int step = 1;
    while (!operations.empty()) {
        std::cout << step++ << ") " << operations.top() << std::endl;
        operations.pop();
    }

    return 0;
}