#include "raylib.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// ====================================================================
// Node structure
// ====================================================================
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node(int val, Node* p = nullptr) : value(val), parent(p) {}
};

// ====================================================================
// BST class - all functions properly declared and defined
// ====================================================================
class BST {
public:
    Node* root = nullptr;
    Node* selected = nullptr;
    std::vector<Node*> searchHighlights;

    // Insert a value into BST and select the new node
    void insert(int val) {
        if (!root) {
            root = selected = new Node(val);
            return;
        }

        Node* cur = root;
        Node* par = nullptr;
        while (cur) {
            par = cur;
            if (val < cur->value) cur = cur->left;
            else if (val > cur->value) cur = cur->right;
            else { selected = cur; return; }  // duplicate
        }

        Node* n = new Node(val, par);
        if (val < par->value) par->left = n;
        else par->right = n;
        selected = n;
    }

    // Find minimum node in subtree
    Node* findMin(Node* n) { while (n->left) n = n->left; return n; }

    // Delete selected node (full BST deletion logic)
    void deleteNode(Node* node) {
        if (!node) return;
        Node* par = node->parent;
        Node* rep = nullptr;

        if (!node->left) rep = node->right;
        else if (!node->right) rep = node->left;
        else {
            rep = findMin(node->right);
            Node* sp = rep->parent;
            if (sp != node) {
                sp->left = rep->right;
                if (rep->right) rep->right->parent = sp;
                rep->right = node->right;
                node->right->parent = rep;
            }
            rep->left = node->left;
            node->left->parent = rep;
        }

        if (rep) rep->parent = par;
        if (!par) root = rep;
        else if (par->left == node) par->left = rep;
        else par->right = rep;

        if (selected == node) selected = rep ? rep : (par ? par : root);
        delete node;
    }

    // Search and highlight all matches
    void search(int val) {
        searchHighlights.clear();
        searchRec(root, val);
    }

    void searchRec(Node* n, int val) {
        if (!n) return;
        if (n->value == val) searchHighlights.push_back(n);
        searchRec(n->left, val);
        searchRec(n->right, val);
    }

    // Collect all nodes for cleanup
    void collectAll(Node* n, std::vector<Node*>& v) {
        if (!n) return;
        collectAll(n->left, v);
        v.push_back(n);
        collectAll(n->right, v);
    }
};

// ====================================================================
// Draw tree recursively
// ====================================================================
void drawTree(Node* node, int x, int y, int offset, BST& tree) {
    if (!node) return;

    const int R = 34;
    const int VG = 120;

    if (node->left) {
        DrawLine(x, y, x - offset, y + VG, Color{200,200,220,255});
        drawTree(node->left, x - offset, y + VG, offset / 2, tree);
    }
    if (node->right) {
        DrawLine(x, y, x + offset, y + VG, Color{200,200,220,255});
        drawTree(node->right, x + offset, y + VG, offset / 2, tree);
    }

    // Search highlight
    auto it = std::find(tree.searchHighlights.begin(), tree.searchHighlights.end(), node);
    if (it != tree.searchHighlights.end())
        DrawCircle(x, y, R + 16, Fade(RED, 0.35f));

    // Selection highlight
    Color border = (node == tree.selected) ? YELLOW : Color{180,180,180,255};
    float thick = (node == tree.selected) ? 6.0f : 2.0f;
    DrawCircleLines(x, y, R + 8, border);
    DrawCircleLines(x, y, R + 9, border);

    DrawCircle(x, y, R, Color{45,50,85,255});
    DrawText(TextFormat("%d", node->value), x - 22, y - 20, 38, WHITE);
}

