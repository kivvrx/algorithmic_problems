// 1 dp[i][j] ������� ��� ������ ������� ��� ����������� ����� ��������� ��� ��������� ���������� ���� 
// � ����� �������
// 2 ���� ��� ����� ���� � ������ ������ � ������� ���� �� �� ��������� �� ����� ����� 
// ������ ���� � ������ ������ ��� ���� �� ��� ���������� ������ �� ����� ��������� �� ������ ���������
// ������� ������
// 3 ���� ����� ����� ������ �� ������ ����� ���������� ���������� ��� ���� ���� 
// � ���� ����� �� ����� ��� 3 �������� ����� ��������� ������ ������ ����� ������
// � ��� ���� 3 ���� �� ������ ����� ���������� ��� ���� �� 
// ����� ����� � �� ��������� ����� ����� 
//���������� ������ [i][j] � �� ����� ���������� ������ i ���� S � ������ j ���� T.
// i �� ��������� j �� ����������� ����� ������� ��� � t �� ������� ������ �� ������ �� ������ �������
// �� �� ��� �������� t
// 1) �������� �� s (�� ��� �������� ������������� � s �������) ���� i ���� ����� i-1, � t ������ �� ������
// ������ ����� �������� � ��� ����� i-1 ���� � s � j ���� � t
// ������ ������ ��� ���� ����� ��������� ����� ��������� ���� ������ �� ������� ������ 
// dp[i-1][j] �� ���� ��� ��������� + 1 ��� ��� �������� ��� �������� 
// 2) ������� � s ���� i ���� ����� i+1 ���� � s, � t ����� ������ �� ������ 
// ����� ������� i+1 ���� � s � j ���� � t �� ������� ��� ���� ����� ��� ����� ���������� ������� �� ��������
// ������� ����� �� ��� �� ������������� ��� ��� ����������� �� �� ��� �������� �� ������ ������� +1 
// � ������ � dp ������ ���� ��� ������ ����������� �� ���� ����������� ���� ������ �������� � ���������
//  +1 � ���� ������ ��� i � j-1 (��� ��� ������� ������ ��� �� ��� �� �������� ��� ����������� ��� ��� �� �����
// ��� ������������ �� ������ ����)
// 3) ������ ���� i ������ ���� i � j ��� � �������� ��� ������ �� ��� ����������� ����������� ����� ����� ��
// ��� +1 � dp ������ ����������� ���� �� �� �� ���� ��� ��� �� ��� ������ ��� ��� ������ �� ������ ���
// i-1 � j-1 ������ ��� +1 ������ ��� ������ � ������ �������� ��������� � ������� �� ��� ���� ��������� ��� ���
// 4 ���� ����� �� �� ������ ������ ���� � �� �������� ����� �������
// 5 ����� ��� ����� � ��� ��� ����� ����������� � � ������ � �� ������ ������ ������ ��� ����� ������ �� ���
// ������ ������ ������
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