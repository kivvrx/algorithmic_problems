
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

int main() {
    int x, k;
    std::cin >> x >> k;
    std::set<int> s_k;
    for (int i = 0; i < k; ++i) {
        int kk;
        std::cin >> kk;
        s_k.insert(kk); 
    }

    std::vector<int> dp(x + 1, INT_MAX); 
    dp[0] = 0;  

    for (int i = 1; i <= x; ++i) {
        for (int coin : s_k) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX)
        std::cout << -1 << std::endl;
    else
        std::cout << dp[x] << std::endl;

    return 0;
}
