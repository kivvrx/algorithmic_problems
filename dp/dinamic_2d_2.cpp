
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> A[i];

    int m;
    std::cin >> m;
    std::vector<int> B(m + 1);
    for (int j = 1; j <= m; j++) std::cin >> B[j];

    std::vector<std::vector<int>> table(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
            if (A[i] == B[j]) {
                table[i][j] = std::max(table[i][j], table[i - 1][j - 1] + 1);
            }
        }
    }

    int i = n, j = m;
    std::vector<int> idxA; 
    std::vector<int> idxB; 

    while (i > 0 && j > 0) {
        if (A[i] == B[j] && table[i][j] == table[i - 1][j - 1] + 1) {
            idxA.push_back(i);
            idxB.push_back(j);
            i--; j--;
        }
        else if (table[i - 1][j] >= table[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }


    std::reverse(idxA.begin(), idxA.end());
    std::reverse(idxB.begin(), idxB.end());


    std::cout << "LCS length = " << table[n][m] << "\n";
    std::cout << "Indices in A: ";
    for (int id : idxA) std::cout << id << " ";
    std::cout << "\nIndices in B: ";
    for (int id : idxB) std::cout << id << " ";
    std::cout << "\n";

    return 0;
}

