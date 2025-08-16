#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now(); 


    int n = 11, m = 20;
    vector<int> N = { 0, 7, 7, 5, 20, 8, 7, 8, 20, 20, 5, 5, };

    /* место ввода с консоли:
    int n, m;
    cin >> n >> m;
    vector<int> N(n+1);

    for (int i = 1; i < N.size(); ++i) {
        int N_i;
        cin >> N_i;
        N[i] = N_i;
    }
    */

    vector<tuple<int, int, int>> color_left_right;

    for (int l = 1; l < N.size(); ++l) {
        int target_value = N[l];
        int r = l;

        size_t found_index = -1;
        for (size_t i = 0; i < color_left_right.size(); ++i) {
            if (get<0>(color_left_right[i]) == target_value) {
                found_index = i;
                break;
            }
        }

        if (found_index == -1) {
            color_left_right.emplace_back(target_value, l, r);
            found_index = color_left_right.size() - 1;
        }

        while (r != N.size()) {
            if (N[r] == N[l]) get<2>(color_left_right[found_index]) = r;
            ++r;
        }
    }

    set<int> check_color;
    for (int i = 0; i < color_left_right.size(); ++i) {
        if (m < N[i]) { cout << -1; return 0; }
        int l = get<1>(color_left_right[i]);
        int r = get<2>(color_left_right[i]);
        check_color.insert(N[l]);
        for (auto j = l; j <= r; ++j) {
            if (check_color.count(N[j]) && N[j] != N[l]) { cout << -1;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);


            double seconds = duration.count() / 1000000.0;
            cerr << "Execution time: " << seconds << " seconds" << endl; 
            return 0; 
            }
        }
    }

    for (int c = 0; c < color_left_right.size(); ++c) {
        cout << get<0>(color_left_right[c]) << " " << get<1>(color_left_right[c]) << " "
            << get<2>(color_left_right[c]) << endl;
    }

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 


    double seconds = duration.count() / 1000000.0;
    cerr << "Execution time: " << seconds << " seconds" << endl;

    return 0;
}

//
//const int NEW = 0;
//const int OPEN = 1;
//const int CLOSE = 2;
//
//struct colour
//{
//	int right_border, left_border, state;
//
//	colour(int _right_border, int _left_border, int _state)
//		: right_border(_right_border), left_border(_left_border), state(_state)
//	{
//	}
//
//	colour() = default;
//};
//
//map<int, colour> colours;
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//
//	vector<int> colours_line;
//	for (int i = 0; i < m; i++)
//	{
//		int c;
//		cin >> c;
//		colours_line.push_back(c - 1);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		auto colour_id = colours_line[i];
//		if (colours.count(colour_id) == 0)
//			colours[colour_id] = colour(-1, INT32_MAX, NEW);
//
//		if (i < colours[colour_id].left_border)
//			colours[colour_id].left_border = i;
//		if (i > colours[colour_id].right_border)
//			colours[colour_id].right_border = i;
//	}
//
//	stack<int> stack;
//	vector<int> colours_ids;
//	for (int i = 0; i < m; i++)
//	{
//		auto colour_id = colours_line[i];
//		switch (colours[colour_id].state)
//		{
//		case NEW:
//			stack.push(i);
//			colours[colour_id].state = OPEN;
//			break;
//		case OPEN:
//		{
//			while (colours_line[stack.top()] != colour_id)
//			{
//				colours_ids.push_back(colours_line[stack.top()]);
//				colours[colours_line[stack.top()]].state = CLOSE;
//				stack.pop();
//			}
//
//			break;
//		}
//		case CLOSE:
//			cout << -1 << endl;
//			return 0;
//		}
//	}
//
//	while (!stack.empty())
//	{
//		colours_ids.push_back(colours_line[stack.top()]);
//		stack.pop();
//	}
//
//	cout << colours_ids.size() << endl;
//	reverse(colours_ids.begin(), colours_ids.end());
//	for (auto colour_id : colours_ids)
//	{
//		cout << colour_id + 1 << " " << colours[colour_id].left_border + 1 << " " << colours[colour_id].right_border + 1 << endl;
//	}
//
//	return 0;
//}