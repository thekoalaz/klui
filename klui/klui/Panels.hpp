#pragma once
#include "stdafx.h"
#include "UIElement.hpp"
#include "scene/scene.hpp"
#include "Button.hpp"

namespace klui
{

/** Panel Class **/
/** Panel class that defines a panel areas within the
 *
 **/
class Panel : public UIElement
{
public:
    Panel(int width, int height) : UIElement(width, height), _persp(false)
    { }
    Panel(int width, int height, std::string name) : UIElement(width, height, name), _persp(false)
    { }
    Panel(int width, int height, int xpos, int ypos, std::string name) : UIElement(width, height, xpos, ypos, name), _persp(false)
    { }
    void draw();

    void setWorld(scene::World * world) { world_ = world; }
    scene::World * getWorld() { return world_; }
    void setCamera(scene::Camera * camera) { camera_ = camera; }

    scene::Camera * getCamera() { return camera_; }

private:
    std::vector<Button *> buttons_;
    bool _persp;
    scene::World * world_;
    scene::Camera * camera_;
};

};
