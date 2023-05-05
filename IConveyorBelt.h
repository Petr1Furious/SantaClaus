#pragma once

#include <iostream>
#include "Object.h"
#include "Wrap.h"

class IConveyorBelt {
protected:
    Object* content{};

public:
    void put(Object* object);

    Object* take();

    virtual void in() = 0;

    virtual void out() = 0;

    virtual ~IConveyorBelt();
};
