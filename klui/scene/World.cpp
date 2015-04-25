#include "World.hpp"

using namespace std;
using namespace scene;

/* Method Definitions */
void World::addObject(Object & obj)
{
    objects_.push_back(&obj);
}

void World::addObject(Camera & cam)
{
    objects_.push_back(&cam);
    cams_.push_back(&cam);

    if (cam_ == nullptr)
    {
        cam_ = &cam;
    }
    else
    {
        std::cout << "Cam already set!" << std::endl;
    }
}

void World::removeObject(Object & obj)
{
    auto sameID = [&](Object * object) { return object->getID() == obj.getID();  };
    auto to_remove = std::remove_if(std::begin(objects_), std::end(objects_), sameID);
    objects_.erase(to_remove);
}

void World::draw()
{
    for (auto &object : objects_)
    {
        object->draw();
    }
}

World & createWorld()
{
    World * new_world = new World();
    return *new_world;
}
