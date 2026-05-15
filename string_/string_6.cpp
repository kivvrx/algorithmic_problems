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
    int check (int l, int r, string s){
        int rr = r, ll = l;
        while (l <= r){
            if (s[l] != s[r]) return 0;
            --r;
            ++l;
        }
        return r - l + 1;
    }
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        int l = 0, r = static_cast<int>(s.size()) - 1;
        int mx = 0;
        string ans ={};
        while (l <= r){
            for (int rr = r; rr >= l; --rr){
                int mxx = max(mx, check(l, rr, s));
                if (mxx > mx) {
                    mx = mxx;
                    ans = s.substr(l,mx);
                } 
            }
        }
        return ans;
    }
};

int main (){


    return 0;
}
