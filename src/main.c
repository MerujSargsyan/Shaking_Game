#include <raylib.h>
// TODO: delta time

int gravity = 1;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 1000;

typedef struct Velocity {
    int x;
    int y;
} Velocity;

typedef struct Accel {
    int x;
    int y;
} Accel;

typedef struct Circle {
    int x;
    int y;
    float r;
    Velocity vel;
    Color col;
    Accel accl;
} Circle;

void update_shapes(Circle* c) {
    c->x += c->vel.x;
    c->y += c->vel.y;
    if(c->y >= WINDOW_HEIGHT) {
        c->vel.y = -10; // bounce factor
        c->accl.y = -1;
    } else if(c->y <= 0) {
        c->vel.y = 10; // bounce factor
        c->accl.y = 1;
    }
    if(c->x >= WINDOW_WIDTH) {
        c->vel.x = -10; // bounce factor
        c->accl.x = -1;
    } else if(c->x <= 0) {
        c->vel.x = 10; // bounce factor
        c->accl.x = 1;
    }
    c->vel.x += c->accl.x;
    c->vel.y += c->accl.y;
}

int main(void) {
    SetTargetFPS(60);
    Circle c;
    c.x = 250;
    c.y = 250;
    c.r = 50.0f;
    c.vel.x = 0;
    c.vel.y = 0;
    c.accl.x = 0;
    c.accl.y = 1;
    c.col = BLACK;

    Circle c2;
    c2.x = 0;
    c2.y = WINDOW_HEIGHT/2;
    c2.r = 50.0f;
    c2.vel.x = 0;
    c2.vel.y = 0;
    c2.accl.x = 1;
    c2.accl.y = 0;
    c2.col = BLUE;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shaking Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        update_shapes(&c);
        DrawCircle(c.x, c.y, c.r, c.col);
        update_shapes(&c2);
        DrawCircle(c2.x, c2.y, c2.r, c2.col);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
