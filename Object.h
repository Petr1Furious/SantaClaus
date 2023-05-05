#pragma once

#include <string>
#include <ostream>
#include "include/pugixml.hpp"

class Object {
    std::string title;

public:
    explicit Object(std::string title) : title(std::move(title)) {}

    std::string& getTitle();

    friend std::ostream& operator<<(std::ostream& stream, const Object& object);

    virtual void Serialize(pugi::xml_node node);

    virtual ~Object() = default;
};
