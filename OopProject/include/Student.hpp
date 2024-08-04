#pragma once
#include "Person.hpp"
#include <string>

class Student : public Person {
public:
    Student(const std::string& id, const std::string& name);

    std::string getId() const;
    void setId(const std::string& id);

private:
    std::string id;
};

