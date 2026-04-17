/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;





int main() {
    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0;
        vector<string> ans;
        if (nums.size() == 0) return ans; 
        for (int r = 0; r < nums.size()-1 ; ++r){
            if (nums[r+1] == nums[r] + 1) {
                l = r;
                while (r < nums.size()-1 && nums[r+1] == nums[r] + 1){
                    ++r;
                }
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]) );
            }
            else {
                l = r;
                ans.push_back(to_string(nums[r]) );
            }
        }
        int r = nums.size()-1;
        if (nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        else if (nums[r] == nums[r-1] + 1){
            ans.pop_back();
            ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
        }
        else ans.push_back(to_string(nums[r]));
        return ans;
    }
};

int main() {
    return 0;
}