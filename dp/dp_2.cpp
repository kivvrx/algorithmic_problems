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



    int maxDistToClosest(vector<int> seats) {
        int sz = int(seats.size());
        vector<int> left(sz,0);
        vector<int> right(sz,0);

        for (int i = 0; i < sz; ++i){
            if (seats[i] == 1) {
                left[i] = 0;
            } else {
                left[i] = (i > 0 ? left[i-1] + !((seats[i-1] == 0 && left[i-1] == 0)) : 0);
            }
        }

        for (int j = sz-1; j > -1; --j){
            if (seats[j] == 1) {
                right[j] = 0;
            } else {
                right[j] = (j < sz-1 ? right[j+1] + !((seats[j+1] == 0 && right[j+1] == 0)) : 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < sz; ++i){
            if (seats[i] == 0){
                auto l = (left[i] == 0? right[i] + 1 : left[i]);
                auto r = (right[i] == 0? left[i] + 1 : right[i]); 
                int dist = min(l, r);
                ans = max(ans, dist);
            }
        }

        return ans;
    }


int main (){
    maxDistToClosest({1,0,0,0});
    
    return 0;
}
