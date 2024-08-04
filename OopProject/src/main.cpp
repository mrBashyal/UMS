#include "raylib.hpp"
#include "AppState.hpp"
#include "AppLogic.hpp"

void initializeWindow();
void runMainLoop(AppState& state);

int main() {
    AppState state;
    state.loadData();

    initializeWindow();
    runMainLoop(state);

    state.saveData();
    CloseWindow();
    return 0;
}

void initializeWindow() {
    const int screenWidth = 1400;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "University Management System");
    SetTargetFPS(60);
}

void runMainLoop(AppState& state) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (state.currentScreen) {
            case Screen::LOGIN:
                handleLogin(state);
                break;
            case Screen::MENU:
                handleMenu(state);
                break;
            case Screen::STUDENT_MENU:
                handleStudentMenu(state);
                break;
            case Screen::COURSE_MENU:
                handleCourseMenu(state);
                break;
            case Screen::FACULTY_MENU:
                handleFacultyMenu(state);
                break;
            case Screen::ADD_STUDENT:
                handleAddStudent(state);
                break;
            case Screen::DISPLAY_STUDENTS:
                handleDisplayStudents(state);
                break;
            case Screen::UPDATE_STUDENT:
                handleUpdateStudent(state);
                break;
            case Screen::DELETE_STUDENT:
                handleDeleteStudent(state);
                break;
            case Screen::ADD_COURSE:
                handleAddCourse(state);
                break;
            case Screen::DISPLAY_COURSES:
                handleDisplayCourses(state);
                break;
            case Screen::UPDATE_COURSE:
                handleUpdateCourse(state);
                break;
            case Screen::DELETE_COURSE:
                handleDeleteCourse(state);
                break;
            case Screen::ADD_FACULTY:
                handleAddFaculty(state);
                break;
            case Screen::DISPLAY_FACULTY:
                handleDisplayFaculty(state);
                break;
            case Screen::UPDATE_FACULTY:
                handleUpdateFaculty(state);
                break;
            case Screen::DELETE_FACULTY:
                handleDeleteFaculty(state);
                break;
            case Screen::TAKE_ATTENDANCE:
                handleTakeAttendance(state);
                break;
            case Screen::DISPLAY_ATTENDANCE:
                handleDisplayAttendance(state);
                break;
        }

        EndDrawing();
    }
}