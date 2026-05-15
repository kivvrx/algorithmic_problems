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
#include <sstream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = 0;
        int i = 0 , j = 0;
        if (s.size() == 0 && t.size() == 0) return 1;
        if (s.size() == 0) return 1;
        while (i < s.size() && j < t.size()){
            if (s[i] == t[j]){
                ss++;
                i++;
                if (ss == s.size()) return 1;
            }
            j++;
        }
        return 0;
    }
};


int main (){


    return 0;
}