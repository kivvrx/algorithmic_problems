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


class MyQueue {
    stack<int,vector<int>> end;
    stack<int,vector<int>> start;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        auto startcop = start;
        start = stack<int,vector<int>>{};
        vector<int> cop; 
        while (!startcop.empty()) {
            cop.push_back(startcop.top());
            startcop.pop();
        }
        start.push(x);
        for (int i = (int)cop.size() - 1; i >= 0; i--) {
            start.push(cop[i]);
        }
        end.push(x);
    }
    
    int pop() {
        int x = start.top();  
        start.pop();           
        return x;
    }
    
    int peek() {
        return start.top(); 
    }
    
    bool empty() {
        return start.empty();
    }
};



int main (){


    return 0;
}