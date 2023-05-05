#include <utility>

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

class MagicalCarpet : public ConveyorBeltRand {
    std::string ip;

public:
    explicit MagicalCarpet(std::string ip) : ip(std::move(ip)) {}

    void out() override;
};

IConveyorBelt* createMagicalCarpet(std::string ip);
