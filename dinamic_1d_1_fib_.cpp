#include <iostream>
#include <iomanip>
#include <vector>
int fib(int n) {
    std::vector<int> a(n+1);
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int fib_recursive(int n, std::vector<int>& a) {
    if (a[n] == -1)
        a[n] = fib_recursive(n - 1, a) + fib_recursive(n - 2, a);
    return a[n];
}


int main() {
    int max_int = 2147483647;
    double as_double = max_int;
    std::cout << std::scientific << as_double << std::endl;
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, -1);
    a[0] = a[1] = 1;
    auto aa = fib_recursive(n, a);
    std::cout << aa;
    return 0;
}