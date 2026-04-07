#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        sum += d;
    }

    // Для связного графа условие дерева: сумма степеней = 2*(n-1)
    if (sum == 2LL * (n - 1)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
