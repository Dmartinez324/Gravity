
#include <iostream>
#include <raylib.h>
#include <vector>
#include <glm/glm.hpp>

using namespace std;


class Circle{
  public:
  Circle();
  Circle(glm::vec2 p, float s, glm::vec2 d, float v);
  ~Circle();

  float getX();
  float getY();
  float getGrav();
  float getVelocity();


  glm::vec2 pos;
  float size;
  glm::vec2 initDirection;
  float velocity;


};



