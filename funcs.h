#ifndef FUNCS_H
#define FUNCS_H

#include <SFML/System/Vector2.hpp>
#include <math.h>

inline float lenght(sf::Vector2f vec)
{
  return abs(vec.x)+abs(vec.y);
}

inline sf::Vector2f normalize(sf::Vector2f vec)
{
  float vec_lenght=lenght(vec);//sqrt((vec.x * vec.x) + (vec.y * vec.y));

  vec.x/=vec_lenght;
  vec.y/=vec_lenght;

  return vec;
}

inline sf::Vector2f mull(sf::Vector2f vec,float value)
{
  vec.y*=value;
  vec.x*=value;

  return vec;
}

#endif // FUNCS_H
