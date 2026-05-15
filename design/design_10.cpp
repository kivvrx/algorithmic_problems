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
    bool isPalindrome(ListNode* head) {
        int sz = 0;
        auto h = head;
        while (h) {
            ++sz;
            h = h->next;
        }
        if (sz == 1 || sz == 0) return true;

        int mid = sz / 2;
        ListNode* cur = head;
        for (int i = 0; i < mid; ++i) cur = cur->next;
        if (sz % 2 != 0) cur = cur->next;

        ListNode* prev = nullptr;
        while (cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};



int main (){


    return 0;
}