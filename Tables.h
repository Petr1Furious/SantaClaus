#pragma once

#include "ITable.h"
#include "Toy.h"

class PapaXmasTable : public ITable {
    void init() override;
};

ITable* createTable();

class TableRand : public ITable {
    void init() override;
};

ITable* createTableRand();
