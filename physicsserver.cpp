#include "physicsserver.h"
#include "planet.h"
#include "funcs.h"

#include <iostream>

PhysicsServer::PhysicsServer(std::vector<Planet*> &plts):planets(plts)
{}

PhysicsServer::~PhysicsServer()
{
  for (Planet* k:planets)
  {
    delete k;
  }
}

void PhysicsServer::_process(float delta_second)
{
  delta_second*=time_scale;

  for (Planet *k:planets)
  {
    for (Planet *j:planets)
    {
      if (j!=k){
        sf::Vector2f ps=j->get_position()-k->get_position(),
                     gr;

        gr=mull(normalize(ps),(j->get_gravity()*gravity_scale)/k->get_mass()/lenght(ps));
        k->add_velocity(gr);


        float distance=lenght(ps);

        if (distance-(k->get_radius()+j->get_radius())<0)
        {
          sf::Vector2f dir=normalize(k->get_position()-j->get_position());

          k->add_velocity(mull(dir,bounce_scale*j->get_gravity()/k->get_mass()));
        }
      }
    }

    k->update(delta_second);
  }
}

void PhysicsServer::set_time_scale(float scale)
{time_scale=scale;}

void PhysicsServer::set_bounce_scale(float scale)
{bounce_scale=scale;}

void PhysicsServer::set_gravity_scale(float scale)
{gravity_scale=scale;}
