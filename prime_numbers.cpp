#include <algorithm>
#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
//Любое целое число n можно представить в одном из 6 видов:
//6k - делится на 6
//6k +- 1 - возможные простые числа
//6k +- 2 - делится на 2
//6k + 3 - делится на 3
//Пусть n составное => n = a × b, где 1 < a <= b < n
//Предположим, что a > √n и b > √n
//Тогда n = a × b > √n × √n = n ⇒ n > n неверно 
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;      
    if (n % 2 == 0) return false; 
    if (n % 3 == 0) return false; 

    // Проверяем делители вида 6k +- 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;       // 6k - 1
        if (n % (i + 2) == 0) return false; // 6k + 1
    }

    return true;
}
// 
std::pair<int,std::vector<int>> sum_proper_divisors(int const number)
{
    std::vector<int> multipliers = { 1 };
    int result = 1;
    for (int i = 2; i <= std::sqrt(number); i++)
    {
        if (number % i == 0)
        {
            if (i == (number / i)) {
               multipliers.push_back(i);
               result += i;
            }
            else {
                multipliers.push_back(i);
                multipliers.push_back(number / i);
                result += i + number / i;
            }
        }
    }
    std::sort(multipliers.begin(), multipliers.end());
    return std::make_pair(result,multipliers);
}

void print_abundant(int const limit)
{
    for (int number = 1; number <= limit; ++number)
    {
        auto sum = sum_proper_divisors(number);
        if (sum.first > number)  
        {
            std::cout << number << " is abundant, sum=" << sum.first
                << ", divisors: ";
            for (int div : sum.second) {
                std::cout << div << " ";
            }
            std::cout << std::endl;
        }
    }
}
//Если n – простое число, большее 2, шаги выше не приведут к превращению n в 1. 
//Следовательно, если в конце шага 2 число n остается больше 2,
//значит, оно является простым множителем
std::vector<int> prime_factors(int a) {
    std::vector<int> factors;
    while (a % 2 == 0) {
        factors.push_back(a);
        a = a / 2;
    }
    for (int i = 3; i <= std::sqrt(a); i += 2) {
        while (a % i == 0) {
            factors.push_back(i);
            a = a / i;
        }
    }
    if (a > 2) {
        factors.push_back(a);
    }
    return factors;
}

int main() {
    int a;
    std::cin >> a;
    print_abundant(a);
    return 0;
}