#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main() {
	int imageData[80] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80
    };
	Deck<ActionCard> deck;
	// if (deck.IsEmpty()) {
	// 	std::cout << "Deck is empty\n";
	// } else {
	// 	std::cout << "Deck is not empty\n";
	// }
	// ActionCard blank1;
	// ActionCard blank2;
	// ActionCard blank3;
	// deck.AddCard(blank1);
	// deck.AddCard(blank2);
	// deck.AddCard(blank3);
	// if (deck.IsEmpty()) {
	// 	std::cout << "Deck is empty\n";
	// } else {
	// 	std::cout << "Deck is not empty\n";
	// }

	ActionCard full;
	full.setInstruction("DRAW 15 CARD(S)");
	full.setImageData(imageData); // imageDate is an array with 80 integers
	deck.AddCard(full);
	ActionCard drawnCard = deck.Draw(); // this gives me the error
	drawnCard.Print();

	return 0;
}