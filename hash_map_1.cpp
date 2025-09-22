//2
//Aztec Tenochtitlan Tetzcoco Tlacopan
//Inca Cusco Chan-Chan Tiwanaku
//3
//Cusco
//Tenochtitlan
//Chan-Chan
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N;
    // ОЧЕНЬ ВАЖНО: очищаем буфер после чтения N
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::unordered_map<std::string, std::string> city_country;
    std::string line;

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss{line};
        std::string country;
        iss >> country;
        std::string city;

        while (iss >> city) {
            city_country[city] = country;
        }
    }

    std::cin >> M;
    std::vector<std::string> requests(M);
    for (auto& r : requests) {
        std::cin >> r;
    }

    std::vector<std::string> answers(M);
    for (int i = 0; i < M; ++i) {
        auto it = city_country.find(requests[i]);
        if (it != city_country.end()) {
            answers[i] = it->second;
        }
        else {
            answers[i] = "Unknown";
        }
    }

    for (const auto& a : answers) {
        std::cout << a << std::endl;
    }

    return 0;
}