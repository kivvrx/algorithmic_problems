// есть дерево, бинарное, тоесть у каждой вершины не более двух потомков
//        z
//		/    \
//   a			c
//	/  \
//b	 v
//
#include <utility> 
#include <iostream>
#include <map>

using namespace std;

struct TNode {
	 char Value; // [A-Z]
	 TNode * left;
	 TNode * right;
	
};



 int Go(TNode * root, map<int, pair<TNode*, TNode*>> &st) {
	 if (root == NULL) return 0;
	// 00000000 00000000 00000000 0000000
	 // a-z 
		 int ans = (1 << (root->Value - 'A')); 
		 //// 00000000 00000000 00000010 0000000 допустим стало вот так 
		 //        z
		//		/    \
		//   a			c
// 
// 			a → 97
//		    z → 122
//			A → 65
//			Z → 90
		 // get the answer for child nodes
		 ans |= Go(root->left, st); //    a  ans =  ans | (Go(root->left, st) -> Go(адрес a,st) -> 0 ) 
	     ans |= Go(root->right, st);  // c  ans =  ans | (Go(root->right, st) -> )
	
		 // update the answer for current mask
		 if (st[ans].first == NULL) st[ans].first = root;
	     else if (st[ans].second == NULL) st[ans].second = root;
	
		 return ans;
	
}

 pair<TNode*, TNode*> FindEquivalentSubtrees(TNode* root) {
	 map<int, pair<TNode*, TNode*>> st;
	 int res = Go(root, st);
	
		 // find & return the answer
		 pair<TNode*, TNode*> ans;
	 for (auto& x : st) {
		 if (x.second.first != NULL && x.second.second != NULL) {
			 ans = x.second;
			 break;
			
		}
		
	}
	 return ans;

}

int main() {
	TNode* root = new TNode{ 'Z' };
	root->left = new TNode{ 'A' };
	root->right = new TNode{ 'C' };
	auto ans = FindEquivalentSubtrees(root);
	std::cout << ans.first << ' ' << ans.second;
}
