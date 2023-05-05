#include <iostream>
#include "Tables.h"
#include "ConveyorBelts.h"
#include "PapaXmasElf.h"
#include "include/pugixml.hpp"

int main() {
    ITable* table = createTableRand();
    IConveyorBelt* conveyor_belt = createConveyorBeltRand();
    PapaXmasElf elf(table, conveyor_belt);

    elf.wrapAllGifts();

    delete table;
    delete conveyor_belt;
    return 0;
}
