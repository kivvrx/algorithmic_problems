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
    string simplifyPath(string path) {
        vector<string> st;
        string t;
        stringstream ss(path);
        while (getline(ss, t, '/')) {
            if (t.empty() || t == ".") continue;
            if (t == "..") {
                if (!st.empty()) st.pop_back();
            } else st.push_back(t);
        }
        string res = "/";
        for (int i = 0; i < st.size(); ++i) {
            res += st[i];
            if (i + 1 < st.size()) res += "/";
        }
        return res;
    }
};


int main (){


    return 0;
}
