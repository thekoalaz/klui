#pragma once
#include "stdafx.h"
#include "UIElement.hpp"

namespace klui
{

/** Button Class **/
/** Abstract class that defines the basic properties of an UI element
 *
**/
//TODO PRIO: Buttons, and button selection
class Button : public UIElement
{
public:
    Button(int width, int height) : UIElement(width, height), _persp(false)
    { }
    Button(int width, int height, int xpos, int ypos) : UIElement(width, height), _persp(false)
    { }
    Button(int width, int height, int xpos, int ypos, std::string name) : UIElement(width, height, name), _persp(false)
    { }
    Button(int width, int height, void * callback(void));
    void draw();

private:
    void * _callback;
    bool _persp;
};

};
