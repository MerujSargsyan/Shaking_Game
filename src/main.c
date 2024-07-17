#include <raylib.h>
// TODO: delta time

int gravity = 1;

typedef struct Velocity {
    int x;
    int y;
} Velocity;

typedef struct Circle {
    int x;
    int y;
    float r;
    Velocity vel;
    Color col;
} Circle;

void update_shapes(Circle* c) {
    c->x += c->vel.x;
    c->y += c->vel.y;
    if(c->y >= 800) {
        c->vel.y = -10; // bounce factor
        gravity = -1;
    } else if(c->y <= 0) {
        c->vel.y = 10; // bounce factor
        gravity = 1;
    }
    c->vel.y += gravity;
}

int main(void) {
    SetTargetFPS(60);
    Circle c;
    c.x = 250;
    c.y = 250;
    c.r = 50.0f;
    c.vel.x = 0;
    c.vel.y = 0;
    c.col = BLACK;

    InitWindow(800, 800, "Shaking Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        update_shapes(&c);
        DrawCircle(c.x, c.y, c.r, c.col);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
