#include <iostream>
#include <raylib.h>
#include <vector>
#include <glm/glm.hpp>
#include "Circle.h"
#include <unistd.h>
#include <string>



class Simulation{
    public:
    std::vector<Circle> circles;
    float _gravity = 0.02f;
    float GravConstant = 1.0f;
    bool firstClick;
    bool skip;
    std::vector<Vector2> direction;
    std::vector<bool> skips;
    bool EndInstruction = false;

    Simulation();
    void BeginSim();
    void Gravity();
    void DrawMovement();
    void Movememnt();
    void PlanetGrav();
    bool outOfBounds(Circle s);
    void Angle(Circle c1, Circle c2);
};