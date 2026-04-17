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
using namespace std;


class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        while (q.front() < t - 3000)
            q.pop();

        return q.size();
    }
};

int main (){


    return 0;
}
