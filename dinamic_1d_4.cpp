//1 dp это массив dp[i] в каждой хранится длина максимальной возрастающей подпоследовательности
// с концом на позиции i тоесть рассматриваем максимальную подпоследовательность в последовательности
// начальной от начальной позиции до i а не до конца данной последовательности
// 2 база так как для первого элемента слева от него нет элементов значит максимальная подпоследовательность
// от начала до начала (мы же рассматриваем первый элемент) dp[0] = 1
// 3 формула перехода = допустим мы вычисляем следующее значение dp[i] тоесть следующуюю длину 
// значит посмотрим на все левые числа из массива входного меньшие текущего числа и выберем то 
// у которого dp[j] максимальное + 1(так как это число dp[i] тоже же входит в текущую подпослежовательность)
// 4 поряддок обхода по возрастанию
// 5 ответ это максимальная длина значит максимальное число из массива dp 
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    std::vector<int> dp(n, 1);
    std::vector<int> parent(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j; 
            }
        }
    }

    auto it = std::max_element(dp.begin(), dp.end());
    int ans = *it;
    int idx = std::distance(dp.begin(), it);

    std::vector<int> indices;
    for (int cur = idx; cur != -1; cur = parent[cur]) {
        indices.push_back(cur);
    }
    std::reverse(indices.begin(), indices.end());

    std::cout << ans << "\n";
    for (int id : indices) std::cout << id + 1 << ' ';
    std::cout << "\n";
}
