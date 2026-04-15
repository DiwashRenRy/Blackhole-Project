#include "raylib.h"
#include "Particle.hpp"
#include <random>

int main(){
    std::vector <Particle> stars;
    InitWindow(1600, 1200, "Stanford Project: Black Hole Sim");
    SetTargetFPS(120);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distPosX(650.0f, 750.0f);
    std::uniform_real_distribution<float> distPosY(50.0f, 1100.0f);
    std::uniform_real_distribution<float> distVel(-100.0f, 100.0f);
    std::uniform_real_distribution<float> distRad(5.0f, 15.0f);
    std::uniform_real_distribution<float> distMass(50.0f, 500.0f);
    Particle black_hole({800, 600}, 1e17, {0, 0}, 100, WHITE);
    for(int i = 0; i < 10; i++){
            Vector2 randomPos = {distPosX(gen), distPosY(gen)};
            float mass = distMass(gen);
            float rad = distRad(gen);
            float dist = Vector2Distance(randomPos, black_hole.pos);
            float dy = randomPos.y - black_hole.pos.y;
            float dx = randomPos.x - black_hole.pos.x;
            float velocityX = sqrt((6.674e-11*1e17)/dist) * (-dy/dist) * 1.3;
            float velocityY = sqrt((6.674e-11*1e17)/dist) * (dx/dist) * 1.3;
            stars.push_back(Particle(randomPos, mass, {velocityX, velocityY}, rad, RED));
        }
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(BLACK);
        black_hole.Draw();
        DrawCircle(800, 600, 90, BLACK);
        for(Particle& s: stars){
            s.Update(black_hole);
            s.Draw();        
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}