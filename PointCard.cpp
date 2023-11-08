/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Edison Freire
Date: 11/7/23
PointCard.cpp implements the PointCard class and inherits from the Card Class.
*/

#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard() : Card()
{
    setType(POINT_CARD);
    setInstruction("0");
}

/**
 * @return true if the string is a valid number, false otherwise
 */
bool PointCard::isNumeric(const std::string &str)
{
    try
    {
        std::stod(str);
        return true;
    }
    catch (const std::invalid_argument &ia)
    {
        return false;
    }
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
 */
bool PointCard::isPlayable()
{
    const std::string instruction = getInstruction();
    if (getDrawn() && isNumeric(instruction))
    {
        return true;
    }
    return false;
}

/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;

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