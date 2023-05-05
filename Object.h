#pragma once

#include <string>
#include <utility>

class Object {
    std::string title;

public:
    explicit Object(std::string title) : title(std::move(title)) {}

    std::string& getTitle() {
        return title;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Object& object) {
        stream << object.title;
        return stream;
    }

    virtual ~Object() = default;
};
