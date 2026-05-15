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
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int n = A.size(), m = B.size();
        int left = 0, right = n;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (n + m + 1) / 2 - i;

            int L1 = (i == 0 ? INT_MIN : A[i - 1]);
            int R1 = (i == n ? INT_MAX : A[i]);
            int L2 = (j == 0 ? INT_MIN : B[j - 1]);
            int R2 = (j == m ? INT_MAX : B[j]);

            if (L1 <= R2 && L2 <= R1) {
                if ((n + m) % 2 == 0)
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                else
                    return max(L1, L2);
            }
            else if (L1 > R2) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};


int main (){


    return 0;
}