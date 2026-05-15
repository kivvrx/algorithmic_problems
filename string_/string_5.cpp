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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int mx = 0;
        int l = 0, r = 0;
        int n = s.size();

        while (r < n) {
            if (mp[s[r]] > 0) {
                while (s[l] != s[r]) {
                    mp[s[l]]--;
                    ++l;
                }
                mp[s[l]]--;
                ++l;
            }

            mp[s[r]]++;
            mx = max(mx, r - l + 1);
            ++r;
        }

        return mx;
    }
};

/*



abcabcbb 




*/


int main (){


    return 0;
}