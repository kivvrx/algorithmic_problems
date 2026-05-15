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
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto l1 = list1;
        auto l2 = list2;

        vector<int> v1, v2;

        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        int n = v1.size();
        int m = v2.size();

        while (m > 0) {
            v1.push_back(0);
            --m;
        }
        m = v2.size();
        int i = n - 1;        
        int j = m - 1;        
        int k = n + m - 1;    

        while (j >= 0) {
            if (i >= 0 && v1[i] > v2[j]) {
                v1[k--] = v1[i--];
            } else {
                v1[k--] = v2[j--];
            }
        }

        ListNode* head = new ListNode();
        ListNode* cur = head;

        for (int t = 0; t < v1.size(); t++) {
            cur->next = new ListNode(v1[t]);
            cur = cur->next;
        }

        return head;
    }
};

// 1 2 5
// 2 8
//

int main (){


    return 0;
}