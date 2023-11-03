#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

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

    ActionCard card1;
    card1.Print();

    PointCard card2;
    card2.Print();

    return 0;
}