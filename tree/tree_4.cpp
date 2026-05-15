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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        unordered_set<Node*> visited;

        Node* cur = p;
        while (cur != nullptr) {
            visited.insert(cur);
            cur = cur->parent;
        }

        cur = q;
        while (cur != nullptr) {
            if (visited.count(cur)) return cur;
            cur = cur->parent;
        }

        return nullptr;
    }
};

int main() {

}