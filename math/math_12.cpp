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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* ans = new ListNode{};
        ListNode* cur = ans;

        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int s = x + y + carry;
            carry = s / 10;

            cur->val = s % 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if (l1 || l2 || carry) {
                cur->next = new ListNode{};
                cur = cur->next;
            }
        }

        return ans;
    }
};


int main (){


    return 0;
}