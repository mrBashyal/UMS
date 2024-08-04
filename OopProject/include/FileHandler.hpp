#pragma once
#include <string>
#include <vector>
#include "Student.hpp"
#include "Course.hpp"
#include "Faculty.hpp"

class FileHandler {
public:
    static std::vector<Student> loadStudents(const std::string& filename);
    static void saveStudents(const std::string& filename, const std::vector<Student>& students);

    static std::vector<Course> loadCourses(const std::string& filename);
    static void saveCourses(const std::string& filename, const std::vector<Course>& courses);

    static std::vector<Faculty> loadFaculty(const std::string& filename);
    static void saveFaculty(const std::string& filename, const std::vector<Faculty>& faculty);
};

