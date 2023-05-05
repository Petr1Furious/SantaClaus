#include "PapaXmasElf.h"
#include "Toy.h"
#include <iostream>

bool PapaXmasElf::wrapGift()
{
    Object* object = table->take(table->getSize() - 1);
    Toy* toy;
    if ((toy = dynamic_cast<Toy*>(object)) != nullptr) {
        toy->isTaken();
    }

    Object* wrap_object = conveyor_belt->take();
    if (wrap_object == nullptr) {
        conveyor_belt->in();
        wrap_object = conveyor_belt->take();
    }

    Wrap* wrap = dynamic_cast<Wrap*>(wrap_object);
    Object* content = nullptr;
    if (wrap == nullptr || (content = wrap->openMe()) != nullptr) {
        if (content != nullptr) {
            wrap->wrapMeThat(content);
        }
        conveyor_belt->put(wrap);
        table->put(object);

        std::cerr << "Only empty wraps can come out of the conveyor belt!\n";
        return false;
    }
    std::cout << "whistles while working\n";

    wrap->wrapMeThat(object);
    std::cout << "tuuuut tuuut tuut\n";
    conveyor_belt->put(wrap);
    conveyor_belt->out();

    return true;
}

bool PapaXmasElf::wrapAllGifts()
{
    while (table->getSize() > 0) {
        if (!wrapGift()) {
            return false;
        }
    }

    std::cout << "o'pa ere 's somin ' wron ' in da box!\n";
    return true;
}
