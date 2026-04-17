#include <vector>
#include <string>
#include <algorithm>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        for (auto head : lists) {
            while (head != nullptr) {
                v.push_back(head->val);
                head = head->next;
            }
        }

        if (v.empty()) return nullptr;

        sort(v.begin(), v.end());

        ListNode* head = new ListNode(v[0]);
        ListNode* cur = head;

        for (int i = 1; i < v.size(); ++i) {
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }

        return head;
    }
};

int main (){

}
 