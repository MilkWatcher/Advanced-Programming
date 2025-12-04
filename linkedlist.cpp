#include "raylib.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

struct Node {
    int value;
    Node* next = nullptr;
};

int main() {
    const int screenWidth = 900;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Singly Linked List Manipulator");
    SetTargetFPS(60);

    Node* head = nullptr;
    Node* selected = nullptr;
    std::string inputText = "";
    bool inputActive = false;
    bool inputError = false;
    std::vector<Node*> searchHighlights;

    // UI rectangles (no overlaps)
    Rectangle inputBox = { 250, 120, 300, 50 };
    Rectangle nextButton = { 570, 120, 100, 50 };
    Rectangle prevButton = { 680, 120, 100, 50 };
    Rectangle insertButton = { 150, 220, 160, 60 };
    Rectangle deleteButton = { 340, 220, 160, 60 };
    Rectangle searchButton = { 530, 220, 160, 60 };

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        // Mouse click handling
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Activate/deactivate input box
            if (CheckCollisionPointRec(mouse, inputBox)) {
                inputActive = true;
            }
            else {
                inputActive = false;
            }

            // Navigation
            if (CheckCollisionPointRec(mouse, nextButton)) {
                if (selected && selected->next) {
                    selected = selected->next;
                    searchHighlights.clear();
                }
            }
            if (CheckCollisionPointRec(mouse, prevButton)) {
                if (selected && selected != head) {
                    Node* temp = head;
                    while (temp->next != selected) {
                        temp = temp->next;
                    }
                    selected = temp;
                    searchHighlights.clear();
                }
            }

            // Operations
            if (CheckCollisionPointRec(mouse, insertButton)) {
                if (!inputText.empty() && !inputError) {
                    int val = std::stoi(inputText);
                    Node* newNode = new Node{ val, nullptr };
                    if (head == nullptr) {
                        head = selected = newNode;
                    }
                    else if (selected == head) {
                        // Insert before head
                        newNode->next = head;
                        head = newNode;
                    }
                    else {
                        // Insert after selected
                        newNode->next = selected->next;
                        selected->next = newNode;
                    }
                }
            }

            if (CheckCollisionPointRec(mouse, deleteButton)) {
                if (selected != nullptr) {
                    Node* toDelete = selected;
                    if (selected == head) {
                        head = selected->next;
                        selected = head;
                    }
                    else {
                        Node* prev = head;
                        while (prev->next != selected) {
                            prev = prev->next;
                        }
                        prev->next = selected->next;
                        if (selected->next) {
                            selected = selected->next;
                        }
                        else {
                            selected = prev;
                        }
                    }
                    delete toDelete;
                    searchHighlights.clear();
                }
            }

            if (CheckCollisionPointRec(mouse, searchButton)) {
                searchHighlights.clear();
                if (!inputText.empty() && !inputError) {
                    int target = std::stoi(inputText);
                    Node* temp = head;
                    while (temp) {
                        if (temp->value == target) {
                            searchHighlights.push_back(temp);
                        }
                        temp = temp->next;
                    }
                }
            }
        }

        // Keyboard navigation
        if (IsKeyPressed(KEY_RIGHT)) {
            if (selected && selected->next) {
                selected = selected->next;
                searchHighlights.clear();
            }
        }
        if (IsKeyPressed(KEY_LEFT)) {
            if (selected && selected != head) {
                Node* temp = head;
                while (temp->next != selected) {
                    temp = temp->next;
                }
                selected = temp;
                searchHighlights.clear();
            }
        }

        // Text input + validation
        if (inputActive) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= '0' && key <= '9') || (key == '-' && inputText.empty())) {
                    inputText += (char)key;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
                inputText.pop_back();
            }
        }

        // Validate input
        inputError = false;
        if (!inputText.empty()) {
            bool valid = true;
            if (inputText[0] == '-') {
                if (inputText.size() == 1) valid = false;
                else {
                    for (size_t i = 1; i < inputText.size(); ++i) {
                        if (!isdigit(inputText[i])) {
                            valid = false;
                            break;
                        }
                    }
                }
            }
            else {
                for (char c : inputText) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }
            }
            inputError = !valid;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(Color{ 30, 30, 45, 255 });

        // Title
        DrawText("Singly Linked List Manipulator", 30, 30, 40, Color{ 200, 220, 255, 255 });

        // Linked list display
        if (head == nullptr) {
            DrawText("Empty Linked List", 300, 340, 30, WHITE);
        }
        else {
            Node* temp = head;
            int x = 100;
            const int y = 340;
            const int width = 80;
            const int height = 60;
            const int spacing = 80;
            bool isFirst = true;

            while (temp) {
                // Fill for search highlights
                Color fill = { 0, 0, 0, 0 };
                if (std::find(searchHighlights.begin(), searchHighlights.end(), temp) != searchHighlights.end()) {
                    fill = Fade(RED, 0.4f);
                }
                DrawRectangle(x, y, width, height, fill);

                // Border for selection
                Color border = (temp == selected) ? YELLOW : Color{ 180, 180, 180, 255 };
                float thickness = (temp == selected) ? 4.0f : 2.0f;
                DrawRectangleLinesEx(Rectangle{ (float)x, (float)y, (float)width, (float)height }, thickness, border);

                // Value
                DrawText(TextFormat("%d", temp->value), x + 20, y + 20, 24, WHITE);

                // HEAD label
                if (isFirst) {
                    DrawText("HEAD", x + 15, y - 30, 20, GREEN);
                    isFirst = false;
                }

                // Arrow to next
                if (temp->next) {
                    int arrowStartX = x + width;
                    int arrowEndX = x + width + spacing;
                    DrawLine(arrowStartX, y + height / 2, arrowEndX, y + height / 2, WHITE);
                    DrawTriangle(Vector2{ (float)arrowEndX - 10, (float)y + height / 2 - 5 },
                        Vector2{ (float)arrowEndX, (float)y + height / 2 },
                        Vector2{ (float)arrowEndX - 10, (float)y + height / 2 + 5 }, WHITE);
                }

                x += width + spacing;
                temp = temp->next;
            }
        }

        // Input box
        DrawRectangleRec(inputBox, LIGHTGRAY);
        Color inputBorder = inputActive ? BLUE : (inputError ? RED : DARKGRAY);
        DrawRectangleLinesEx(inputBox, 3, inputBorder);

        std::string displayText = inputText.empty() ? "Enter number..." : inputText;
        Color textCol = inputText.empty() ? GRAY : BLACK;
        DrawText(displayText.c_str(), (int)inputBox.x + 15, (int)inputBox.y + 12, 24, textCol);

        // Blinking cursor
        if (inputActive && ((int)(GetTime() * 2) % 2 == 0)) {
            int cursorX = (int)inputBox.x + 15 + MeasureText(inputText.c_str(), 24);
            DrawRectangle(cursorX, (int)inputBox.y + 8, 2, 34, BLACK);
        }

        // Navigation buttons
        bool nextHover = CheckCollisionPointRec(mouse, nextButton);
        bool prevHover = CheckCollisionPointRec(mouse, prevButton);

        DrawRectangleRec(nextButton, nextHover ? SKYBLUE : BLUE);
        DrawRectangleRec(prevButton, prevHover ? SKYBLUE : BLUE);
        DrawText("Next", (int)nextButton.x + 20, (int)nextButton.y + 12, 24, WHITE);
        DrawText("Prev", (int)prevButton.x + 20, (int)prevButton.y + 12, 24, WHITE);

        // Operation buttons
        bool insertHover = CheckCollisionPointRec(mouse, insertButton);
        bool deleteHover = CheckCollisionPointRec(mouse, deleteButton);
        bool searchHover = CheckCollisionPointRec(mouse, searchButton);

        DrawRectangleRec(insertButton, insertHover ? LIME : GREEN);
        DrawRectangleRec(deleteButton, deleteHover ? MAROON : RED);
        DrawRectangleRec(searchButton, searchHover ? VIOLET : PURPLE);

        DrawText("Insert", (int)insertButton.x + 25, (int)insertButton.y + 18, 24, WHITE);
        DrawText("Delete", (int)deleteButton.x + 25, (int)deleteButton.y + 18, 24, WHITE);
        DrawText("Search", (int)searchButton.x + 28, (int)searchButton.y + 18, 24, WHITE);

        // Instructions
        DrawText("Use Next/Prev buttons or ← → arrows to navigate selection", 30, 530, 20, Color{ 180, 180, 200, 255 });
        DrawText("Insert: before head or after selected", 30, 560, 20, Color{ 180, 180, 200, 255 });
        DrawText("Delete: remove selected, move to next/prev", 30, 590, 20, Color{ 180, 180, 200, 255 });
        DrawText("Search: highlights matches, clears on navigation", 30, 620, 20, Color{ 180, 180, 200, 255 });

        EndDrawing();
    }

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    CloseWindow();
    return 0;
}