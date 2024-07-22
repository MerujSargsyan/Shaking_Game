#include <stdio.h>
#include <physics.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 1000;
const float PHYSICS_TIME_STEP = 1.0f / 60.0f; // 60 checks per second



void update_shapes(Circle* c, float deltaTime) {
    c->pos.x += c->vel.x * deltaTime;
    c->pos.y += c->vel.y * deltaTime;
    
    if(c->pos.y >= WINDOW_HEIGHT || c->pos.y <= 0) {
        c->vel.y = -c->vel.y;
    }

    if(c->pos.x >= WINDOW_WIDTH || c->pos.x <= 0) {
        c->vel.x = -c->vel.x;
    }

    c->vel.x += c->accl.x * deltaTime;
    c->vel.y += c->accl.y * deltaTime;
}



int main(void) {
    SetTargetFPS(60);
    Vector2 vel = {0, 100};
    Vector2 pos = {250, 250};
    Vector2 acc = {0, 0};
    Circle c = get_circle(50, pos, vel, acc, 60.0f, BLACK);

    Vector2 vel2 = {100, 0};
    Vector2 pos2 = {0, WINDOW_HEIGHT/2};
    Vector2 acc2 = {0, 0};
    Circle c2 = get_circle(30, pos2, vel2, acc2, 50.0f, BLUE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shaking Game");

    float accumulator = 0.0f;
    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        accumulator += deltaTime;

        while(accumulator >= PHYSICS_TIME_STEP) {
            if(CheckCollisionCircles(c.pos, c.rad, c2.pos, c2.rad)) {
                simulate_physics(&c, &c2);
            }

            update_shapes(&c, deltaTime);
            update_shapes(&c2, deltaTime);

            accumulator -= PHYSICS_TIME_STEP;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(c.pos.x, c.pos.y, c.rad, c.col);
        DrawCircle(c2.pos.x, c2.pos.y, c2.rad, c2.col);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
