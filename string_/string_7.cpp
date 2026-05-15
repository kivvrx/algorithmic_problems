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
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        for (int i = 0; i < s.size(); ++i){
            if (isspace(s[i])){
                r = i - 1;
                while (l < r){
                    auto ll = s[l];
                    auto rr = s[r];
                    s[l] = rr;
                    s[r] = ll;
                    ++l;
                    --r;
                }
                l = i + 1;
            }
        }
        r = s.size()-1;
           while (l < r){
                    auto ll = s[l];
                    auto rr = s[r];
                    s[l] = rr;
                    s[r] = ll;
                    ++l;
                    --r;
                }
        return s;
    }
};


int main (){


    return 0;
}