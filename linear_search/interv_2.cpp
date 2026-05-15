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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int l = 0, r = 0;
        vector<vector<int>> ans;
        int lsz = static_cast<int>(firstList.size()) , rsz = static_cast<int>(secondList.size());
        while (l < lsz && r < rsz){
            int ll = firstList[l][0];
            int lr = firstList[l][1];
            int rl = secondList[r][0];
            int rr = secondList[r][1];
            int mxl = max(ll, rl);
            int mnr = min(lr,rr);
            if (mxl <= mnr) ans.push_back({mxl,mnr});
            if (lr < rr) ++l;
            else ++r;
        }
        return ans;
    }
};


int main (){


    return 0;
}