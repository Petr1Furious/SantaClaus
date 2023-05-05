#pragma once

#include "Object.h"

static const size_t TABLE_SIZE = 10;

class ITable {
protected:
    size_t size {};
    Object* objects[TABLE_SIZE] {};

public:
    virtual void init() = 0;

    [[nodiscard]] size_t getSize() const;

    void put(Object* object);

    Object* take(size_t num);

    [[nodiscard]] std::string* look() const;

    virtual ~ITable();
};