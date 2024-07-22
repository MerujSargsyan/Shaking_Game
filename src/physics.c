#include <physics.h>

Circle get_circle(int mass, Vector2 pos, Vector2 vel, Vector2 acc, float rad, Color col) {
    Circle c = {mass, pos, vel, acc, rad, col};
    return c;
}

void simulate_physics(Circle* c1, Circle* c2) {
    Vector2 diff = Vector2Subtract(c1->vel, c2->vel);
    print_vec(diff);
    c2->vel = diff;
}

void print_vec(Vector2 v) {
    printf("x: %f, y: %f\n", v.x, v.y);
}
