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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m - 1;
        int mm = m - 1;
        int nn = n - 1;
        while (nn >= 0){
            if (mm >= 0 && nums1[mm] > nums2[nn]){
                nums1[k--] = nums1[mm--];
            }
            else nums1[k--] = nums2[nn--];

        }
    }
};


int main (){


    return 0;
}