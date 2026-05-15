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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int total = numbers[l] + numbers[r];
            if (total == target) {
                return {l + 1, r + 1};
            } else if (total > target) {
                r--;
            } else {
                l++;
            }
        }
        return {-1, -1};       
    }
};

int main (){


    return 0;
}