#include "planet.h"
#include "funcs.h"
#include <iostream>

Planet::Planet(const std::string &file_path,float ms,float gr,float rad,sf::Vector2f pos,sf::Vector2f vel):
mass(ms),gravity(gr),radius(rad),velocity(vel)
{
  txt.loadFromFile(file_path);

  margin={(float)txt.getSize().x/2,(float)txt.getSize().y/2};

  move(pos);
}

void Planet::add_velocity(sf::Vector2f vel)
{
  velocity+=vel;
}

void Planet::update(float delta)
{
  move(mull(velocity,delta));
}

void Planet::display(sf::RenderWindow &win)
{
  setTexture(txt);

  win.draw(*this);
}

sf::Vector2f Planet::get_position() const
{
  return getPosition()+margin;
}
