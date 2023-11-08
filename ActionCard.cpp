/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Edison Freire
Date: 11/7/23
ActionCard.cpp implements the ActionCard class and inherits from the Card Class.
*/

#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
 */
ActionCard::ActionCard() : Card()
{
    setType(ACTION_CARD);
    setInstruction("");
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
 */
bool ActionCard::isPlayable()
{
    const std::string instruction = getInstruction();
    if (getDrawn())
    {
        std::regex drawRegex("(DRAW|PLAY) \\d+ CARD\\(S\\)");
        if (std::regex_match(instruction, drawRegex))
        {
            return true;
        }
        if (instruction == "REVERSE HAND")
        {
            return true;
        }
        if (instruction == "SWAP HAND WITH OPPONENT")
        {
            return true;
        }
    }
    return false;
}

/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;

    const int *imageData = getImageData();
    if (imageData != nullptr && imageData[79] != 0)
    {
        std::cout << "Card:" << std::endl;
        for (int i = 0; i < 80; i++)
        {
            std::cout << imageData[i] << ' ';
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Card:\nNo image data" << std::endl;
    }
}