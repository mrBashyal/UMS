#pragma once
#include "AppState.hpp"
#include "UIComponents.hpp"
#include "raylib.hpp"
#include "Authentication.hpp"
#include <cstring>
#include <string>

void handleLogin(AppState &state)
{
    DrawText("University Management System", 250, 50, 60, DARKGRAY);
    DrawText("Login", 650, 250, 45, DARKGRAY);
    DrawText("Username:", 450, 400, 30, DARKGRAY);
    TextInput(state.username, sizeof(state.username), {650, 400, 300, 40}, state.usernameActive);
    DrawText("Password:", 450, 470, 30, DARKGRAY);
    PasswordInput(state.password, sizeof(state.password), {650, 470, 300, 40}, !state.usernameActive);

    if (Button({670, 620, 70, 40}, "Login"))
    {
         UserType userType = Authentication::authenticateUser(state.username, state.password);
        
        switch (userType) {
            case UserType::ADMIN:
                state.currentUserType = UserType::ADMIN;
                state.currentScreen = Screen::MENU;
                break;
            case UserType::STUDENT:
                state.currentUserType = UserType::STUDENT;
                state.currentScreen = Screen::MENU;
                break;
            case UserType::INVALID:
                DrawText("Invalid credentials", 500, 700, 40, RED);
                break;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {650, 400, 300, 40}))
        {
            state.usernameActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {650, 470, 300, 40}))
        {
            state.usernameActive = false;
        }
    }
}

void handleMenu(AppState &state)
{
    if (state.currentUserType == UserType::ADMIN)
    {
        DrawText("Admin Menu", 1400 / 2 - 100, 50, 40, DARKGRAY);
        if (Button({1400 / 2 - 100, 200, 200, 40}, "Students"))
            state.currentScreen = Screen::STUDENT_MENU;
        if (Button({1400 / 2 - 100, 250, 200, 40}, "Courses"))
            state.currentScreen = Screen::COURSE_MENU;
        if (Button({1400 / 2 - 100, 300, 200, 40}, "Faculty"))
            state.currentScreen = Screen::FACULTY_MENU;
        if (Button({1400 / 2 - 100, 500, 200, 40}, "Logout"))
            state.currentScreen = Screen::LOGIN;
    }
    else if(state.currentUserType == UserType::STUDENT)
    {
        DrawText("Student Menu", 1400 / 2 - 100, 50, 40, DARKGRAY);
        if (Button({1400 / 2 - 100, 200, 220, 45}, "Display Students"))
            state.currentScreen = Screen::DISPLAY_STUDENTS;
        if (Button({1400 / 2 - 100, 260, 220, 45}, "Display Courses"))
            state.currentScreen = Screen::DISPLAY_COURSES;
        if (Button({1400 / 2 - 100, 320, 220, 45}, "Display Faculty"))
            state.currentScreen = Screen::DISPLAY_FACULTY;
        if (Button({1400 / 2 - 100, 380, 220, 45}, "Display Attendance"))
            state.currentScreen = Screen::DISPLAY_ATTENDANCE;
        if (Button({1400 / 2 - 100, 580, 200, 45}, "Logout"))
            state.currentScreen = Screen::LOGIN;
    }
}

