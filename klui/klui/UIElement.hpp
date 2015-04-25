#pragma once
#include "stdafx.h"

namespace klui
{ 
/** Global variables **/
static int DEFAULT_XPOS = 10;
static int DEFAULT_YPOS = 10;

/** Class Prototypes **/
class UIElement;

/** Class Definitions **/
/** UIElement Class **/
/** Abstract class that defines the basic properties of an UI element
 *
**/
class UIElement
{
public:
    /* Constructors */
    UIElement(int width, int height)
        : xpos_(DEFAULT_XPOS), ypos_(DEFAULT_YPOS), width_(width), height_(height), name_(NULL)
        { init(); }
    UIElement(std::string name, int width, int height)
        : xpos_(DEFAULT_XPOS), ypos_(DEFAULT_YPOS), width_(width), height_(height), name_(name)
        { init(); }
    UIElement(std::string name, int width, int height, int xpos, int ypos)
        : xpos_(xpos), ypos_(ypos), width_(width), height_(height), name_(name)
        { init(); }

    
    virtual void init();
    virtual void draw() = 0;
    
    void addChildren(UIElement * elem) { children_.push_back(elem); }

    /* getters */
    int getXPos() { return xpos_; } const
    int getYPos() { return ypos_; } const
    int getWidth() { return width_; } const 
    int getHeight() { return height_; } const
    std::string getName() { return name_; } const
    int getId() { return UIElemId_; } const

    std::vector<UIElement *> & getChildren() { return children_; } const


    /* Single line functions */
    unsigned int nextId() { return NEXTID++; }

protected:
    /* setters */
    void setXPos(int xpos) { xpos_=xpos; }
    void setYPos(int ypos) { ypos_=ypos; }
    void setWidth(int width) { width_=width; }
    void setHeight(int height) { height_=height; }
    void setName(std::string name) { name_=name; }


private:
    int xpos_, ypos_,
        width_, height_;
    std::string name_;
    bool ortho_;
    float opacity_;
    unsigned int UIElemId_;
    std::vector<UIElement *> children_;
    
    static int NEXTID;
};
};
