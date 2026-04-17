#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> ans;

    void dfs(string cur, int open, int close, int n) {
        if ((int)cur.size() == 2*n) {
            ans.push_back(cur);
            return;
        }

        if (open < n)
            dfs(cur + "(", open + 1, close, n);

        if (close < open)
            dfs(cur + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return ans;
    }
};

int main (){
    Solution* s = new Solution();
    s->generateParenthesis(3);
    return 0;
}