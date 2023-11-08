/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Edison Freire
Date: 11/7/23
Player.cpp implements the Player class.
*/

#include "Player.hpp"
/**
 * @post: Construct a new Player object
 */
Player::Player() : score_{0}, opponent_{nullptr}, actiondeck_{nullptr}, pointdeck_{nullptr} {}

/**
 * @post: Destroy the Player object
 */
Player::~Player()
{
    delete opponent_;
    delete actiondeck_;
    delete pointdeck_;
}

/**
 * @return the player's hand
 */
const Hand &Player::getHand() const
{
    return hand_;
}

/**
 * @post: Set the player's hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand &hand)
{
    hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const
{
    return score_;
}

/**
 * @post: Set the player's score
 * @param: score
 */
void Player::setScore(const int &score)
{
    score_ = score;
}

/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard &&card)
{
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    std::string instruction = card.getInstruction();
    std::smatch match;
    std::regex drawRegex("(DRAW|PLAY) (\\d+) CARD\\(S\\)");
    if (std::regex_match(instruction, match, drawRegex))
    {
        if (match.size() == 3)
        {
            std::string action = match[1].str();      // "DRAW" or "PLAY"
            int numCards = std::stoi(match[2].str()); // Extracted number of cards
            if (action == "PLAY")
            {
                for (int i = 0; i < numCards; i++)
                {
                    playPointCard();
                }
            }
            else if (action == "DRAW")
            {
                for (int i = 0; i < numCards; i++)
                {
                    drawPointCard();
                }
            }
        }
    }
    else if (instruction == "REVERSE HAND")
    {
        hand_.Reverse();
    }
    else if (instruction == "SWAP HAND WITH OPPONENT")
    {
        if (opponent_ != nullptr)
        {
            Hand temp = hand_;
            setHand(opponent_->getHand());
            opponent_->setHand(temp);
        }
    }
}

/**
 * @post: Draw a point card and place it in the player's hand
 */
void Player::drawPointCard()
{
    if (!pointdeck_->IsEmpty() && pointdeck_ != nullptr)
    {
        PointCard card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    }
}

/**
 * @post: Play a point card from the player's hand and update the player's score
 */
void Player::playPointCard()
{
    if (!hand_.isEmpty())
    {
        setScore(score_ + hand_.PlayCard());
    }
}

/**
 * @post: Set the opponent of the player
 * @param a pointer to a Player opponent
 */
void Player::setOpponent(Player *opponent)
{
    opponent_ = opponent;
}

/**
 * @return: a pointer to the player's opponent
 */
Player *Player::getOpponent()
{
    return opponent_;
}

/**
 * @post: set the action deck of the player
 * @param: A pointer to a deck holding Action cards
 */
void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
    actiondeck_ = actiondeck;
}

/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard> *Player::getActionDeck()
{
    return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: A pointer to a deck holding Point cards
 */
void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
    pointdeck_ = pointdeck;
}

/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard> *Player::getPointDeck()
{
    return pointdeck_;
}