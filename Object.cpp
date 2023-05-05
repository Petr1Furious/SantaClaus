#include "Object.h"

std::string& Object::getTitle()
{
    return title;
}

std::ostream& operator<<(std::ostream& stream, const Object& object)
{
    stream << object.title;
    return stream;
}

void Object::Serialize(pugi::xml_node node)
{
    node.set_name("Object");
    node.append_attribute("title");
    node.attribute("title").set_value(title.c_str());
}
