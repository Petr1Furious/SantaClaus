#pragma once

#include "IConveyorBelt.h"
#include "ITable.h"

class IElf {
protected:
    ITable* table;
    IConveyorBelt* conveyor_belt;

public:
    IElf(ITable* table, IConveyorBelt* conveyorBelt)
        : table(table)
        , conveyor_belt(conveyorBelt)
    {
    }

    virtual bool wrapGift() = 0;

    virtual bool wrapAllGifts() = 0;
};
