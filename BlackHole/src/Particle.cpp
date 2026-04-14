#include "Particle.hpp"
#include <raymath.h>

Particle::Particle(Vector2 position, Vector2 vel, float r, Color c){
    pos = position;
    velocity = vel;
    radius = r;
    color = c;
}

Particle::Particle(Vector2 position, float m, Vector2 vel, float r, Color c){
    pos = position;
    velocity = vel;
    radius = r;
    mass = m;
    color = c;
}

Particle::Particle(){
    pos = {400, 300};
    velocity = {100.0f, 100.0f};
    mass = 50;
    color = WHITE;
    radius = 10;
}

void Particle::Update(const Particle& black_hole){
    if(this->mass > 1000.0f) return;

    pos = Vector2Add(pos, Vector2Scale(velocity, GetFrameTime()));
    float dist = Vector2Distance(pos, black_hole.pos);
    Vector2 direction = Vector2Normalize(Vector2Subtract(black_hole.pos, this->pos));
    float acc = (6.674e-11f * black_hole.mass) / (dist*dist+10.0f);
    velocity = Vector2Add(velocity, Vector2Scale(direction, acc * GetFrameTime()));

    if(dist < black_hole.radius){
        active = false;
        return;
    }
}

void Particle::circularOrbit(const Particle& black_hole){
    
}

void Particle::Draw(){
    if(active){
        DrawCircleV(pos, radius, color);
    }
}