#include "ConveyorBelts.h"
#include <boost/asio.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <chrono>
#include <random>
#include <sstream>

using boost::asio::ip::udp;

void PapaXmasConveyorBelt::in()
{
    if (content != nullptr) {
        std::cerr << "Conveyor belt is not empty!\n";
        return;
    }

    content = dynamic_cast<Object*>(new Wrap("wrap"));
}

void PapaXmasConveyorBelt::out()
{
    if (content == nullptr) {
        std::cerr << "Conveyor belt is empty!\n";
        return;
    }

    delete content;
    content = nullptr;
}

IConveyorBelt* createConveyorBelt()
{
    return dynamic_cast<IConveyorBelt*>(new PapaXmasConveyorBelt());
}

void ConveyorBeltRand::in()
{
    if (content != nullptr) {
        std::cerr << "Conveyor belt is not empty!\n";
        return;
    }

    static std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

    if (rnd() % 2 == 0) {
        content = dynamic_cast<Object*>(new Box("random box"));
    } else {
        content = dynamic_cast<Object*>(new GiftPaper("random gift paper"));
    }
}

void ConveyorBeltRand::out()
{
    if (content == nullptr) {
        std::cerr << "Conveyor belt is empty!\n";
        return;
    }

    pugi::xml_document doc;
    content->Serialize(doc.append_child());
    doc.save(std::cout);

    delete content;
    content = nullptr;
}

IConveyorBelt* createConveyorBeltRand()
{
    return dynamic_cast<IConveyorBelt*>(new ConveyorBeltRand());
}

void MagicalCarpet::out()
{
    if (content == nullptr) {
        std::cerr << "Magical carpet is empty!\n";
        return;
    }

    pugi::xml_document doc;
    content->Serialize(doc.append_child());

    std::stringstream ss;
    doc.save(ss);

    boost::asio::io_service service;
    udp::socket socket(service);

    int32_t port = 13131;
    socket.open(udp::v4());
    socket.set_option(udp::socket::reuse_address(true));
    socket.bind(udp::endpoint(boost::asio::ip::address_v4::any(), port));

    boost::asio::ip::address address = boost::asio::ip::address::from_string(ip);
    socket.set_option(boost::asio::ip::multicast::join_group(address));

    udp::endpoint destination(address, port);
    socket.send_to(boost::asio::buffer(ss.str()), destination);

    delete content;
    content = nullptr;
}

IConveyorBelt* createMagicalCarpet(std::string ip)
{
    return dynamic_cast<IConveyorBelt*>(new MagicalCarpet(std::move(ip)));
}
