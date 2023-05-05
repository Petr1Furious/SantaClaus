#include "IConveyorBelt.h"

void IConveyorBelt::put(Object* object) {
    if (content != nullptr) {
        std::cerr << "Conveyor belt is not empty!\n";
        return;
    }
    content = object;
}

Object* IConveyorBelt::take() {
    Object* res_object = content;
    content = nullptr;
    return res_object;
}

IConveyorBelt::~IConveyorBelt() {
    delete content;
}
