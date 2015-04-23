#include "stdafx.h"
#include "Window.hpp"

using namespace std;
using namespace klui;

/** Global variables **/

/** Window Class **/
/** Class that defines the window system.
 *
**/
void Window::init()
{
    std::cout << "Window: " << getName() << " " << getWidth() << " by " << getHeight() << "." << std::endl;
    window = new sf::RenderWindow(sf::VideoMode(getWidth(), getHeight()), getName());
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(FPS_LIMIT);
    init_ = true;
}

void Window::draw()
{    
    sf::Event event;
    while (window->pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
        else if (event.type == sf::Event::Resized)
        {
            reshape(event.size.width, event.size.height);
        }
    }
    window->clear();

    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    for(std::vector<UIElement *>::const_iterator child = getChildren().begin() ;
        child < getChildren().end() ; child++)
    {
        (*child)->draw();
    }
    
    window->display();
}

void Window::reshape(int w, int h)
{
    std::cout << "New size: " << w << " by " << h << std::endl;
    // prevent divide by 0 error when minimized
    if(w==0) 
        h = 1;

    setWidth(w);
    setHeight(h);
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/h,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
