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
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& t : tokens) {

            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();

                int res = 0;
                if (t == "+") res = x + y;
                else if (t == "-") res = x - y;
                else if (t == "*") res = x * y;
                else res = x / y;

                st.push(res);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};


int main (){

    return 0;
}
