
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return 0;
        unordered_map<char,int> mp;
        unordered_map<char,int> mpp;
        for (char s : s1) mp[s]++;
        int sz1 = s1.size();
        int sz2 = s2.size();
        int l = 0;
        int r = sz1-1;
        for (int i = l; i < r; ++i){
           mpp[s2[i]]++; 
        }
        int cnt = 0;
        //cnt += (mpp == mp);
        for(; r < sz2; ++r){
            mpp[s2[r]]++;
            cnt += (mpp == mp);
            mpp[s2[l]]--;
            if (mpp[s2[l]] == 0)
            mpp.erase(s2[l]);
            ++l;
        }
        return cnt > 0;
    }
};

int main() {

}
