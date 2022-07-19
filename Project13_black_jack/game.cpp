#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
void solution() {
	std::srand(unsigned(std::time(0)));
	std::vector<int> cards = { 11,11,11,11,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,
	7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10, 10,10,10,10, 10,10,10,10,
	11,11,11,11 };
	std::cout << "*******************************" << std::endl;
	std::cout << "welcome. this is simple version of blackjack" << std::endl;
	std::cout << "rules are simple. draw a card, until you score 21" << std::endl;
	int choice;
	int count = 0;
	int playcard = 0;
	while (true) {
		std::cout << "draw a card" << std::endl;
		std::cout << "1-yes" << std::endl;
		std::cout << "0-no" << std::endl;
		std::cout << "your choice" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 1) {
			std::random_shuffle(cards.begin(), cards.end());
			int sizeOfVector = cards.size() - 1;
			playcard = cards[sizeOfVector];
			cards.pop_back();
			std::cout << "you drew:   " << playcard << std::endl;
			count += playcard;
			if (count > 21) {
				std::cout << "you loose" << count << std::endl;
				break;
			}
			else if (count == 21) {
				std::cout << "you win" << std::endl;
				break;
			}
			else {
				std::cout << "you have   " << count << "  points" << std::endl;
			}
		}
		//if user did not draw a card
		else if (choice == 0) {
			std::cout << "you ended the game. your score: " << count << std::endl;
			break;
		}
		else if ((choice != 1) && (choice != 0))
		{
			std::cout << "enter 1 or 0 to continue" << std::endl;
			std::cout << std::endl;

		}
	}
}

int main() {
	int t = 1;
	std::cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}