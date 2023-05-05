#pragma once

#include <stdexcept>
#include "Object.h"

class Wrap : public Object {
    Object* content{};

public:
    explicit Wrap(std::string title) : Object(std::move(title)) {}

    virtual void wrapMeThat(Object* gift);

    virtual Object* openMe();

    ~Wrap() override;

    void Serialize(pugi::xml_node node) override;
};

class Box : public Wrap {
    bool is_open{true};

public:
    explicit Box(std::string title) : Wrap(std::move(title)) {}

    void wrapMeThat(Object* gift) override;

    Object* openMe() override;

    void closeMe();

    void Serialize(pugi::xml_node node) override;
};

class GiftPaper : public Wrap {
public:
    explicit GiftPaper(std::string title) : Wrap(std::move(title)) {}

    void Serialize(pugi::xml_node node) override;
};

Object* MyUnitTests(Object** objects);
