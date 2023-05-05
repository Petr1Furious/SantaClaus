#include <iostream>
#include <boost/asio.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "include/pugixml.hpp"
#include "Object.h"
#include "Toy.h"
#include "Wrap.h"

static const size_t MAX_BUFFER_SIZE = 1500;

using boost::asio::ip::udp;

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

void takeXML(const pugi::xml_document& doc) {
    Wrap* wrap;
    if ((wrap = dynamic_cast<Wrap*>(Deserialize(*doc.children().begin()))) == nullptr) {
        std::cerr << "XML must represent a wrapped gift!\n";
        return;
    }

    Object* content = wrap->openMe();

    Toy* toy;
    if ((toy = dynamic_cast<Toy*>(content)) != nullptr) {
        toy->isTaken();
    }

    wrap->wrapMeThat(content);
    delete wrap;
}

int main(int argc, char* argv[]) {
    if (argc == 3 && strcmp(argv[1], "-w") == 0) {
        std::string ip = argv[2];
        int32_t port = 13131;

        boost::asio::io_service service;
        udp::socket socket(service);

        socket.open(udp::v4());
        socket.set_option(udp::socket::reuse_address(true));
        socket.bind(udp::endpoint(boost::asio::ip::address_v4::any(), port));

        boost::asio::ip::address address = boost::asio::ip::address::from_string(ip);
        socket.set_option(boost::asio::ip::multicast::join_group(address));

        try {
            while (true) {
                char buffer[MAX_BUFFER_SIZE + 1];
                size_t buffer_size = socket.receive(boost::asio::buffer(buffer, MAX_BUFFER_SIZE));

                pugi::xml_document doc;
                if (!doc.load_buffer(buffer, buffer_size)) {
                    std::cerr << "Could not load UDP data to XML!\n";
                    continue;
                }

                takeXML(doc);
            }
        }
        catch (const boost::exception& e) {
            std::cerr << "Error. Reason: " << boost::diagnostic_information(e) << '\n';
        }
    }

    for (int i = 1; i < argc; i++) {
        pugi::xml_document doc;
        if (!doc.load_file(argv[i])) {
            std::cerr << "Could not load a file to XML!\n";
            continue;
        }

        takeXML(doc);
    }
    return 0;
}
