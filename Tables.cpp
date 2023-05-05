#include "Tables.h"

#include <chrono>
#include <random>

void PapaXmasTable::init()
{
    put(dynamic_cast<Object*>(new Teddy("teddy")));
    put(dynamic_cast<Object*>(new LittlePony("little pony")));
}

ITable* createTable()
{
    auto* table = dynamic_cast<ITable*>(new PapaXmasTable());
    table->init();
    return table;
}

static std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

void TableRand::init()
{
    while (size < TABLE_SIZE) {
        Object* toy;
        if (rnd() % 2 == 0) {
            toy = reinterpret_cast<Toy*>(new Teddy("random teddy"));
        } else {
            toy = reinterpret_cast<Toy*>(new LittlePony("random little pony"));
        }
        put(toy);
    }
}

ITable* createTableRand()
{
    auto* table = dynamic_cast<ITable*>(new TableRand());
    table->init();
    return table;
}
