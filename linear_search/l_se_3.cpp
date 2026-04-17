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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i){
            vector<int> cur = intervals[i];
            vector<int> & last = ans.back();
            if (cur [0] <= last[1]){
                last[1] = max(last[1],cur[1]);
            }
            else ans.push_back(cur);
        }
        return ans;
    }
};

int main (){


    return 0;
}
