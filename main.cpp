#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main() {
	int *p = new int[80];
	for (int i=0; i < 80; i++) {
		p[i] = i+1;
	}

	ActionCard steve;
	steve.setInstruction("DRAW 4 CARD(S)");
	steve.setImageData(p);

	Deck<ActionCard> deck;
	deck.AddCard(steve);
	ActionCard workPls = deck.Draw();
	workPls.Print();

}