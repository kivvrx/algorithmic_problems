//
//{2, 3, 5, 7, 11}, index = 2, k = 2) -> {3, 5} {5, 7}
//			 |
//          
// k > size то пустой вектор 
// k < 1 то пустой вектор 

#include <vector>
#include <iostream>

std::vector<int> find_k_closest(const std::vector<int>& a, size_t index, size_t k) 
{
	if (a.empty() || k < static_cast<size_t>(1) || k > a.size() || index < static_cast<size_t>(0) || index > a.size()-1) {
		return std::vector<int>();
	}

	std::vector<int> res;
	res.reserve(k);
	int count = 0;
	int n = a.size(); // например индексов до 6 а размер  7
	int l = int(index), r = l + 1;

	while (count != k) {
		if (r >= n) {
			res.push_back(a[l]);
			--l;
			++count;
			continue;
		}
		if (l < 0) {
			res.push_back(a[r]);
			++r;
			++count;
			continue;
		}
		// -5     -4    -3  -2 -1
		//           l		  i		 r          i=index 
		const auto& i = index;
		if (abs((a[r]) - (a[i])) <= abs((a[l]) - (a[i]))) {
			res.push_back(a[r]);
			++r;
			++count;
		}
		else {
			res.push_back(a[l]);
			--l;
			++count;
		}
	}
	
	return res;

}

int main() {
	auto a = find_k_closest({ 1 }, 1, 1);
	for (const auto& f : a) {
		std::cout << f << std::endl;
	}
}