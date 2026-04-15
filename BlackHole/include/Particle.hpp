#pragma once
#include "raylib.h"
#include <raymath.h>

class Particle{
    public:
        Vector2 pos;
        Vector2 prevPos;
        Vector2 velocity;
        float radius;
        float mass;
        Color color;
        bool active = true;

        Particle();
        Particle(Vector2 position, Vector2 vel, float r, Color c);
        Particle(Vector2 position, float m, Vector2 vel, float r, Color c);
        void Update(const Particle& black_hole);
        void Draw();
};
