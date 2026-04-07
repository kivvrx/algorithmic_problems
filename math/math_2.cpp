#include <iostream>
#include <climits>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = LLONG_MAX;

    for (long long r = 1; r * r <= n; r++) {

        long long small = n / r;
        long long big = small + 1;
        long long count_big = n % r;
        long long count_small = r - count_big;

        if (count_big == 0) {
            ans = min(ans, llabs(r - small));
        }
        else if (abs(count_big - count_small) <= 1) {
            ans = min(ans, llabs(r - big));
        }
    }

    cout << ans;
    return 0;
}