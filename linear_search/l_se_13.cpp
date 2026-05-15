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
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size()<2) return false;
        unordered_map<int, int> mp;
        mp[0]=-1;
        int runningSum=0;
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            if(k!=0) 
                runningSum = runningSum%k;
            if(mp.find(runningSum)!=mp.end())
            {
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
            {
                mp[runningSum]=i;
            }
        }
        return false;
    }
};


int main (){


    return 0;
}