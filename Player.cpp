#include "Player.hpp"

Player::Player() : score_{0}, opponent_{nullptr}, actiondeck_{nullptr}, pointdeck_{nullptr} {}

Player::~Player()
{
    delete opponent_;
    delete actiondeck_;
    delete pointdeck_;
}

const Hand &Player::getHand() const
{
    return hand_;
}

void Player::setHand(const Hand &hand)
{
    hand_ = hand;
}

int Player::getScore() const
{
    return score_;
}

void Player::setScore(const int &score)
{
    score_ = score;
}

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

void Player::drawPointCard()
{
    if (!pointdeck_->IsEmpty() && pointdeck_ != nullptr)
    {
        PointCard card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    }
}

void Player::playPointCard()
{
    if (!hand_.isEmpty())
    {
        setScore(score_ + hand_.PlayCard());
    }
}

void Player::setOpponent(Player *opponent)
{
    opponent_ = opponent;
}

Player *Player::getOpponent()
{
    return opponent_;
}

void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
    actiondeck_ = actiondeck;
}

Deck<ActionCard> *Player::getActionDeck()
{
    return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
    pointdeck_ = pointdeck;
}

Deck<PointCard> *Player::getPointDeck()
{
    return pointdeck_;
}