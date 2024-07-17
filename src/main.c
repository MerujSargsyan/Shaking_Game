#include <raylib.h>

int main(void) {
    SetTargetFPS(60);

    InitWindow(500, 500, "Shaking Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
