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
// 64345341
class MaxStack {
    list<int> lst; 
    map<int, vector<list<int>::iterator>> mp;
public:
    MaxStack() {}

    void push(int x) {
        lst.push_back(x);
        mp[x].push_back(prev(lst.end()));
    }

    int pop() {
        int x = lst.back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        lst.pop_back();
        return x;
    }

    int top() {
        return lst.back();
    }

    int peekMax() {
        return mp.rbegin()->first; 
    }

    int popMax() {
        int maxKey = mp.rbegin()->first;
        auto it = mp[maxKey].back(); 
        mp[maxKey].pop_back();
        if (mp[maxKey].empty()) mp.erase(maxKey);
        lst.erase(it);
        return maxKey;
    }
};

int main (){


    return 0;
}