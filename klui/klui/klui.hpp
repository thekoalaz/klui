#pragma once
#include "stdafx.h"
#include "Window.hpp"
#include "Panels.hpp"
#include "Button.hpp"
#include "scene/World.hpp"

namespace klui
{
/** Global variables **/
static int DEFAULT_WIDTH = 640;
static int DEFAULT_HEIGHT = 480;

/** Class Prototypes **/
class Manager;

/** Class Definitions **/

/** Manager Class **/
/** Manages and exposes all the UI elements.
 *  Singleton.
**/
class Manager
{
public:
    /* Constructors */
    Manager() { init(); }

    void init();
    void display();
    void drawElements();
    void startLoop();

    Window & createWindow(int width, int height);
    Window & createWindow(int width, int height, std::string name);
    Window & createWindow(int width, int height, int xpos, int ypos, std::string name);

    Panel & createPanel(Window & window, int width, int height, std::string name);
    Panel & createPanel(Window & window, int width, int height, int xpos, int ypos, std::string name);

    Button & createButton(Panel & panel, int width, int height, int xpos, int ypos, std::string name);

private:
    std::vector<Window *> windows_;
    std::vector<UIElement *> elements_;

    sf::Clock clock;
};

};
