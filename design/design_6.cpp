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


  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
     // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
     // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
 


  // Your NestedIterator object will be instantiated and called as such:
  // NestedIterator i(nestedList);
  // while (i.hasNext()) cout << i.next();
 

class NestedIterator {

    vector<int> v;
    int idx = 0;
    void go_v (vector<NestedInteger> &nestedList){
        for (const auto vv : nestedList){
            if (vv.isInteger()) v.push_back(vv.getInteger());
            else go_v(vv.getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        go_v(nestedList);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};
// [[1,1],2,[1,1]] -> [1,1,2,1,1]

int main (){


    return 0;
}

