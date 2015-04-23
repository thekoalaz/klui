#pragma once
#include "stdafx.h"
#include "UIElement.hpp"

namespace klui
{ 

/** Global variables **/
static std::string DEFAULT_WINDOWNAME = "A Window";
static int FPS_LIMIT = 60;

/** Class Prototypes **/
class Window;

/** Class Definitions **/
/** Window Class **/
/** Abstract class that defines the basic properties of an UI element
 *
**/
class Window : public UIElement
{
public:
    /* Constructors */
    Window(int width, int height) : UIElement(width, height, DEFAULT_WINDOWNAME), init_(false)
        { init(); }
    Window(int width, int height, std::string name) : UIElement(width, height, name), init_(false)
        { init(); }

    void init();
    void draw();
    void reshape(int w, int h);

    bool isOpen() { return window->isOpen(); }
    
private:
    sf::RenderWindow * window;
    bool init_;
};

};
