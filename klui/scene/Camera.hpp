#pragma once
#include "stdafx.h"
#include "Object.hpp"

namespace scene
{
class Camera : public Object
{
public:
    /* Constructors */
    Camera() : Object() { }

    void doDraw();

    /* Getters*/
    float getFocal() { return focal_; }

private:
    float focal_;
};

};
