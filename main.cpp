#include <iostream>

#include <SFML/Graphics.hpp>

#include "planet.h"
#include "sceneloader.h"
#include "physicsserver.h"

#include <vector>

int main(int argv,char **argc)
{
  auto [vec,serv]=scene::load_scene("Scene.xml");

  sf::RenderWindow wn(sf::VideoMode(800,700),"Test",sf::Style::Close);
  wn.setFramerateLimit(60);

  sf::Vector2f size={(float)wn.getSize().x,(float)wn.getSize().y};

  sf::View view({0,0},size);
  wn.setView(view);

  sf::Clock timer;

  while(true)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
      break;
    if (sf::Event ev;wn.pollEvent(ev))
      if (ev.type==sf::Event::Closed)
        break;

    serv->_process(timer.getElapsedTime().asSeconds()*10);
    timer.restart();

    for (Planet *k:*vec)
    {
      k->display(wn);
    }

    wn.display();
    wn.clear();
  }

  delete serv;

  return 0;
}
