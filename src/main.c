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

void update_shapes(Circle* c, float deltaTime) {
    c->pos.x += c->vel.x * deltaTime;
    c->pos.y += c->vel.y * deltaTime;
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
    c->vel.x += c->accl.x * deltaTime;
    c->vel.y += c->accl.y * deltaTime;
}

Circle get_circle(Vector2 pos, float rad, Vector2 vel, Vector2 acc, Color col) {
    Circle c = {pos, vel, acc, rad, col};
    return c;
}

int main(void) {
    SetTargetFPS(60);
    Vector2 vel = {0, 20};
    Vector2 pos = {250, 250};
    Vector2 acc = {0, 1};
    float r = 60.0f;
    Circle c = get_circle(pos, r, vel, acc, BLACK);

    Vector2 vel2 = {20, 0};
    Vector2 pos2 = {0, WINDOW_HEIGHT/2};
    Vector2 acc2 = {0, 0};
    float r2 = 50.0f;
    Circle c2 = get_circle(pos2, r2, vel2, acc2, BLUE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shaking Game");
    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        if(CheckCollisionCircles(c.pos, c.r, c2.pos, c2.r)) {
            c.col = RED;
        } else {c.col = BLACK;}
        ClearBackground(RAYWHITE);
        update_shapes(&c, deltaTime);
        update_shapes(&c2, deltaTime);
        DrawCircle(c.pos.x, c.pos.y, c.r, c.col);
        DrawCircle(c2.pos.x, c2.pos.y, c2.r, c2.col);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
