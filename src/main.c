#include <raylib.h>

typedef struct Circle {
    int x;
    int y;
    float r;
    Color col;
} Circle;

int main(void) {
    SetTargetFPS(60);
    Circle c;
    c.x = 250;
    c.y = 250;
    c.r = 50.0f;
    c.col = BLACK;

    InitWindow(800, 800, "Shaking Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(c.x, c.y, c.r, c.col);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
