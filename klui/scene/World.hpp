#pragma once
#include "stdafx.h"
#include "Object.hpp"
#include "Camera.hpp"

namespace scene
{
class Object;

class World
{
public:
    World() : cam_(nullptr){ }

    void addObject(Object &);
    void addObject(Camera &);
    void removeObject(Object &);

    Camera & getCam() { return *cam_; }

    void draw();

    ~World() { for (auto & object : objects_) { delete object; } };
private:
    std::vector<Object *> objects_;
    std::vector<Camera *> cams_;

    Camera * cam_;
};

World & createWorld();

};
