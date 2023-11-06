#include "Hand.hpp"

Hand::Hand() : cards_{} {}

Hand::~Hand() {}

Hand::Hand(const Hand& other) {
    cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other) {}

Hand::Hand(Hand&& other) {}

const std::deque<PointCard>& Hand::getCards() const {}

void Hand::addCard(PointCard&& card) {}

bool Hand::isEmpty() const {}

void Hand::Reverse() {}

int Hand::PlayCard() {}