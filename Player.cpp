#include "Player.hpp"

Player::Player() {}

Player::~Player() {}

const Hand& Player::getHand() const {}

void Player::setHand(const Hand& hand) {}

int Player::getScore() const {}

void Player::setScore(const int& score) {}

void Player::play(ActionCard&& card) {}

void Player::drawPointCard() {}

void Player::playPointCard() {}

Player* Player::getOpponent() {}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {}

Deck<ActionCard>* Player::getActionDeck() {}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {}

Deck<PointCard>* Player::getPointDeck() {}