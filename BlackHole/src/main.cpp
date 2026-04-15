#include "raylib.h"
#include "Particle.hpp"
#include <vector>
#include <random>

int main(){
    std::vector <Particle> stars;
    InitWindow(800, 600, "Stanford Project: Black Hole Sim");
    SetTargetFPS(120);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distPos(400.0f, 550.0f);
    std::uniform_real_distribution<float> distVel(-100.0f, 100.0f);
    std::uniform_real_distribution<float> distRad(5.0f, 15.0f);
    std::uniform_real_distribution<float> distMass(50.0f, 500.0f);
    Particle black_hole({100, 300}, 1e15*100, {0, 0}, 100, WHITE);
    for(int i = 0; i < 10; i++){
            Vector2 randomPos = {distPos(gen), distPos(gen)};
            //Vector2 randomVel = {distVel(gen), distVel(gen)};
            float mass = distMass(gen);
            float rad = distRad(gen);
            
            stars.push_back(Particle(randomPos, mass, {0,0}, rad, RED));
        }
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(BLACK);
        black_hole.Draw();
        for(Particle& s: stars){
            s.Update(black_hole);
            s.Draw();        
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}