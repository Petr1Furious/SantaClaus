#include <iostream>
#include "ITable.h"

size_t ITable::getSize() const {
    return size;
}

void ITable::put(Object* object) {
    if (size == TABLE_SIZE) {
        std::cerr << "The table collapsed!\n";
        return;
    }
    objects[size++] = object;
}

Object* ITable::take(size_t num) {
    if (num > size) {
        std::cerr << "Taking a non-existent object!\n";
        return nullptr;
    }

    Object* res = objects[num];
    for (size_t i = num + 1; i <= size; i++) {
        if (i == size) {
            objects[i - 1] = nullptr;
            break;
        }
        objects[i - 1] = objects[i];
    }
    size--;
    return res;
}

std::string* ITable::look() const {
    auto* titles = new std::string[size + 1];
    for (size_t i = 0; i < size; i++) {
        titles[i] = objects[i]->getTitle();
    }
    titles[size] = nullptr;
    return titles;
}

ITable::~ITable() {
    for (auto& i : objects) {
        delete i;
    }
}
