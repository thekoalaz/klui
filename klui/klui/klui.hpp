#pragma once
#include "stdafx.h"
#include "Window.hpp"
#include "Panels.hpp"
#include "Button.hpp"
#include <scene/World.hpp>

namespace klui
{
/** Global variables **/
static int DEFAULT_WIDTH = 640;
static int DEFAULT_HEIGHT = 480;
static std::string DEFAULT_APPNAME = "Sup!";

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
    Manager() : appname_(DEFAULT_APPNAME) 
        { init(DEFAULT_WIDTH, DEFAULT_HEIGHT); }
    Manager(std::string appname) : appname_(appname)
        { init(DEFAULT_WIDTH, DEFAULT_HEIGHT); }
    Manager(int width, int height) : appname_(DEFAULT_APPNAME)
        { init(width, height); }
    Manager(std::string appname, int width, int height) : appname_(appname)
        { init(width, height); }

    void init(int, int);
    void display();
    void renderFrame();
    void startLoop();

    /* Creation Methods */
    Window & createWindow(int, int);
    Window & createWindow(std::string, int, int);
    Window & createWindow(std::string, int, int, int, int);

    Panel & createPanel(Window &, int, int);
    Panel & createPanel(Window &, std::string, int, int);
    Panel & createPanel(Window &, std::string, int, int, int, int);

    Button & createButton(Panel & panel, std::string, int, int, int, int);

    /* Getter Methods */
    Window & getMainWindow() { return *windows_[0]; }

private:
    std::vector<Window *> windows_;
    std::vector<UIElement *> elements_;

    std::string appname_;

    sf::Clock clock;
};

};
