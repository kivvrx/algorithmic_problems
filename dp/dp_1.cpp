
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    cnt[0] = 1; // сумма 0 встречается один раз (перед началом массива)

    int cur = 0;
    int ans = 0;

    for (int x : nums) {
        cur += x;

        if (cnt.count(cur - k))
            ans += cnt[cur - k];

        cnt[cur]++;
    }

    return ans;
}


int main() {
    return 0;
}


/*

  0 1 2 3 
0 1          
1   1          
2     1      
3       1    

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
        if (dp[i][i] == k) ans++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + nums[j];
            if (dp[i][j] == k) ans++;
        }
    }

    return ans;
}


*/