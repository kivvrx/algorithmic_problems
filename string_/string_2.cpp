#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        if (chars.size() == 0) return 0;

        int r = 1;
        int l = 0;
        int cnt = 0;

        while (r < chars.size()){

            if (chars[r] == chars[r-1]){
                l = r - 1;
                while (r < chars.size() && chars[r] == chars[r-1]){
                    ++r;
                }
                cnt = r - l;

                string nums = to_string(cnt);
                int sz = nums.size();

                for (int i = 0; i < sz; ++i){
                    chars[l+1+i] = nums[i];
                }

                l = l + 1 + sz;
                for (int i = l; i < r; ++i){
                    chars[i] = '\1';
                }
            }
            ++r;
        }

        int i = 0;
        while (i < chars.size()) {
            if (chars[i] == '\1') {
                chars.erase(chars.begin() + i);
            }
            else {
                i++;
            }
        }

        return chars.size();
    }
};


// a b b b b b b b 
// 0 1 2 3 4 5 6 7
int main() {
    return 0;
}