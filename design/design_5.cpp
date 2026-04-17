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



class HitCounter {
    queue<int> q;
public:
    HitCounter() {}

    void hit(int timestamp) {
        q.push(timestamp);
    }

    int getHits(int timestamp) {
        int limit = timestamp - 300;
        while (!q.empty() && q.front() <= limit)
            q.pop();
        return q.size();
    }
};

// 400 - 300 = 100 

int main (){


    return 0;
}
