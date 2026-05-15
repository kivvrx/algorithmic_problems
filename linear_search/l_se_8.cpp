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
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return (nums[0] == 1? 0 : 1);
        sort(nums.begin(), nums.end());
        int check = -1;
        for (int i = 1; i < nums.size(); ++i){
            if (abs(nums[i]-nums[i-1]) != 1) {
                check = nums[i] - 1;
                break;
            }
        }
        return (check != -1? check : (nums[0] == 0? nums.size() : 0));
    }
};

int main (){


    return 0;
}