// ====================================================================
// Main
// ====================================================================
int main() {
    const int SW = 1200;
    const int SH = 800;
    InitWindow(SW, SH, "Binary Search Tree Visualizer - Final Fixed");
    SetTargetFPS(60);

    BST tree;
    std::string input = "";
    bool active = false;
    bool err = false;

    // Centered UI
    Rectangle inputBox  = { (SW - 300) / 2, 40, 300, 60 };
    Rectangle btnUp     = { inputBox.x + 320, 40, 90, 60 };
    Rectangle btnLeft   = { btnUp.x + 100, 40, 90, 60 };
    Rectangle btnRight  = { btnLeft.x + 100, 40, 90, 60 };

    Rectangle btnInsert = { 180, 130, 220, 80 };
    Rectangle btnDelete = { SW / 2 - 110, 130, 220, 80 };
    Rectangle btnSearch = { SW - 400, 130, 220, 80 };

    while (!WindowShouldClose()) {
        Vector2 m = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            active = CheckCollisionPointRec(m, inputBox);

            if (CheckCollisionPointRec(m, btnUp)    && tree.selected && tree.selected->parent) { tree.selected = tree.selected->parent; tree.searchHighlights.clear(); }
            if (CheckCollisionPointRec(m, btnLeft)  && tree.selected && tree.selected->left)  { tree.selected = tree.selected->left;  tree.searchHighlights.clear(); }
            if (CheckCollisionPointRec(m, btnRight) && tree.selected && tree.selected->right) { tree.selected = tree.selected->right; tree.searchHighlights.clear(); }

            if (CheckCollisionPointRec(m, btnInsert) && !input.empty() && !err) { tree.insert(std::stoi(input)); tree.searchHighlights.clear(); }
            if (CheckCollisionPointRec(m, btnDelete) && tree.selected) { tree.deleteNode(tree.selected); tree.searchHighlights.clear(); }
            if (CheckCollisionPointRec(m, btnSearch) && !input.empty() && !err) { tree.search(std::stoi(input)); }
        }

        // Arrow keys
        if (IsKeyPressed(KEY_UP)    && tree.selected && tree.selected->parent) { tree.selected = tree.selected->parent; tree.searchHighlights.clear(); }
        if (IsKeyPressed(KEY_LEFT)  && tree.selected && tree.selected->left)  { tree.selected = tree.selected->left;  tree.searchHighlights.clear(); }
        if (IsKeyPressed(KEY_RIGHT) && tree.selected && tree.selected->right) { tree.selected = tree.selected->right; tree.searchHighlights.clear(); }

        // Input
        if (active) {
            int c = GetCharPressed();
            while (c > 0) {
                if ((c >= '0' && c <= '9') || (c == '-' && input.empty())) input += (char)c;
                c = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !input.empty()) input.pop_back();
        }

        // Validation
        err = false;
        if (!input.empty()) {
            bool ok = true;
            if (input == "-") ok = false;
            else if (input[0] == '-') {
                for (size_t i = 1; i < input.size(); ++i)
                    if (!isdigit(input[i])) ok = false;
            } else {
                for (char c : input) if (!isdigit(c)) ok = false;
            }
            err = !ok;
        }

        // === DRAW ===
        BeginDrawing();
        ClearBackground(Color{18, 22, 38, 255});

        // Tree starts lower (y=280)
        if (tree.root)
            drawTree(tree.root, SW/2, 280, 340, tree);
        else
            DrawText("BST is empty — enter a value and click INSERT", SW/2 - 280, SH/2 - 30, 32, Color{140,150,180,255});

        // Top panel
        DrawRectangle(0, 0, SW, 240, Color{28, 33, 58, 255});

        // Input box
        DrawRectangleRec(inputBox, Color{220,220,230,255});
        DrawRectangleLinesEx(inputBox, 4, active ? SKYBLUE : (err ? RED : Color{100,100,120,255}));
        const char* txt = input.empty() ? "Enter value..." : input.c_str();
        DrawText(txt, (int)inputBox.x + 25, (int)inputBox.y + 18, 28, input.empty() ? GRAY : BLACK);
        if (active && ((int)(GetTime()*2)%2 == 0)) {
            int cx = (int)inputBox.x + 25 + MeasureText(input.c_str(), 28);
            DrawRectangle(cx, (int)inputBox.y + 12, 3, 36, BLACK);
        }

        // Navigation buttons
        bool hu = CheckCollisionPointRec(m, btnUp);
        bool hl = CheckCollisionPointRec(m, btnLeft);
        bool hr = CheckCollisionPointRec(m, btnRight);
        DrawRectangleRec(btnUp,    hu ? Color{100,180,255,255} : Color{60,120,200,255});
        DrawRectangleRec(btnLeft,  hl ? Color{100,180,255,255} : Color{60,120,200,255});
        DrawRectangleRec(btnRight, hr ? Color{100,180,255,255} : Color{60,120,200,255});
        DrawText("Up",    btnUp.x    + 25, btnUp.y    + 18, 28, WHITE);
        DrawText("Left",  btnLeft.x  + 15, btnLeft.y  + 18, 28, WHITE);
        DrawText("Right", btnRight.x + 12, btnRight.y + 18, 28, WHITE);

        // Operation buttons
        bool hi = CheckCollisionPointRec(m, btnInsert);
        bool hd = CheckCollisionPointRec(m, btnDelete);
        bool hs = CheckCollisionPointRec(m, btnSearch);

        DrawRectangleRec(btnInsert, hi ? LIME : Color{0,180,0,255});
        DrawRectangleRec(btnDelete, hd ? Color{200,50,50,255} : Color{180,30,30,255});
        DrawRectangleRec(btnSearch, hs ? Color{200,100,255,255} : Color{160,60,220,255});

        DrawText("INSERT", btnInsert.x + 45, btnInsert.y + 25, 32, WHITE);
        DrawText("DELETE", btnDelete.x + 45, btnDelete.y + 25, 32, WHITE);
        DrawText("SEARCH", btnSearch.x + 45, btnSearch.y + 25, 32, WHITE);

        // Bottom text
        DrawText("Arrow Keys or Buttons: Up=Parent | Left/Right=Children", 30, SH - 100, 24, Color{180,200,230,255});
        DrawText("Yellow border = Selected | Red glow = Search matches", 30, SH - 60, 24, Color{180,200,230,255});

        EndDrawing();
    }

    // Cleanup
    std::vector<Node*> nodes;
    tree.collectAll(tree.root, nodes);
    for (Node* n : nodes) delete n;

    CloseWindow();
    return 0;
}