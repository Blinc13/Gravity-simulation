#ifndef SCENELOADER_H
#define SCENELOADER_H

#include "planet.h"
#include "physicsserver.h"

#include "xml/tinyxml2.h"

#include <vector>
#include <string>
#include <utility>

namespace scene
{
  std::pair<std::vector<Planet*>*,PhysicsServer*>
  load_scene(const std::string&);
}

#endif // SCENELOADER_H
