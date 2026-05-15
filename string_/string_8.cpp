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
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        int ans = -1;
        char c = ' ';
        for (int i = 0; i < s.size(); ++i){
            mp[s[i]]++;
        }
        for (int i = 0; i < s.size(); ++i){
            if (mp[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main (){


    return 0;
}