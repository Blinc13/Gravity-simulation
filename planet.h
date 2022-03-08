#ifndef PLANET_H
#define PLANET_H

#include <SFML/Graphics.hpp>
#include <string>

class Planet:private sf::Sprite
{
private:
  sf::Vector2f velocity,
               margin;

  sf::Sprite spr;
  sf::Texture txt;

  float mass,
        gravity,
        radius;
public:
  explicit Planet(const std::string&,float,float,float,sf::Vector2f={0,0},sf::Vector2f={0,0});

  void add_velocity(sf::Vector2f);
  void display(sf::RenderWindow&);
  void update(float);

  sf::Vector2f get_position()        const;
  inline sf::Vector2f get_vel()      const {return velocity;}
  inline float get_mass()            const {return mass;}
  inline float get_gravity()         const {return gravity;}
  inline float get_radius()          const {return radius;}

  void operator+=(const sf::Vector2f &vec)
  {add_velocity(vec);}
};

#endif // PLANET_H
