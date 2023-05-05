#include "Toy.h"
#include <cassert>

void Teddy::isTaken() const
{
    std::cout << "gra hu\n";
}

void LittlePony::isTaken() const
{
    std::cout << "yo man\n";
}

Object** MyUnitTests()
{
    auto** objects = new Object*[2];
    objects[0] = new LittlePony("happy pony");
    objects[1] = new Teddy("cuddles");

    assert(objects[0]->getTitle() == "happy pony");
    assert(objects[1]->getTitle() == "cuddles");
    return objects;
}

void Toy::Serialize(pugi::xml_node node)
{
    Object::Serialize(node);
    node.set_name("Toy");
}

void Teddy::Serialize(pugi::xml_node node)
{
    Toy::Serialize(node);
    node.set_name("Teddy");
}

void LittlePony::Serialize(pugi::xml_node node)
{
    Toy::Serialize(node);
    node.set_name("LittlePony");
}
