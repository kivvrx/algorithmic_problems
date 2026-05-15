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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        for (auto n : nums1) mp[n]++;
        for (auto n : nums2) {
            if (mp[n] > 0) 
            {
                res.push_back(n);
                mp[n]--;
            }
        }
        return res;
    }
};

int main (){


    return 0;
}
