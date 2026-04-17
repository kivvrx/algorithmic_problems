#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
    int sz = s.size();
    if (sz == 0) return false;
    if (sz == 1 || sz == 2) return true; 
    int l = 0, r = sz - 1;

    int cnt = 0;
    while (l < r){
        if (s[l] != s[r]){
            ++cnt;
            if (cnt > 1) return false;
            bool is_l = (s[l+1] == s[r]? 1 : 0);
            bool is_r = (s[r-1] == s[l]? 1 : 0);
            if (!is_l && !is_r) return false;
            string t1 = s.substr(l+1, r-l);
            string t2 = s.substr(l, r-l);
            string tt1 = t1;
            string tt2 = t2;
            reverse(tt1.begin(), tt1.end());
            reverse(tt2.begin(), tt2.end());
            return (t1 == tt1 || t2 == tt2);
        }
        --r;
        ++l;
    }
    return true;
    }
};
int main() {
    Solution* s = new Solution{};
    s->validPalindrome({"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"});
    return 0;          //01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
}                      //0         1        |2         3         4         5         6         7         8|        9         10                                                  