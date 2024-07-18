#include <raylib.h>
#include <stdio.h>
// TODO: delta time

int gravity = 1;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 1000;

typedef struct Circle {
    Vector2 pos;
    Vector2 vel;
    Vector2 accl;
    float r;
    Color col;
} Circle;

void update_shapes(Circle* c) {
    c->pos.x += c->vel.x;
    c->pos.y += c->vel.y;
    if(c->pos.y >= WINDOW_HEIGHT) {
        c->vel.y = -10; // bounce factor
        c->accl.y = -1;
    } else if(c->pos.y <= 0) {
        c->vel.y = 10; // bounce factor
        c->accl.y = 1;
    }
    if(c->pos.x >= WINDOW_WIDTH) {
        c->vel.x = -10; // bounce factor
        c->accl.x = -1;
    } else if(c->pos.x <= 0) {
        c->vel.x = 10; // bounce factor
        c->accl.x = 1;
    }
    c->vel.x += c->accl.x;
    c->vel.y += c->accl.y;
}

int main(void) {
    SetTargetFPS(60);
    Circle c;
    c.pos.x = 250;
    c.pos.y = 250;
    c.r = 50.0f;
    c.vel.x = 0;
    c.vel.y = 0;
    c.accl.x = 0;
    c.accl.y = 1;
    c.col = BLACK;

    Circle c2;
    c2.pos.x = 0;
    c2.pos.y = WINDOW_HEIGHT/2;
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
        update_shapes(&c2);
        if(CheckCollisionCircles(c.pos, c.r, c2.pos, c2.r)) {
            printf("touching");
        }
        DrawCircle(c.pos.x, c.pos.y, c.r, c.col);
        DrawCircle(c2.pos.x, c2.pos.y, c2.r, c2.col);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
