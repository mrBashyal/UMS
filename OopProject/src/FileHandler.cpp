#include "FileHandler.hpp"
#include <fstream>
#include <sstream>
#include <vector>

// Load students from a file
std::vector<Student> FileHandler::loadStudents(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string id, name;

            if (iss >> id) {
                // Extract the remaining part of the line as the name
                std::getline(iss, name);
                // Trim leading whitespace from the name
                name = name.substr(name.find_first_not_of(" "));
                students.emplace_back(id, name);
            }
        }
        file.close();
    }
    return students;
}

// Save students to a file
void FileHandler::saveStudents(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getId() << " " << student.getName() << std::endl;
        }
        file.close();
    }
}

// Load courses from a file
std::vector<Course> FileHandler::loadCourses(const std::string& filename) {
    std::vector<Course> courses;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string id, name;

            if (iss >> id) {
                // Extract the remaining part of the line as the name
                std::getline(iss, name);
                // Trim leading whitespace from the name
                name = name.substr(name.find_first_not_of(" "));
                courses.emplace_back(id, name);
            }
        }
        file.close();
    }
    return courses;
}

// Save courses to a file
void FileHandler::saveCourses(const std::string& filename, const std::vector<Course>& courses) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& course : courses) {
            file << course.getId() << " " << course.getName() << std::endl;
        }
        file.close();
    }
}

// Load faculty from a file
std::vector<Faculty> FileHandler::loadFaculty(const std::string& filename) {
    std::vector<Faculty> faculty;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string id, name;

            if (iss >> id) {
                // Extract the remaining part of the line as the name
                std::getline(iss, name);
                // Trim leading whitespace from the name
                name = name.substr(name.find_first_not_of(" "));
                faculty.emplace_back(id, name);
            }
        }
        file.close();
    }
    return faculty;
}

// Save faculty to a file
void FileHandler::saveFaculty(const std::string& filename, const std::vector<Faculty>& faculty) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& member : faculty) {
            file << member.getId() << " " << member.getName() << std::endl;
        }
        file.close();
    }
}
