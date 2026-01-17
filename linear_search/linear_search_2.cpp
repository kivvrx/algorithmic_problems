#include <iostream>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	if (n <= 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	std::vector<int> a_v(n);
	for (auto& a_i : a_v) {
		std::cin >> a_i;
	}
	int count = 1;
	int ans = 1;
	for (int i = 1; i < a_v.size(); ++i) {
		if (a_v[i] == a_v[i - 1]) {
			++count;
		}
		else count = 1;
		ans = std::max(ans, count);
	}
	std::cout << ans << std::endl;
	return 0;
}
