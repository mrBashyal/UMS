#include "Faculty.hpp"

Faculty::Faculty(const std::string& id, const std::string& name) : Person(name), id(id) {}

std::string Faculty::getId() const {
    return id;
}

void Faculty::setId(const std::string& id) {
    this->id = id;
}
