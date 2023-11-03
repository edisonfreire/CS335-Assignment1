#include "PointCard.hpp"

PointCard::PointCard() : Card() {
    setType(POINT_CARD);
    setInstruction("0");
}

bool PointCard::isNumeric(const std::string& str) {
    try {
        std::stod(str);
        return true;
    } catch (const std::invalid_argument& ia) {
        return false;
    }
}

bool PointCard::isPlayable() {
    const std::string instruction = getInstruction();
    if (getDrawn() && isNumeric(instruction)) {
        return true;
    }
    return false;
}

void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;

    const int* imageData = getImageData();
    if (imageData) {
        std::cout << "Card:" << std::endl;
        for (int i = 0; i < 64; i++) {
            std::cout << imageData[i] << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << "Card: No image data" << std::endl;
    }
}