#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {    
        stack<char> q;
        for (char c : s){
            if(c == '(' || c == '[' || c == '{'){
                q.push(c);
            }
            else {
                if (q.empty()) return false;
                if (q.top() == (c == ')'? c-1 : c-2)) q.pop();
                else return false;
            }
        }
        return q.size() == 0;
    }
};

int main (){

}