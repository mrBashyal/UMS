#pragma once
#include "Screens.hpp"
#include <vector>
#include <map>
#include "Student.hpp"
#include "Course.hpp"
#include "Faculty.hpp"
#include "FileHandler.hpp"
#include <fstream>
#include<cstring>
#include "Authentication.hpp"

class AppState {
public:
    Screen currentScreen;
    char inputId[10];
    char inputName[50];
    char username[20];
    char password[20];
    char attendanceDate[11];
    bool idActive;
    bool usernameActive;
    bool dateActive;
    bool isAdmin;

    std::vector<Student> students;
    std::vector<Course> courses;
    std::vector<Faculty> faculty;
    std::map<std::string, std::map<std::string, bool>> attendance;

    UserType currentUserType;

    AppState() : currentScreen(Screen::LOGIN), idActive(true), usernameActive(true), dateActive(false), currentUserType(UserType::INVALID) {
        memset(inputId, 0, sizeof(inputId));
        memset(inputName, 0, sizeof(inputName));
        memset(username, 0, sizeof(username));
        memset(password, 0, sizeof(password));
        memset(attendanceDate, 0, sizeof(attendanceDate));
    }

    void loadData() {
        students = FileHandler::loadStudents("students.txt");
        courses = FileHandler::loadCourses("courses.txt");
        faculty = FileHandler::loadFaculty("faculty.txt");
        loadAttendance("attendance.txt");
    }

    void saveData() {
        FileHandler::saveStudents("students.txt", students);
        FileHandler::saveCourses("courses.txt", courses);
        FileHandler::saveFaculty("faculty.txt", faculty);
        saveAttendance("attendance.txt");
    }

    void loadAttendance(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string date, id;
            bool present;
            while (file >> date >> id >> present) {
                attendance[date][id] = present;
            }
            file.close();
        }
    }

    void saveAttendance(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& dateEntry : attendance) {
                for (const auto& entry : dateEntry.second) {
                    file << dateEntry.first << " " << entry.first << " " << entry.second << "\n";
                }
            }
            file.close();
        }
    }
};