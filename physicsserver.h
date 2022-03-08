#ifndef PHYSICSSERVER_H
#define PHYSICSSERVER_H

#include "planet.h"

#include <vector>

class PhysicsServer
{
private:
  std::vector<Planet*> &planets;

  float time_scale=1,
        gravity_scale=1,
        bounce_scale=1;
public:
  explicit PhysicsServer(std::vector<Planet*>&);

  void _process(float);

  void set_time_scale(float);
  void set_bounce_scale(float);
  void set_gravity_scale(float);

  ~PhysicsServer();
};

#endif // PHYSICSSERVER_H
