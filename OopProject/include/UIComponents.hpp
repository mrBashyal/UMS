#pragma once
#include "raylib.hpp"
#include <string>
#include <cstring>

bool Button(Rectangle rect, const char* text) {
    bool clicked = false;
    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) clicked = true;
        DrawRectangleRec(rect, LIGHTGRAY);
    } else {
        DrawRectangleRec(rect, GRAY);
    }
    DrawText(text, rect.x + 10, rect.y + 10, 20, BLACK);
    return clicked;
}

void TextInput(char* buffer, int bufferSize, Rectangle rect, bool active) {
    DrawRectangleRec(rect, active ? LIGHTGRAY : DARKGRAY);
    DrawText(buffer, rect.x + 5, rect.y + 5, 20, BLACK);

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            int length = strlen(buffer);
            if (length < bufferSize - 1) {
                buffer[length] = (char)key;
                buffer[length + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            int length = strlen(buffer);
            if (length > 0) buffer[length - 1] = '\0';
        }
    }
}

bool PasswordInput(char* buffer, int bufferSize, Rectangle rect, bool active) {
    DrawRectangleRec(rect, active ? LIGHTGRAY : DARKGRAY);
    std::string masked(buffer, strlen(buffer));
    std::fill(masked.begin(), masked.end(), '*');
    DrawText(masked.c_str(), rect.x + 5, rect.y + 5, 20, BLACK);

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            int length = strlen(buffer);
            if (length < bufferSize - 1) {
                buffer[length] = (char)key;
                buffer[length + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            int length = strlen(buffer);
            if (length > 0) buffer[length - 1] = '\0';
        }
    }
    return true;
}

bool Checkbox(Rectangle rect, bool checked) {
    bool clicked = false;
    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clicked = true;
            checked = !checked;
        }
    }

    DrawRectangleLinesEx(rect, 2, DARKGRAY);
    if (checked) {
        DrawText("P", rect.x + rect.width / 2 - MeasureText("P", 16) / 2, rect.y + rect.height / 2 - 8, 16, Fade(DARKGRAY, 0.8f));    
    }
    return checked;
}

void DateInput(char* buffer, int bufferSize, Rectangle rect, bool active) {
    DrawRectangleRec(rect, active ? LIGHTGRAY : DARKGRAY);
    DrawText(buffer, rect.x + 5, rect.y + 5, 20, BLACK);

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            int length = strlen(buffer);
            if (length < bufferSize - 1) {
                buffer[length] = (char)key;
                buffer[length + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            int length = strlen(buffer);
            if (length > 0) buffer[length - 1] = '\0';
        }
    }
}