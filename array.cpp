#include "raylib.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 650;
    const int ARRAY_SIZE = 10;

    InitWindow(screenWidth, screenHeight, "Array Manipulator - Insert / Delete / Search");
    SetTargetFPS(60);

    // Data
    int data[ARRAY_SIZE] = { 0 };
    int selectedIndex = 0;

    // Input handling
    std::string inputText = "";
    bool inputActive = false;
    bool inputError = false;                 // Shows red border when input is invalid
    std::vector<int> searchResults;          // Indices that match the search value

    // UI rectangles (carefully positioned – no overlaps)
    Rectangle inputBox = { 250, 120, 300, 50 };
    Rectangle btnPlus = { 570, 120, 50, 50 };
    Rectangle btnMinus = { 630, 120, 50, 50 };

    Rectangle btnInsert = { 150, 220, 160, 60 };
    Rectangle btnDelete = { 340, 220, 160, 60 };
    Rectangle btnSearch = { 530, 220, 160, 60 };

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        // ------------------------------------------------------------
        // Mouse click handling
        // ------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Activate/deactivate input box
            if (CheckCollisionPointRec(mouse, inputBox))
                inputActive = true;
            else
                inputActive = false;

            // Index navigation
            if (CheckCollisionPointRec(mouse, btnPlus))
                selectedIndex = (selectedIndex + 1) % ARRAY_SIZE;
            if (CheckCollisionPointRec(mouse, btnMinus))
                selectedIndex = (selectedIndex - 1 + ARRAY_SIZE) % ARRAY_SIZE;

            // Operations
            if (CheckCollisionPointRec(mouse, btnInsert))
            {
                if (!inputText.empty() && !inputError)
                {
                    int value = std::stoi(inputText);
                    data[selectedIndex] = value;
                }
            }

            if (CheckCollisionPointRec(mouse, btnDelete))
            {
                data[selectedIndex] = 0;
            }

            if (CheckCollisionPointRec(mouse, btnSearch))
            {
                searchResults.clear();
                if (!inputText.empty() && !inputError)
                {
                    int target = std::stoi(inputText);
                    for (int i = 0; i < ARRAY_SIZE; ++i)
                        if (data[i] == target)
                            searchResults.push_back(i);
                }
            }
        }

        // ------------------------------------------------------------
        // Keyboard navigation (arrow keys)
        // ------------------------------------------------------------
        if (IsKeyPressed(KEY_RIGHT))  selectedIndex = (selectedIndex + 1) % ARRAY_SIZE;
        if (IsKeyPressed(KEY_LEFT))   selectedIndex = (selectedIndex - 1 + ARRAY_SIZE) % ARRAY_SIZE;

        // ------------------------------------------------------------
        // Text input + validation
        // ------------------------------------------------------------
        if (inputActive)
        {
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((key >= '0' && key <= '9') || (key == '-' && inputText.empty()))
                    inputText += (char)key;
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty())
                inputText.pop_back();
        }

        // Validate input (only digits + optional leading minus)
        inputError = false;
        if (!inputText.empty())
        {
            bool valid = true;
            if (inputText[0] == '-') {
                if (inputText.size() == 1) valid = false;               // lone "-"
                else for (size_t i = 1; i < inputText.size(); ++i)
                    if (!isdigit(inputText[i])) { valid = false; break; }
            }
            else {
                for (char c : inputText)
                    if (!isdigit(c)) { valid = false; break; }
            }
            inputError = !valid;
        }

        // Clear search highlights when selection changes
        static int lastSelected = -1;
        if (selectedIndex != lastSelected)
        {
            searchResults.clear();
            lastSelected = selectedIndex;
        }

        // ------------------------------------------------------------
        // Drawing
        // ------------------------------------------------------------
        BeginDrawing();
        ClearBackground(Color{ 30, 30, 45, 255 });

        // Title
        DrawText("Array Manipulator", 30, 30, 40, Color{ 200, 220, 255, 255 });

        // ---- Array display (centered) ----
        const int cellXStart = 100;
        const int cellY = 340;
        const int cellSize = 60;
        const int spacing = 15;

        DrawText("Array:", cellXStart, cellY - 50, 24, WHITE);

        for (int i = 0; i < ARRAY_SIZE; ++i)
        {
            int x = cellXStart + i * (cellSize + spacing);
            int y = cellY;

            // Background fill for search results
            if (std::find(searchResults.begin(), searchResults.end(), i) != searchResults.end())
                DrawRectangle(x, y, cellSize, cellSize, Fade(RED, 0.4f));

            // Selection highlight (yellow border)
            Color border = (i == selectedIndex) ? YELLOW : Color{ 180, 180, 180, 255 };
            float thickness = (i == selectedIndex) ? 4.0f : 2.0f;
            DrawRectangleLinesEx(Rectangle{ (float)x, (float)y, (float)cellSize, (float)cellSize }, thickness, border);

            // Value
            DrawText(TextFormat("%d", data[i]), x + 18, y + 15, 28, WHITE);

            // Index label below
            DrawText(TextFormat("%d", i), x + 24, y + cellSize + 8, 18, Color{ 160, 160, 160, 255 });
        }

        // ---- Input box ----
        DrawRectangleRec(inputBox, LIGHTGRAY);
        Color inputBorder = inputActive ? BLUE : (inputError ? RED : DARKGRAY);
        DrawRectangleLinesEx(inputBox, 3, inputBorder);

        std::string displayText = inputText.empty() ? "Enter number..." : inputText;
        Color textCol = inputText.empty() ? GRAY : BLACK;
        DrawText(displayText.c_str(), (int)inputBox.x + 15, (int)inputBox.y + 12, 24, textCol);

        // Blinking cursor
        if (inputActive && ((int)(GetTime() * 2) % 2 == 0))
        {
            int cursorX = (int)inputBox.x + 15 + MeasureText(inputText.c_str(), 24);
            DrawRectangle(cursorX, (int)inputBox.y + 8, 2, 34, BLACK);
        }

        // ---- Navigation buttons ----
        bool plusHover = CheckCollisionPointRec(mouse, btnPlus);
        bool minusHover = CheckCollisionPointRec(mouse, btnMinus);

        DrawRectangleRec(btnPlus, plusHover ? SKYBLUE : BLUE);
        DrawRectangleRec(btnMinus, minusHover ? SKYBLUE : BLUE);
        DrawText("+", (int)btnPlus.x + 18, (int)btnPlus.y + 10, 30, WHITE);
        DrawText("-", (int)btnMinus.x + 18, (int)btnMinus.y + 10, 30, WHITE);

        // ---- Operation buttons ----
        bool insertHover = CheckCollisionPointRec(mouse, btnInsert);
        bool deleteHover = CheckCollisionPointRec(mouse, btnDelete);
        bool searchHover = CheckCollisionPointRec(mouse, btnSearch);

        DrawRectangleRec(btnInsert, insertHover ? LIME : GREEN);
       DrawRectangleRec(btnDelete, deleteHover ? MAROON : RED);
        DrawRectangleRec(btnSearch, searchHover ? VIOLET : PURPLE);

        DrawText("Insert", (int)btnInsert.x + 25, (int)btnInsert.y + 18, 24, WHITE);
        DrawText("Delete", (int)btnDelete.x + 25, (int)btnDelete.y + 18, 24, WHITE);
        DrawText("Search", (int)btnSearch.x + 28, (int)btnSearch.y + 18, 24, WHITE);

        // Instructions
        DrawText("Use [+]/[-] buttons or ← → arrows to change selected index", 30, 560, 20, Color{ 180,180,200,255 });
        DrawText("Insert replaces value | Delete sets to 0 | Search highlights matches", 30, 590, 20, Color{ 180,180,200,255 });

        EndDrawing();
    }

    CloseWindow();
    return 0;
}