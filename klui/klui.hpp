#include <SFML/Graphics.hpp>

namespace klui
{

/** Global variables **/

/** Class Prototypes **/
class Manager;
class UIElement;
extern class Window;
extern class Panel;
extern class Button;

/** Class Definitions **/

/** Manager Class **/
/** Manages and exposes all the UI elements.
 * There should only ever be one manager.
**/
class Manager
{
public:
    /* Constructors */
    Manager() { }

    void init(int argc, char* argv[]);
    void display();
    void drawElements();
    void setShaders(std::string vertfile, std::string fragfile);
    void deleteShaders();

    Window & createWindow(int width, int height);
    Window & createWindow(int width, int height, std::string name);
    Window & createWindow(int width, int height, int xpos, int ypos, std::string name);

    Panel & createPanel(Window & window, int width, int height, std::string name);
    Panel & createPanel(Window & window, int width, int height, int xpos, int ypos, std::string name);

    Button & createButton(Panel & panel, int width, int height, int xpos, int ypos, std::string name);

private:
    std::vector<Window *> _windows;
    std::vector<UIElement *> _elements;
    GLuint v, f, p;
};

/** UIElement Class **/
/** Abstract class that defines the basic properties of an UI element
 *
**/
class UIElement
{
public:
    /* Constructors */
    UIElement(int width, int height)
        : _xpos(DEFAULT_XPOS), _ypos(DEFAULT_YPOS), _width(width), _height(height), _name(NULL)
        { init(); }
    UIElement(int width, int height, std::string name)
        : _xpos(DEFAULT_XPOS), _ypos(DEFAULT_YPOS), _width(width), _height(height), _name(name)
        { init(); }
    UIElement(int xpos, int ypos, int width, int height, std::string name)
        : _xpos(xpos), _ypos(ypos), _width(width), _height(height), _name(name)
        { init(); }

    
    virtual void init();
    virtual void draw() = 0;
    

    /* getters */
    int getXPos() { return _xpos; } const
    int getYPos() { return _ypos; } const
    int getWidth() { return _width; } const 
    int getHeight() { return _height; } const
    std::string getName() { return _name; } const
    int getId() { return _UIElemId; } const

    std::vector<UIElement *> & getChildren() { return _children; } const


    /* setters */
    void setXPos(int xpos) { _xpos=xpos; }
    void setYPos(int ypos) { _ypos=ypos; }
    void setWidth(int width) { _width=width; }
    void setHeight(int height) { _height=height; }
    void setName(std::string name) { _name=name; }

    void addChildren(UIElement * elem) { _children.push_back(elem); }

    /* Single line functions */
    unsigned int nextId() { return NEXTID++; }

private:
    int _xpos, _ypos,
        _width, _height;
    std::string _name;
    bool _ortho;
    float _opacity;
    unsigned int _UIElemId;
    std::vector<UIElement *> _children;

    
    static int NEXTID;
};

}