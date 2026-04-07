#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    struct Event { long long l, r, x; };
    vector<Event> events(n);
    vector<long long> points(m);

    for (int i = 0; i < n; i++) {
        cin >> events[i].l >> events[i].r >> events[i].x;
    }

    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }


    vector<long long> all;
    all.reserve(3*n + m);

    for (auto &e : events) {
        all.push_back(e.l);
        all.push_back(e.r);
        all.push_back(e.r + 1); 
        all.push_back(e.l + 1); 
    }
    for (auto p : points) all.push_back(p);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto get = [&](long long x) {
        return int(lower_bound(all.begin(), all.end(), x) - all.begin());
    };

    int K = all.size();

    vector<long long> even(K + 5, 0), odd(K + 5, 0);

    for (auto &e : events) {
        long long l = e.l, r = e.r, x = e.x;
        
        int L = get(l);
        int R = get(r);
        int Rp1 = get(r + 1);
        int Lp1 = get(l + 1);

        if (l % 2 == 0) {
            even[L] += x;
            even[Rp1] -= x;

            odd[Lp1] -= x;
            odd[Rp1] += x;
        } else {
            odd[L] += x;
            odd[Rp1] -= x;

            even[Lp1] -= x;
            even[Rp1] += x;
        }
    }

    for (int i = 1; i < K; i++) {
        even[i] += even[i - 1];
        odd[i]  += odd[i - 1];
    }

    for (int i = 0; i < m; i++) {
        long long p = points[i];
        int P = get(p);

        if (p % 2 == 0)
            cout << even[P] << "\n";
        else
            cout << odd[P] << "\n";
    }

    return 0;
}
