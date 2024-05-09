#include "Simulation.h"
#include <iostream>




Simulation::Simulation(){
}

void Simulation:: BeginSim(){
    SetTraceLogLevel(LOG_NONE);
    // InitWindow(GetScreenWidth(),GetScreenHeight(), "Gravity");
    int cellSize = 40;
    int cellCount =40;
    int offset = 75;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount,"Gravity");


    
    
    skip = firstClick = true;
    float size = 10.0f;

    while (!WindowShouldClose()) {
        if(IsKeyReleased(KEY_NINE)){
            DrawRectangle(200,200,10,100,BLACK);
        }

        SetTargetFPS(60);
        float mousePosX = -100.0f;
        float mousePosY = -100.0f;

        float mousePosX2 = -100.0f;
        float mousePosY2 = -100.0f;

        if(IsKeyReleased(KEY_ONE)){
            size = 10.0f;
        }
        if(IsKeyReleased(KEY_TWO)){
            size = 20.0f;
        }
        else if(IsKeyReleased(KEY_THREE)){
            size = 30.0f;
        }
        

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            mousePosX = GetMouseX();
            mousePosY = GetMouseY();


            if(firstClick){
                circles.push_back({{mousePosX,mousePosY}, size, {0.0f,0.0f}, 0.0f});
                mousePosX2 = GetMouseX();
                mousePosY2 = GetMouseY();
                firstClick = false;
                skip = true;
                skips.push_back(true);
            }
            else{
                float x = circles.back().pos.x;
                float y = circles.back().pos.y;
                
                glm::vec2 normalizedVector(mousePosX-x,mousePosY-y);
                glm::normalize(normalizedVector);
                direction.push_back({(mousePosX - x) / 60,(mousePosY - y) / 60}); 

                firstClick = true;
                skips.back() = false;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);     
        PlanetGrav();
        Movememnt();
        DrawMovement();        
        EndDrawing();
    }

    CloseWindow();
}


void Simulation::Gravity(){
    int i = 0;
    for(auto& circle : circles){
            if(!skips[i]){
                circle.velocity += _gravity;
                circle.pos.y += circle.velocity;
            }
        i++;
        }
}


void Simulation::Movememnt(){
    int i = 0;
    for(auto& circle : circles){
            if(!skips[i]){
                circle.pos.y += direction[i].y;
                circle.pos.x += direction[i].x;
            }
        i++;
        }
}



void Simulation::PlanetGrav(){
    for(int i = 0; i < direction.size(); i++){
        for(int j = 0; j < direction.size();j++){
            if(!skips[j] && i != j ){
                float distance = glm::length(circles[i].pos - circles[j].pos) * 100;
                float mass1 = circles[i].size;
                float mass2 = circles[j].size;
                glm::vec2 dirVector = circles[i].pos - circles[j].pos;
                dirVector = glm::normalize(dirVector);

                float force = GravConstant * (mass1 * mass2 / distance * distance);
                float ACC = force / circles[j].size;
                dirVector = dirVector * ACC;

                direction[j].x = direction[j].x + dirVector.x / 60 ;
                direction[j].y = direction[j].y + dirVector.y / 60;
            }
        }
    }
}

















void Simulation::DrawMovement(){
    int i = 0;
    for(const auto& circle : circles){
        if(!skips[i]){
            DrawCircle(circle.pos.x,circle.pos.y,circle.size,RED);
        } 
        i++;
       }
}







