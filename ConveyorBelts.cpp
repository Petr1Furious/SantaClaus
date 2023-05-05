#include <chrono>
#include <random>
#include "ConveyorBelts.h"

void PapaXmasConveyorBelt::in() {
    if (content != nullptr) {
        std::cerr << "Conveyor belt is not empty!\n";
        return;
    }

    content = dynamic_cast<Object*>(new Wrap("wrap"));
}

void PapaXmasConveyorBelt::out() {
    if (content == nullptr) {
        std::cerr << "Conveyor belt is empty!\n";
        return;
    }

    delete content;
    content = nullptr;
}

IConveyorBelt* createConveyorBelt() {
    return dynamic_cast<IConveyorBelt*>(new PapaXmasConveyorBelt());
}

void ConveyorBeltRand::in() {
    if (content != nullptr) {
        std::cerr << "Conveyor belt is not empty!\n";
        return;
    }

    static std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

    if (rnd() % 2 == 0) {
        content = dynamic_cast<Object*>(new Box("random box"));
    } else {
        content = dynamic_cast<Object*>(new GiftPaper("random gift paper"));
    }
}

void ConveyorBeltRand::out() {
    if (content == nullptr) {
        std::cerr << "Conveyor belt is empty!\n";
        return;
    }

    delete content;
    content = nullptr;
}

IConveyorBelt* createConveyorBeltRand() {
    return dynamic_cast<IConveyorBelt*>(new ConveyorBeltRand());
}
