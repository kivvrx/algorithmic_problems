#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long K1, M, K2, P2, N2;
    cin >> K1 >> M >> K2 >> P2 >> N2;

    if (P2 < 1 || N2 < 1 || N2 > M) {
        cout << "-1 -1";
        return 0;
    }

    long long L = 1;
    long long R = 1000000000;

    // Подъездное ограничение
    if (P2 > 1) {
        long long t = (K2 - 1) / (M * (P2 - 1)) + 1;
        L = max(L, t);
    }
    {
        long long t = (K2 + M * P2 - 1) / (M * P2);
        L = max(L, t);
    }

    // Этажное ограничение
    long long A = (P2 - 1) * M + (N2 - 1);
    if (A > 0) {
        long long t = (K2 - 1) / A;
        R = min(R, t);
    }

    long long B = (P2 - 1) * M + N2;
    {
        long long t = (K2 + B - 1) / B;
        L = max(L, t);
    }

    if (L > R) {
        cout << "-1 -1";
        return 0;
    }

    auto calcPN = [&](long long x) {
        long long perEntrance = x * M;
        long long P1 = (K1 + perEntrance - 1) / perEntrance;
        long long offset = K1 - perEntrance * (P1 - 1);
        long long N1 = (offset + x - 1) / x;
        return pair<long long,long long>(P1, N1);
    };

    if (L == R) {
        auto [P1, N1] = calcPN(L);
        cout << P1 << " " << N1;
        return 0;
    }

    auto [P1L, N1L] = calcPN(L);
    auto [P1R, N1R] = calcPN(R);

    long long ansP = (P1L == P1R ? P1L : 0);
    long long ansN = (N1L == N1R ? N1L : 0);

    cout << ansP << " " << ansN;
    return 0;
}
