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
    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '1') {
                    cnt++;
                    dfs(g, i, j);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& g, int i, int j) {
        int n = g.size(), m = g[0].size();
        stack<pair<int,int>> st;
        st.push({i, j});

        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();

            if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] != '1')
                continue;

            g[x][y] = '0';

            st.push({x+1, y});
            st.push({x-1, y});
            st.push({x, y+1});
            st.push({x, y-1});
        }
    }
};



int main (){


    return 0;
}