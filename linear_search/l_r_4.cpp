#include <iostream>
#include <vector>
#include <string>
using namespace std;


int leng (const vector<int>&  nums){
    int sz = int( nums.size());
    if (sz == 0) return 0;
    int cnt = 0;
    int l = -1, r = -1;
    int mx = 0;
    for (int i = 0; i < sz; ++i){
        if ( nums[i] == 0 && cnt == 0) {            
            l = 0;
            r = i;
            mx = max(mx, i - l);
            cnt++;
        }
        else if ( nums[i] == 0 && cnt == 1){
            l = r;
            r = i;
            mx = max(mx, i - l - 1);
            ++cnt;
        }
        else if ( nums[i] == 0 && cnt == 2){ //cnt = 3
            mx = max(mx, i - l - 1 - 1);
            l = r;
            r = i;
        }
    }
    if (cnt == 0 || cnt == 1) return sz - 1;
    mx = max(mx, sz - r - 1);
    return (mx);
}
int main() {
    int n;
    cin >> n;
    vector<int>  nums(n);
    for (auto& vv :  nums) cin >> vv;
    cout << leng( nums);
    return 0;
}
// l r i
// [0,1,1,1,0,1,1,0,1]
//  0 1 2 3 4 5 6 7 8 
// 0 1 0 1 0
// 0 1 2 3 4 

// 1 1 0 1
