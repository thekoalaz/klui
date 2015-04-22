#pragma once
#include "klui.hpp"

namespace klui
{ 

/** Global variables **/

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
    Window(int width, int height) : UIElement(width, height)
    { setName(DEFAULT_WINDOWNAME); init(); }
    Window(int width, int height, std::string name) : UIElement(width, height, name) { init(); }

    void init();
    void draw();
    void reshape(int w, int h);
    
private:
    static void displayFuncWrapper();
    static void reshapeFuncWrapper(int w, int h);

    bool _init;
};

};