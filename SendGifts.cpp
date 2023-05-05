#include <cstring>
#include "Tables.h"
#include "ConveyorBelts.h"
#include "PapaXmasElf.h"
#include "include/pugixml.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3 || strcmp(argv[1], "-w") != 0) {
        std::cerr << "Usage: " << argv[0] << " -w IP\n";
        return 1;
    }

    ITable* table = createTableRand();
    IConveyorBelt* conveyor_belt = createMagicalCarpet(argv[2]);
    PapaXmasElf elf(table, conveyor_belt);

    elf.wrapAllGifts();

    delete table;
    delete conveyor_belt;
    return 0;
}
