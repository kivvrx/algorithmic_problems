// 110001111010100101011110
// удалить один элемент и найти самый большой подмассив 1 
// за O(n^2)
#include <vector>

//int longestSubarray(std::vector<int>& v) {
//    int max_len = 0;
//
//    for (int skip = 0; skip < v.size(); ++skip) {  
//        int current_len = 0;
//        int best_len = 0;
//
//        for (int i = 0; i < v.size(); ++i) {
//            if (i == skip) continue;  
//
//            if (v[i] == 1) {
//                current_len++;
//                best_len = std::max(best_len, current_len);
//            }
//            else {
//                current_len = 0;
//            }
//        }
//
//        max_len = std::max(max_len, best_len);
//    }
//
//    return max_len;
//}

// 11111111
// 00000000
// 1110100011
// 0011
// 1111
// за O(n)

int longestSubarray(std::vector<int>& v) {
	int n = int(v.size());
	int r = 0;
	int cnt = int(v[0]==0);
	int ans = 0;
	for (int l = 0; l < n; ++l) {
		while (r + 1 < n && cnt + (v[r + 1] == 0) < 2) {
			r++;
			cnt += (v[r] == 0);
		}
		ans = std::max(ans, r - l);
		cnt -= (v[l] == 0);
	}
	return ans;
}
