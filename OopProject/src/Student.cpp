#include "Student.hpp"

Student::Student(const std::string& id, const std::string& name)
    : Person(name), id(id) {}

std::string Student::getId() const {
    return id;
}

void Student::setId(const std::string& id) {
    this->id = id;
}
