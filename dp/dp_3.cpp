#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
#include <sstream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (size_t i = 1; i <= n; ++i){
            for (size_t j = 1; j*j <= i; ++j){
                dp[i] = min(dp[i],dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};


int main (){


    return 0;
}