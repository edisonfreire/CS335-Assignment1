#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"

int main() {
	int *p = new int[80];
	for (int i=0; i < 80; i++) {
		p[i] = i+1;
	}

	// ActionCard steve;
	// steve.setInstruction("DRAW 4 CARD(S)");
	// steve.setImageData(p);
	// steve.Print();
	// Deck<ActionCard> deck;
	// deck.AddCard(steve);
	// ActionCard workPls = deck.Draw();
	// workPls.Print();

	Hand hand;
	std::cout << hand.isEmpty() << std::endl;

	PointCard card1;
	card1.setInstruction("15");
	card1.setImageData(p);

	PointCard card2;
	card2.setInstruction("69");

	hand.addCard(std::move(card1));
	hand.addCard(std::move(card2));

	// hand.Reverse();

	std::cout << hand.PlayCard() << std::endl;
	std::cout << hand.PlayCard() << std::endl;
}