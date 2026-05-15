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

  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool symmetric (TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && (symmetric(left->left, right->right)) && (symmetric(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symmetric(root->left, root->right);
    }
};


int main (){


    return 0;
}