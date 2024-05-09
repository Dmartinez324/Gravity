#include "Circle.h"
#include <iostream>



Circle::Circle() : pos(glm::vec2(0.0f, 0.0f)), size(1.0f), initDirection(glm::vec2(0.0f, 0.0f)), velocity(0.0f) {}


Circle::Circle(glm::vec2 pos, float size, glm::vec2 dir, float velocity)
    : pos(pos), size(size), initDirection(dir), velocity(velocity) {}



float Circle::getGrav(){
    if(this->size == 10.0f){
        return 30;
    }
    else if(this->size == 20.0f){
        return 60;
    }
    else if(this->size == 30.0f){
        return 90;
    }
    return 30;
}

Circle::~Circle(){
    
}