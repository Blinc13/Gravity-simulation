#include "sceneloader.h"

std::pair<std::vector<Planet*>*,PhysicsServer*>
scene::load_scene(const std::string &filename)
{
  tinyxml2::XMLDocument doc;

  doc.LoadFile(filename.data());
  auto *Root=doc.FirstChild();

  auto *vec=new std::vector<Planet*>();

  {//Planets load
    auto *Planets=Root->FirstChild(),
         *Planet=Planets->FirstChild();

    for (;Planet!=nullptr;Planet=Planet->NextSiblingElement())
    {
      std::string texture_path(Planet->FirstChildElement("texture")->GetText());

      float mass=Planet->FirstChildElement("mass")->FloatText();
      float grav=Planet->FirstChildElement("gravity")->FloatText();
      float rad=Planet->FirstChildElement("radius")->FloatText();

      sf::Vector2f position,vel;

      {
        auto *vector=Planet->FirstChildElement("position");

        position.x=vector->FirstChildElement()->FloatText();
        position.y=vector->LastChildElement()->FloatText();

        vector=Planet->FirstChildElement("velocity");

        vel.x=vector->FirstChildElement()->FloatText();
        vel.y=vector->LastChildElement()->FloatText();
      }


      vec->push_back(new class Planet(texture_path,mass,grav,rad,position,vel));
    }
  }

  auto *serv=new PhysicsServer(*vec);

  {
    auto *Params=Root->FirstChildElement("Params");

    serv->set_bounce_scale(Params->FirstChildElement("bounce_scale")->FloatText());
    serv->set_time_scale(Params->FirstChildElement("time_scale")->FloatText());
    serv->set_gravity_scale(Params->FirstChildElement("gravity_scale")->FloatText());
  }

  return {vec,serv};
}

