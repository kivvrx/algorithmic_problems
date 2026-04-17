#include <vector>
#include <string>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr){
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }
        return prev;
    };
};
int main (){

}
 
/*

1 2 3 4 5 
2 1 3 4 5
2 3 1 4 5
2 3 4 1 5








*/