void handleStudentMenu(AppState &state)
{
    DrawText("Student Menu", 570, 50, 40, DARKGRAY);
    if (Button({600, 200, 220, 40}, "Add Student"))
        state.currentScreen = Screen::ADD_STUDENT;
    if (Button({600, 260, 220, 40}, "Display Students"))
        state.currentScreen = Screen::DISPLAY_STUDENTS;
    if (Button({600, 320, 220, 40}, "Update Student"))
        state.currentScreen = Screen::UPDATE_STUDENT;
    if (Button({600, 380, 220, 40}, "Delete Student"))
        state.currentScreen = Screen::DELETE_STUDENT;
    if (Button({600, 440, 220, 40}, "Take Attendance"))
        state.currentScreen = Screen::TAKE_ATTENDANCE;
    if (Button({600, 500, 220, 40}, "Display Attendance"))
        state.currentScreen = Screen::DISPLAY_ATTENDANCE;
    if (Button({600, 650, 220, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleCourseMenu(AppState &state)
{
    DrawText("Course Menu", 570, 50, 40, DARKGRAY);
    if (Button({600, 200, 200, 40}, "Add Course"))
        state.currentScreen = Screen::ADD_COURSE;
    if (Button({600, 260, 200, 40}, "Display Courses"))
        state.currentScreen = Screen::DISPLAY_COURSES;
    if (Button({600, 320, 200, 40}, "Update Course"))
        state.currentScreen = Screen::UPDATE_COURSE;
    if (Button({600, 380, 200, 40}, "Delete Course"))
        state.currentScreen = Screen::DELETE_COURSE;
    if (Button({600, 530, 200, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleFacultyMenu(AppState &state)
{
    DrawText("Faculty Menu", 570, 50, 40, DARKGRAY);
    if (Button({600, 200, 200, 40}, "Add Faculty"))
        state.currentScreen = Screen::ADD_FACULTY;
    if (Button({600, 260, 200, 40}, "Display Faculty"))
        state.currentScreen = Screen::DISPLAY_FACULTY;
    if (Button({600, 320, 200, 40}, "Update Faculty"))
        state.currentScreen = Screen::UPDATE_FACULTY;
    if (Button({600, 380, 200, 40}, "Delete Faculty"))
        state.currentScreen = Screen::DELETE_FACULTY;
    if (Button({600, 530, 200, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleAddStudent(AppState &state)
{

    DrawText("Add Student", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Student ID:", 600 - 150, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Student Name:", 600 - 150, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);
    if (Button({600 - 60, 410, 200, 40}, "Save"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            state.students.emplace_back(state.inputId, state.inputName);
            memset(state.inputId, 0, sizeof(state.inputId));
            memset(state.inputName, 0, sizeof(state.inputName));
            state.currentScreen = Screen::MENU;
        }
    }
    if (Button({600 - 60, 460, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleDisplayStudents(AppState &state)
{
    DrawText("Student List", 600 - 60, 50, 40, DARKGRAY);
    for (size_t i = 0; i < state.students.size(); i++)
    {
        DrawText((state.students[i].getId() + " - " + state.students[i].getName()).c_str(), 200, 150 + i * 30, 20, DARKGRAY);
    }
    if (Button({600 - 40, 800, 200, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleUpdateStudent(AppState &state)
{
    DrawText("Update Student", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Student ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Enter Updated Name:", 600 - 250, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);

    if (Button({600 - 40, 410, 200, 40}, "Update"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            for (auto &student : state.students)
            {
                if (student.getId() == state.inputId)
                {
                    student.setName(state.inputName);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    memset(state.inputName, 0, sizeof(state.inputName));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 470, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleDeleteStudent(AppState &state)
{
    DrawText("Delete Student", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Student ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);

    if (Button({600 - 40, 350, 200, 40}, "Delete"))
    {
        if (strlen(state.inputId) > 0)
        {
            for (auto it = state.students.begin(); it != state.students.end(); ++it)
            {
                if (it->getId() == state.inputId)
                {
                    state.students.erase(it);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 410, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
    }
}

void handleAddCourse(AppState &state)
{
    DrawText("Add Course", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Course ID:", 600 - 150, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Course Name:", 600 - 150, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);

    if (Button({600 - 40, 410, 200, 40}, "Save"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            state.courses.emplace_back(state.inputId, state.inputName);
            memset(state.inputId, 0, sizeof(state.inputId));
            memset(state.inputName, 0, sizeof(state.inputName));
            state.currentScreen = Screen::MENU;
        }
    }

    if (Button({600 - 40, 470, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleDisplayCourses(AppState &state)
{
    DrawText("Course List", 600 - 60, 50, 40, DARKGRAY);
    for (size_t i = 0; i < state.courses.size(); i++)
    {
        DrawText((state.courses[i].getId() + " - " + state.courses[i].getName()).c_str(), 200, 150 + i * 30, 20, DARKGRAY);
    }
    if (Button({600 - 40, 800, 200, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleUpdateCourse(AppState &state)
{
    DrawText("Update Course", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Course ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Enter Updated Name:", 600 - 250, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);

    if (Button({600 - 40, 410, 200, 40}, "Update"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            for (auto &course : state.courses)
            {
                if (course.getId() == state.inputId)
                {
                    course.setName(state.inputName);
                    FileHandler::saveCourses("courses.txt", state.courses);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    memset(state.inputName, 0, sizeof(state.inputName));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 470, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleDeleteCourse(AppState &state)
{
    DrawText("Delete Course", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Course ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);

    if (Button({600 - 40, 350, 200, 40}, "Delete"))
    {
        if (strlen(state.inputId) > 0)
        {
            for (auto it = state.courses.begin(); it != state.courses.end(); ++it)
            {
                if (it->getId() == state.inputId)
                {
                    state.courses.erase(it);
                    FileHandler::saveCourses("courses.txt", state.courses);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 410, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
    }
}

void handleAddFaculty(AppState &state)
{
    DrawText("Add Faculty", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Faculty ID:", 600 - 150, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Faculty Name:", 600 - 150, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);

    if (Button({600 - 40, 410, 200, 40}, "Save"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            state.faculty.emplace_back(state.inputId, state.inputName);
            FileHandler::saveFaculty("faculty.txt", state.faculty);
            memset(state.inputId, 0, sizeof(state.inputId));
            memset(state.inputName, 0, sizeof(state.inputName));
            state.currentScreen = Screen::MENU;
        }
    }

    if (Button({600 - 40, 410, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleUpdateFaculty(AppState &state)
{
    DrawText("Update Faculty", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Faculty ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);
    DrawText("Enter Updated Name:", 600 - 250, 260, 30, DARKGRAY);
    TextInput(state.inputName, sizeof(state.inputName), {800 - 100, 260, 250, 40}, !state.idActive);

    if (Button({600 - 40, 410, 200, 40}, "Update"))
    {
        if (strlen(state.inputId) > 0 && strlen(state.inputName) > 0)
        {
            for (auto &fac : state.faculty)
            {
                if (fac.getId() == state.inputId)
                {
                    fac.setName(state.inputName);
                    FileHandler::saveFaculty("faculty.txt", state.faculty);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    memset(state.inputName, 0, sizeof(state.inputName));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 470, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        memset(state.inputName, 0, sizeof(state.inputName));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
        else if (CheckCollisionPointRec(mousePoint, {800 - 100, 260, 250, 40}))
        {
            state.idActive = false;
        }
    }
}

void handleDeleteFaculty(AppState &state)
{
    DrawText("Delete Faculty", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Enter Faculty ID:", 600 - 250, 200, 30, DARKGRAY);
    TextInput(state.inputId, sizeof(state.inputId), {800 - 100, 200, 250, 40}, state.idActive);

    if (Button({600 - 40, 350, 200, 40}, "Delete"))
    {
        if (strlen(state.inputId) > 0)
        {
            for (auto it = state.faculty.begin(); it != state.faculty.end(); ++it)
            {
                if (it->getId() == state.inputId)
                {
                    state.faculty.erase(it);
                    FileHandler::saveFaculty("faculty.txt", state.faculty);
                    memset(state.inputId, 0, sizeof(state.inputId));
                    state.currentScreen = Screen::MENU;
                    break;
                }
            }
        }
    }

    if (Button({600 - 40, 410, 200, 40}, "Back"))
    {
        memset(state.inputId, 0, sizeof(state.inputId));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.idActive = true;
        }
    }
}

void handleDisplayFaculty(AppState &state)
{
    DrawText("Faculty List", 600 - 60, 50, 40, DARKGRAY);
    for (int i = 0; i < state.faculty.size(); i++)
    {
        DrawText((state.faculty[i].getId() + " - " + state.faculty[i].getName()).c_str(), 200, 150 + i * 30, 20, DARKGRAY);
    }
    if (Button({600 - 40, 800, 200, 40}, "Back"))
        state.currentScreen = Screen::MENU;
}

void handleTakeAttendance(AppState &state)
{
    DrawText("Take Attendance", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Date (YYYY-MM-DD):", 600 - 250, 200, 30, DARKGRAY);
    DateInput(state.attendanceDate, sizeof(state.attendanceDate), {800 - 100, 200, 250, 40}, state.dateActive);

    if (strlen(state.attendanceDate) == 10)
    { // Ensure date is entered
        for (int i = 0; i < state.students.size(); i++)
        {
            DrawText((state.students[i].getId() + " - " + state.students[i].getName()).c_str(), 200, 300 + i * 30, 20, DARKGRAY);
            state.attendance[state.attendanceDate][state.students[i].getId()] = Checkbox({500.0f, 300.0f + i * 30.0f, 20.0f, 20.0f}, state.attendance[state.attendanceDate][state.students[i].getId()]);
        }
    }

    if (Button({600 - 20, 800, 200, 40}, "Save & Back"))
    {
        state.saveAttendance("attendance.txt");
        memset(state.attendanceDate, 0, sizeof(state.attendanceDate));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.dateActive = true;
        }
        else
        {
            state.dateActive = false;
        }
    }
}

void handleDisplayAttendance(AppState &state)
{
    DrawText("Display Attendance", 600 - 60, 50, 40, DARKGRAY);
    DrawText("Date (YYYY-MM-DD):", 600 - 250, 200, 30, DARKGRAY);
    DateInput(state.attendanceDate, sizeof(state.attendanceDate), {800 - 100, 200, 250, 40}, state.dateActive);

    if (strlen(state.attendanceDate) == 10)
    { // Ensure date is entered
        for (int i = 0; i < state.students.size(); i++)
        {
            DrawText((state.students[i].getId() + " - " + state.students[i].getName() + " - " + (state.attendance[state.attendanceDate][state.students[i].getId()] ? "Present" : "Absent")).c_str(), 200, 300 + i * 30, 20, DARKGRAY);
        }
    }

    if (Button({600 - 20, 800, 200, 40}, "Back"))
    {
        memset(state.attendanceDate, 0, sizeof(state.attendanceDate));
        state.currentScreen = Screen::MENU;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, {800 - 100, 200, 250, 40}))
        {
            state.dateActive = true;
        }
        else
        {
            state.dateActive = false;
        }
    }
}