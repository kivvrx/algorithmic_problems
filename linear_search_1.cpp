#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
// 52 карты 4 масти 13 достоинств одно достоинство 4 карты другое тоже 4 карты и так 13 достоинств
// каждое достоинство по 4 карты(масти) 1*4 + 1*4 + 1*4 = 4(1+...+1) = 4*13 
// 2 колоды найти вероятность выигрыша  
//основная идея что надо проверять все карты потому что они разные везде комбинации разные
// выгрыш основывается на том сколько выгрышных карт остается после удаления а выигрышные карты это 
// карты которые записаны в s строках для первого и второго игрока соответсвенно 
// тоесть выигрыш = (число выигрышных карт тоесть тех что подходят к любой из s строк)/(число не удаленных)
using namespace std;
const unordered_set<char> all_suits = { 'C', 'D', 'H', 'S' };
const unordered_set<char> all_ranks = { '2', '3' ,'4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

vector<string> read(int size) {
	vector<string> cards;
	cards.reserve(size);
	string card;
	for (int i = 0; i < size; ++i) {
		cin >> card;
		cards.push_back(card);
	}
	return cards;
}

bool check_card(const string& cardset, const char& suit, const char& rank) { 
	unordered_set<char> suits;
	unordered_set<char> ranks;
	for (const auto& char_set : cardset) {
		if (all_suits.count(char_set)) suits.insert(char_set);
		else ranks.insert(char_set);
	}
	if (suits.empty()) suits = all_suits;
	if (ranks.empty()) ranks = all_ranks;

	return (suits.count(suit) != 0) && (ranks.count(rank) != 0);
}

bool check_cards(const vector<string>& cardsets, const char& suit, const char& rank) {
	for (const auto& card : cardsets) {
		if (check_card(card, suit, rank))	 return true;
	}
	return false;
}

double calculate_probability(const vector<string>& del, const vector<string>& win) {
	auto count_not_removed = 0;
	auto count_not_removed_win = 0;

	for (const auto& suit : all_suits )
		for (const auto& rank : all_ranks) {
			if (!check_cards(del, suit, rank)) {
				count_not_removed++;
				if (check_cards(win, suit, rank)) count_not_removed_win++;
			}
		}

	return count_not_removed == 0? 0.0 : count_not_removed_win/(double)count_not_removed;
}


int main() {
	int r1, r2, s1, s2;
	cin >> r1 >> s1 >> r2 >> s2;
	auto del1 = read(r1);
	auto win1 = read(s1);
	auto del2 = read(r2);
	auto win2 = read(s2);

	auto p1 = calculate_probability(del1, win1);
	auto p2 = calculate_probability(del2, win2);
	cout << max(p1,p2);

	return 0;
}
//bool matches(const std::string& card, const std::string& subset) {
//    std::string ranks, suits;
//    for (char c : subset) {
//        if (c == 'C' || c == 'D' || c == 'H' || c == 'S')
//            suits += c;
//        else
//            ranks += c;
//    }
//    return (ranks.empty() || ranks.find(card[0]) != std::string::npos) &&
//        (suits.empty() || suits.find(card[1]) != std::string::npos);
//}
//
//
//double Probability(const std::vector<std::string>& deletion, const std::vector<std::string>& winning) {
//    std::string values = "23456789TJQKA", suits = "CDHS";
//    std::vector<std::string> deck;
//
//
//    for (char v : values)
//        for (char s : suits)
//            deck.push_back(std::string(1, v) + s);
//
//    for (const std::string& rule : deletion) {
//        deck.erase(remove_if(deck.begin(), deck.end(),
//            [&rule](const std::string& card) { return matches(card, rule); }),
//            deck.end());
//    }
//
//    if (deck.empty()) return 0.0; 
//
//
//    int wins = 0;
//    for (const std::string& card : deck) {
//        for (const std::string& rule : winning) {
//            if (matches(card, rule)) {
//                ++wins;
//                break;
//            }
//        }
//    }
//
//    return static_cast<double>(wins) / deck.size();
//}
//
//int main() {
//    int r1, s1, r2, s2;
//    std::cin >> r1 >> s1 >> r2 >> s2;
//
//    std::vector<std::string> delGrey(r1), winGrey(s1), delWhite(r2), winWhite(s2);
//    for (auto& rule : delGrey) std::cin >> rule;
//    for (auto& rule : winGrey) std::cin >> rule;
//    for (auto& rule : delWhite) std::cin >> rule;
//    for (auto& rule : winWhite) std::cin >> rule;
//
//    double pGrey = Probability(delGrey, winGrey);
//    double pWhite = Probability(delWhite, winWhite);
//
//    std::cout.precision(2);
//    std::cout << std::fixed << std::max(pGrey, pWhite) << std::endl;
//
//    return 0;
//}
