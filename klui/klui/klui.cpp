#include "stdafx.h"
#include "klui.hpp"

using namespace std;
using namespace klui;
/** Global variables **/

/** Method Definitions **/

/** Manager Class **/
/** Manages and exposes all the UI elements
 *
**/
void Manager::init(int width, int height)
{
    clock = sf::Clock();
    Window * main_window = new Window(appname_, width, height);
    windows_.push_back(main_window);
}

void Manager::startLoop()
{
    while (windows_[0]->isOpen())
    {
        renderFrame();
    }
}

void Manager::renderFrame()
{
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    for (auto &window : windows_)
    {
        window->draw();
    }
}

Window & Manager::createWindow(int width, int height)
{
    Window * new_window = new Window(width, height);
    windows_.push_back(new_window);
    return *new_window;
}

Window & Manager::createWindow(std::string name, int width, int height)
{
    Window * new_window = new Window(name, width, height);
    windows_.push_back(new_window);
    return *new_window;
}

Panel & Manager::createPanel(Window & window, std::string name, int width, int height)
{
    Panel * new_panel = new Panel(width, height);
    window.addChildren(new_panel);
    elements_.push_back(new_panel);

    return *new_panel;
}

Panel & Manager::createPanel(Window & window, std::string name, int width, int height)
{
    Panel * new_panel = new Panel(name, width, height);
    window.addChildren(new_panel);
    elements_.push_back(new_panel);

    return *new_panel;
}

Panel & Manager::createPanel(Window & window, std::string name, int width, int height, int xpos, int ypos)
{
    Panel * new_panel = new Panel(name, width, height, xpos, ypos);
    window.addChildren(new_panel);
    elements_.push_back(new_panel);

    return *new_panel;
}

Button & Manager::createButton( Panel & panel, std::string name, int width, int height, int xpos, int ypos)
{
    Button * new_button = new Button(name, width, height, xpos, ypos);
    panel.addChildren(new_button);
    elements_.push_back(new_button);

    return *new_button;
}
