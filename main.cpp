#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main() {
    // test copy constructor

    // Card originalCard;
    // originalCard.setInstruction("Original Instruction");
    // int imageData[80] = {
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    // 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    // 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    // 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    // 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    // 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    // 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    // 71, 72, 73, 74, 75, 76, 77, 78, 79, 80
    // };
    // originalCard.setImageData(imageData);

    // Card copiedCard(originalCard);
    // int modifiedImageData[80] = {
    // 69, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    // 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    // 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    // 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    // 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    // 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    // 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    // 71, 72, 73, 74, 75, 76, 77, 78, 79, 80
    // };
    // copiedCard.setInstruction("Modified Instruction");
    // copiedCard.setImageData(modifiedImageData);

    // const int* originalImageData = originalCard.getImageData();
    // const int* copiedImageData = copiedCard.getImageData();

    // std::cout << "Original Instruction: " << originalCard.getInstruction() << std::endl;
    // std::cout << "Copied Instruction: " << copiedCard.getInstruction() << std::endl;

    // // Assuming you want to print the first element of the image data for demonstration
    // std::cout << "Original Image Data[0]: " << originalImageData[0] << std::endl;
    // std::cout << "Copied Image Data[0]: " << copiedImageData[0] << std::endl;

    // ActionCard card;
    // card.Print();
    // card.setDrawn(true);
    // card.setInstruction("DRAW 1 CARD");
    // card.Print();
    // std::cout << card.isPlayable() << std::endl;

    // PointCard pc;
    // pc.setDrawn(true);
    // pc.setInstruction("Not a number");
    // pc.Print();
    // std::cout << pc.isPlayable() << std::endl;
    // pc.setInstruction("100");
    // pc.Print();
    // std::cout << pc.isPlayable() << std::endl;

    // ActionCard card1;
    // card1.setDrawn(true);
    // card1.setInstruction("DRAW 5 CARDS");
    // std::cout << "Original Card:" << std::endl;
    // card1.Print();

    // ActionCard card2(std::move(card1));
    // std::cout << "New Card (moved):" << std::endl;
    // card2.Print();

    // card1.Print();
    // testing cards

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

    // ActionCard card1;
    // card1.setDrawn(true);
    // card1.setInstruction("DRAW 2 CARDS");
    // card1.setImageData(imageData);
    // card1.Print();

    // ActionCard card2(card1);
    // card2.Print();
    // // test case 1 worked for card

    // ActionCard card3(std::move(card1));
    // card1.Print();
    // card3.Print();
    // // test case 2 worked for card

    // ActionCard drawCard;
    // drawCard.setDrawn(true);
    // drawCard.setInstruction("DRAW 15 CARDS");
    // std::cout << drawCard.isPlayable() << std::endl;

    // ActionCard playCard;
    // playCard.setDrawn(true);
    // playCard.setInstruction("PLAY 1 CARD");
    // std::cout << playCard.isPlayable() << std::endl;

    // ActionCard reverseCard;
    // reverseCard.setDrawn(true);
    // reverseCard.setInstruction("REVERSE HAND");
    // std::cout << reverseCard.isPlayable() << std::endl;

    // ActionCard swapCard;
    // swapCard.setDrawn(true);
    // swapCard.setInstruction("SWAP HAND WITH OPPONENT");
    // std::cout << swapCard.isPlayable() << std::endl;

    // PointCard numberCard;
    // numberCard.setDrawn(true);
    // numberCard.setInstruction("15");
    // std::cout << numberCard.isPlayable() << std::endl;

    // PointCard stringCard;
    // stringCard.setDrawn(true);
    // stringCard.setInstruction("this is a string");
    // std::cout << stringCard.isPlayable() << std::endl;
    // //test 3 passed for card

    // ActionCard emptyAction;
    // emptyAction.Print();

    // PointCard emptyPoint;
    // emptyPoint.Print();

    // ActionCard defaultAction;
    // std::cout << defaultAction.getType() << std::endl;
    // defaultAction.Print();

    // PointCard defaultPoint;
    // std::cout << defaultPoint.getType() << std::endl;
    // defaultPoint.Print();

    // ActionCard source;
    // source.setDrawn(true);
    // source.setInstruction("DRAW 4 CARDS");
    // source.setImageData(imageData);

    // ActionCard target;
    // // target = source;
    // target = std::move(source);
    // if (source.getImageData() == nullptr) {
    //     std::cout << "null" << std::endl;
    // }

    // source.Print();
    // target.Print();

    // source.setInstruction("PLAY 2 CARDS");
    // target.Print();
    // std::cout << target.isPlayable() << std::endl;

    // source.Print();

    Deck<ActionCard> actionDeck;
    
    // Check if it's empty
    if (actionDeck.IsEmpty()) {
        std::cout << "The deck is empty." << std::endl;
    } else {
        std::cout << "The deck is not empty." << std::endl;
    }

    ActionCard blankCard1;
    ActionCard blankCard2;
    
    actionDeck.AddCard(blankCard1);
    actionDeck.AddCard(blankCard2);
    
    // Check if the deck is empty after adding cards
    if (actionDeck.IsEmpty()) {
        std::cout << "The deck is empty after adding cards." << std::endl;
    } else {
        std::cout << "The deck is not empty after adding cards." << std::endl;
    }

    ActionCard actionCardWithContent;
    actionCardWithContent.setImageData(imageData);
    actionCardWithContent.setInstruction("DRAW 1 CARD");
    actionDeck.AddCard(actionCardWithContent);

    // Draw the card from the deck and use it on the right side of an assignment
    ActionCard drawnCard;
    drawnCard = actionDeck.Draw();

    // Check the content of the drawn card
    drawnCard.Print();

    // Draw multiple cards in a row
    // for (int i = 0; i < 3; i++) {
    //     ActionCard drawnCard = actionDeck.Draw();
    //     drawnCard.Print();
    // }


    return 0;
}