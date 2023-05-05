#include <iostream>
#include "Wrap.h"

void Wrap::wrapMeThat(Object* gift) {
    if (content != nullptr) {
        std::cerr << "Wrap is not empty!\n";
        return;
    }
    content = gift;
}

Object* Wrap::openMe() {
    Object* res_content = content;
    content = nullptr;
    return res_content;
}

void Box::wrapMeThat(Object* gift) {
    if (!is_open) {
        std::cerr << "Box has to be open to wrap!\n";
        return;
    }

    Wrap::wrapMeThat(gift);
}

Object* Box::openMe() {
    is_open = true;
    return Wrap::openMe();
}

void Box::closeMe() {
    is_open = false;
}

Object* MyUnitTests(Object** objects) {
    auto* box = dynamic_cast<Box*>(objects[1]);
    auto* gift_paper = dynamic_cast<GiftPaper*>(objects[2]);

    delete box->openMe();
    box->wrapMeThat(objects[0]);
    box->closeMe();
    gift_paper->wrapMeThat(box);
    return gift_paper;
}
