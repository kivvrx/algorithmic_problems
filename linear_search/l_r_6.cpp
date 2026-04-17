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
// 101010110101010111

int chec (vector<int> v){
    int sz = int(v.size());
    if (sz == 0) return 0;
    if (sz == 1) return 1;

    int l = 0;
    int r = 0;
    int cnt = 0;
    int mx = -1;

    while (r < sz){
        cnt += (v[r] == 0);

        if (cnt > 1){
            while (l < sz && cnt > 1){
                cnt -= v[l] == 0;
                ++l;
            }
        }

        mx = max(mx, r - l + 1);
        ++r;
    }

    return mx;
}

// 0 1 1 1 0 1 1 1 0
// 0 1 2 3 4 5 
int main() {
}
