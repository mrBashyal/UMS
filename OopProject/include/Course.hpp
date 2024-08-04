#pragma once
#include <string>

class Course {
public:
    Course(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;
    void setName(const std::string& name);

private:
    std::string id;
    std::string name;
};
