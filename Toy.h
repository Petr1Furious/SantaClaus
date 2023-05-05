#pragma once

#include <iostream>
#include <utility>
#include "Object.h"

class Toy : public Object {
public:
    explicit Toy(std::string title) : Object(std::move(title)) {}

    virtual void isTaken() const = 0;

    ~Toy() override = default;
};

class Teddy : public Toy {
public:
    explicit Teddy(std::string title) : Toy(std::move(title)) {}

    void isTaken() const override;
};

class LittlePony : public Toy {
public:
    explicit LittlePony(std::string title) : Toy(std::move(title)) {}

    void isTaken() const override;
};

Object** MyUnitTests();
