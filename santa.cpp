#include <iostream>
#include "include/pugixml.hpp"
#include "Object.h"
#include "Toy.h"
#include "Wrap.h"

Object* Deserialize(pugi::xml_node node) {
    if (strcmp(node.name(), "Object") == 0) {
        return new Object(node.attribute("title").as_string());
    }

    if (strcmp(node.name(), "Teddy") == 0) {
        return new Teddy(node.attribute("title").as_string());
    }
    if (strcmp(node.name(), "LittlePony") == 0) {
        return new LittlePony(node.attribute("title").as_string());
    }

    if (strcmp(node.name(), "Wrap") == 0 ||
        strcmp(node.name(), "Box") == 0 ||
        strcmp(node.name(), "GiftPaper") == 0) {
        Wrap* wrap;
        if (strcmp(node.name(), "Wrap") == 0) {
            wrap = new Wrap(node.attribute("title").as_string());
        } else if (strcmp(node.name(), "Box") == 0) {
            Box* box = new Box(node.attribute("title").as_string());
            if (!node.attribute("is_open").as_bool()) {
                box->closeMe();
            }
            wrap = box;
        } else {
            wrap = new GiftPaper(node.attribute("title").as_string());
        }

        if (node.child("content").children().begin() != node.child("content").children().end()) {
            wrap->wrapMeThat(Deserialize(*node.child("content").children().begin()));
        }

        return wrap;
    }

    return nullptr;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        pugi::xml_document doc;
        if (!doc.load_file(argv[i])) {
            std::cerr << "Could not load a file to XML!\n";
            continue;
        }

        Wrap* wrap;
        if ((wrap = dynamic_cast<Wrap*>(Deserialize(*doc.children().begin()))) == nullptr) {
            std::cerr << "XML must represent a wrapped gift!\n";
            continue;
        }

        Object* content = wrap->openMe();

        Toy* toy;
        if ((toy = dynamic_cast<Toy*>(content)) != nullptr) {
            toy->isTaken();
        }

        wrap->wrapMeThat(content);
        delete wrap;
    }
    return 0;
}
