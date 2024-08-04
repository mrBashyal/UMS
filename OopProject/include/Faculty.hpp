#pragma once
#include "Person.hpp"
#include <string>

class Faculty: public Person {
public:
    Faculty(const std::string& id, const std::string& name);

    std::string getId() const;
    void setId(const std::string& id);

private:
    std::string id;
};

