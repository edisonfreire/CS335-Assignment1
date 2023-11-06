#include "Card.hpp"

Card::~Card() {
    if (bitmap_ != nullptr) {
        delete[] bitmap_;
    }
}

Card::Card(const Card& rhs) : cardType_{rhs.cardType_}, instruction_{rhs.instruction_}, bitmap_{new int[80]}, drawn_{rhs.drawn_} {
    std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
}

Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        delete[] bitmap_;
        bitmap_ = new int[80];
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
        drawn_ = rhs.drawn_;
    }
    return *this;
}

Card::Card(Card&& rhs) : cardType_{std::move(rhs.cardType_)}, instruction_{std::move(rhs.instruction_)}, bitmap_{nullptr}, drawn_{std::move(rhs.drawn_)} {
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
}

Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        cardType_ = std::move(rhs.cardType_);
        delete[] bitmap_;
        bitmap_ = std::move(rhs.bitmap_);
        rhs.bitmap_ = new int[80];
        instruction_ = std::move(rhs.instruction_);
        drawn_ = std::move(rhs.drawn_);
    }
    return *this;
}

Card::Card() : cardType_{ACTION_CARD}, instruction_{""}, bitmap_{new int[80]}, drawn_{false} {}

std::string Card::getType() const {
    return (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
}

void Card::setType(const CardType& type) {
    cardType_ = type;
}

const std::string& Card::getInstruction() const {
    return instruction_;
}

void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

const int* Card::getImageData() const {
    return bitmap_;
}

void Card::setImageData(int* data) {
    bitmap_ = data;
}

bool Card::getDrawn() const {
    return drawn_;
}

void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}