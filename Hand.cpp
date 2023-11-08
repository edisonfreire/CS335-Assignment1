/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Edison Freire
Date: 11/7/23
Hand.cpp implements the Hand class.
*/

#include "Hand.hpp"

/**
 * @post: Construct a new Hand object
 */
Hand::Hand() : cards_{} {}

/**
 * @post: Destroy the Hand object
 */
Hand::~Hand() {}

/**
 * Copy Constructor
 * @param: other Hand object
 */
Hand::Hand(const Hand &other)
{
    cards_ = other.cards_;
}

/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(const Hand &other)
{
    if (this != &other)
    {
        cards_ = other.cards_;
    }
    return *this;
}

/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand &&other)
{
    cards_ = std::move(other.cards_);
}

/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(Hand &&other)
{
    if (this != &other)
    {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard> &Hand::getCards() const
{
    return cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard &&card)
{
    cards_.push_back(card);
}

/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const
{
    return cards_.empty();
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse()
{
    // Hand reversed = *this;
    // std::reverse(reversed.cards_.rbegin(), reversed.cards_.rend());
    // *this = reversed;
    size_t left = 0;
    size_t right = cards_.size() - 1;

    while (left < right)
    {
        // Swap the cards at the left and right positions
        std::swap(cards_[left], cards_[right]);
        // Move the pointers towards the center
        ++left;
        --right;
    }
}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
int Hand::PlayCard()
{
    if (isEmpty())
    {
        throw std::runtime_error("Hand is empty. Cannot play a card.");
    }
    PointCard frontCard = std::move(cards_.front());
    frontCard.setDrawn(true);
    cards_.pop_front();

    if (frontCard.isPlayable())
    {
        return std::stoi(frontCard.getInstruction());
    }

    return 0;
}