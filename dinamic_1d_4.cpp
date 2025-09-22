//1 dp ��� ������ dp[i] � ������ �������� ����� ������������ ������������ ���������������������
// � ������ �� ������� i ������ ������������� ������������ ��������������������� � ������������������
// ��������� �� ��������� ������� �� i � �� �� ����� ������ ������������������
// 2 ���� ��� ��� ��� ������� �������� ����� �� ���� ��� ��������� ������ ������������ ���������������������
// �� ������ �� ������ (�� �� ������������� ������ �������) dp[0] = 1
// 3 ������� �������� = �������� �� ��������� ��������� �������� dp[i] ������ ���������� ����� 
// ������ ��������� �� ��� ����� ����� �� ������� �������� ������� �������� ����� � ������� �� 
// � �������� dp[j] ������������ + 1(��� ��� ��� ����� dp[i] ���� �� ������ � ������� ���������������������)
// 4 �������� ������ �� �����������
// 5 ����� ��� ������������ ����� ������ ������������ ����� �� ������� dp 
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
