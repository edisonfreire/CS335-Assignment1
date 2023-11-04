#include "ActionCard.hpp"

ActionCard::ActionCard() : Card() {
    setType(ACTION_CARD);
    setInstruction("");
}

bool ActionCard::isPlayable() {
    const std::string instruction = getInstruction();
    if (getDrawn()) {
        std::regex drawRegex("DRAW \\d+ CARD(S");
        if (std::regex_match(instruction, drawRegex)) {
            return true;
        }
        std::regex playRegex("PLAY \\d+ CARD(S)?");
        if (std::regex_match(instruction, playRegex)) {
            return true;
        }
        if (instruction == "REVERSE HAND") {
            return true;
        }
        if (instruction == "SWAP HAND WITH OPPONENT") {
            return true;
        }
    }
    return false;
}

void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;

    const int* imageData = getImageData();
    if (imageData) {
        std::cout << "Card:" << std::endl;
        for (int i = 0; i < 80; i++) {
            std::cout << imageData[i] << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << "Card:\nNo image data" << std::endl;
    }
}