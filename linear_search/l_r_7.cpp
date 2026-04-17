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
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= left_max)
                    left_max = height[l];
                else
                    ans += left_max - height[l];
                l++;
            } else {
                if (height[r] >= right_max)
                    right_max = height[r];
                else
                    ans += right_max - height[r];
                r--;
            }
        }

        return ans;
    }
};
/*


             |
 |           |
||           |
------------------------------




*/



int main (){


    return 0;
}
