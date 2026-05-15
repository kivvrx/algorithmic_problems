struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto cur = head;
        int sz = 0;
        while (cur){
            ++sz;
            cur = cur->next;
        }
        if (sz == 0 || sz == 1) return nullptr;
        auto prev = head;
        cur = head->next;
        auto nxt = cur->next;
        ListNode* ans = new ListNode();
        if (n == sz) return cur;
        int cnt = 0;
        while (cur){
            ++cnt;
            if (n == (sz-cnt)){
                prev->next = nxt;
                ans = head;
                break;
            }
            prev = cur;
            cur = nxt;
            nxt = (nxt? nxt->next : nullptr);
        }
        return ans;
    }
};


int main (){


    return 0;
}
