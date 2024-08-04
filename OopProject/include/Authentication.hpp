#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

enum class UserType {
    ADMIN,
    STUDENT,
    INVALID
};

class Authentication {
public:
    static UserType authenticateUser(const std::string& username, const std::string& password) {
        if (checkCredentials("admin_credentials.txt", username, password)) {
            return UserType::ADMIN;
        }
        if (checkCredentials("student_credentials.txt", username, password)) {
            return UserType::STUDENT;
        }
        return UserType::INVALID;
    }

private:
    static bool checkCredentials(const std::string& filename, const std::string& username, const std::string& password) {
        std::ifstream file(filename);
        std::string line;
        
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword;
            
            if (std::getline(iss, storedUsername, ',') && std::getline(iss, storedPassword)) {
                if (storedUsername == username && storedPassword == password) {
                    return true;
                }
            }
        }
        
        return false;
    }
};