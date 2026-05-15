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
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int idx = -1;
        int n = int(nums.size() - 1);
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                idx = i;
                break;
            }
        }

        int l, r;
        if (idx == -1) {
            ans.push_back(nums[n] * nums[n]);
            l = n - 1;
            r = n + 1;
        } else {
            ans.push_back(nums[idx] * nums[idx]);
            l = idx - 1;
            r = idx + 1;
        }

        while (l >= 0 || r <= n) {
            if (l >= 0 && (r > n || nums[l]*nums[l] <= nums[r]*nums[r])) {
                ans.push_back(nums[l]*nums[l]);
                --l;
            } else if (r <= n) {
                ans.push_back(nums[r]*nums[r]);
                ++r;
            }
        }
        l = 0;
        r = 1;
        while (ans.size()-1 >= r && ans[l] > ans[r]) {
            swap(ans[l],ans[r]);
            ++l;
            ++r;
        }
        return ans;
    }
};

int main (){


    return 0;
}