#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include <stdio.h>
#include <raymath.h>

typedef struct Circle {
    int mass;
    Vector2 pos;
    Vector2 vel;
    Vector2 accl;
    float rad;
    Color col;
} Circle;

Circle get_circle(int mass, Vector2 pos, Vector2 vel, Vector2 acc, float rad, Color col);
void simulate_physics(Circle* c1, Circle* c2);
void print_vec(Vector2 v);

#endif
