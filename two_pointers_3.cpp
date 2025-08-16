#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//1 3 
//2    4

int check(vector<int> houses, vector<int> heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    
    int ans = 0;
    int heater_idx = 0;
    
    for (int h = 0; h < houses.size(); ++h) {
        while (heater_idx < heaters.size() - 1 && heaters[heater_idx + 1] <= houses[h]) ++heater_idx;
        int left = abs(houses[h] - heaters[heater_idx]);
        int min_dist = left;
        if (heater_idx + 1 < heaters.size()) {
           min_dist = min(left, abs(houses[h] - heaters[heater_idx + 1]));
        }
        ans = max(ans, min_dist);
    }
    
    return ans;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> n_v(n), m_v(m);
	for (auto& nn : n_v) cin >> nn;
	for (auto& mm : m_v) cin >> mm;
	cout << check(n_v, m_v);
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main ()
{
	string temp;
	getline(cin, temp);
	vector<int> houses;
	vector<int> heaters;

	int n;
	while (cin >> n)
	{
		houses.push_back(n);
		if (cin.peek() == '\n')
			break;
	}
	while (cin >> n)
	{
		heaters.push_back(n);
		if (cin.peek() == '\n')
			break;
	}

	vector<int> min_radius(houses.size(), numeric_limits<int>::max());

	int j = 0;
	int k = 0;

	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());

	while (j < houses.size())
	{
		min_radius[j] = min(min_radius[j], abs(houses[j] - heaters[k]));

		if (k > 0)
			min_radius[j] = min(min_radius[j], abs(houses[j] - heaters[k - 1]));

		if (heaters[k] < houses[j] && k < heaters.size() - 1)
			k++;
		else
			j++;
	}

	cout << *max_element(min_radius.begin(), min_radius.end()) << endl;

	return 0;
}
*/