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
void Manager::init()
{
    clock = sf::Clock();
    Window * main_window = new Window(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    windows_.push_back(main_window);
}

void Manager::startLoop()
{
    while (windows_[0]->isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        for (auto &window : windows_)
        {
            window->draw();
        }
    }
}

void Manager::drawElements()
{
    //glutMainLoop();
}

Window & Manager::createWindow(int width, int height)
{
    Window * new_window = new Window(width, height);
    windows_.push_back(new_window);
    return *new_window;
}

Window & Manager::createWindow(int width, int height, std::string name)
{
    Window * new_window = new Window(width, height, name);
    windows_.push_back(new_window);
    return *new_window;
}

Panel & Manager::createPanel(Window & window, int width, int height, std::string name)
{
    Panel * new_panel = new Panel(width, height, name);
    window.addChildren(new_panel);
    elements_.push_back(new_panel);

    return *new_panel;
}

Panel & Manager::createPanel(Window & window, int width, int height, int xpos, int ypos, std::string name)
{
    Panel * new_panel = new Panel(width, height, xpos, ypos, name);
    window.addChildren(new_panel);
    elements_.push_back(new_panel);

    return *new_panel;
}

Button & Manager::createButton( Panel & panel, int width, int height, int xpos, int ypos, std::string name)
{
    Button * new_button = new Button(width, height, xpos, ypos, name);
    panel.addChildren(new_button);
    elements_.push_back(new_button);

    return *new_button;
}
