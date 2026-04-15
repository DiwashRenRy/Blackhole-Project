#include "raylib.h"
#include "Particle.hpp"
#include <vector>
#include <random>

int main(){
    std::vector <Particle> stars;
    InitWindow(1600, 1200, "Stanford Project: Black Hole Sim");
    SetTargetFPS(120);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distPosX(700, 1150);
    std::uniform_real_distribution<float> distPosY(50, 750);
    std::uniform_real_distribution<float> distVel(-100.0f, 100.0f);
    std::uniform_real_distribution<float> distRad(5.0f, 15.0f);
    std::uniform_real_distribution<float> distMass(50.0f, 500.0f);
    Particle black_hole({800, 600}, 1e17, {0, 0}, 100, WHITE);
    for(int i = 0; i < 1; i++){
            Vector2 randomPos = {distPosX(gen), distPosY(gen)};
            float mass = distMass(gen);
            float rad = distRad(gen);
            float dist = Vector2Distance(randomPos, black_hole.pos);
            float dy = randomPos.y - black_hole.pos.y;
            float dx = randomPos.x - black_hole.pos.x;
            float velocityX = sqrt((6.674e-11*1e17)/dist) * (-dy/dist) * 1.2;
            float velocityY = sqrt((6.674e-11*1e17)/dist) * (dx/dist) * 1.2;
            stars.push_back(Particle(randomPos, mass, {velocityX, velocityY}, rad, RED));
        }
    while(!WindowShouldClose()){
        
        BeginDrawing();
        //ClearBackground(BLACK);
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