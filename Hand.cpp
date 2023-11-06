#include "Hand.hpp"

Hand::Hand() : cards_{} {}

Hand::~Hand() {}

Hand::Hand(const Hand& other) {
    cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}

Hand& Hand::operator=(Hand&& other) {
    if (this != &other) {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

void Hand::addCard(PointCard&& card) {
    cards_.push_back(std::move(card));
}

bool Hand::isEmpty() const {
    return cards_.empty();
}

void Hand::Reverse() {
    size_t left = 0;
    size_t right = cards_.size() - 1;

    while (left < right) {
        // Swap the elements using std::swap
        std::swap(cards_[left], cards_[right]);
        left++;
        right--;
    }
}

int Hand::PlayCard() {
        if (isEmpty()) {
        throw std::runtime_error("Hand is empty. Cannot play a card.");
    }

    PointCard frontCard = std::move(cards_.front());
    cards_.pop_front();

    if (frontCard.isPlayable()) {
        return std::stoi(frontCard.getInstruction());
    } else {
        throw std::runtime_error("Card is not playable.");
    }

    // The card is not playable, so no points are earned.
    return 0;
}