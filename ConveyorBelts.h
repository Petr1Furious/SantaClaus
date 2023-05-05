#include "IConveyorBelt.h"

class PapaXmasConveyorBelt : public IConveyorBelt {
public:
    void in() override;

    void out() override;
};

IConveyorBelt* createConveyorBelt();

class ConveyorBeltRand : public IConveyorBelt {
public:
    void in() override;

    void out() override;
};

IConveyorBelt* createConveyorBeltRand();
