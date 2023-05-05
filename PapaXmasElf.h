#pragma once

#include "IElf.h"

class PapaXmasElf : public IElf {
public:
    PapaXmasElf(ITable* table, IConveyorBelt* conveyorBelt)
        : IElf(table, conveyorBelt)
    {
    }

    bool wrapGift() override;

    bool wrapAllGifts() override;
};
