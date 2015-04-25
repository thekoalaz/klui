#pragma once
#include "stdafx.h"

namespace scene
{

class Object
{
public:
    /* Constructors */
    Object() : tx_(0), ty_(0), tz_(0), rotx_(0), roty_(0), rotz_(0), visible_(true)
        {
            objectID_ = nextID();
        }
    Object(float tx, float ty, float tz, float rotx, float roty, float rotz) : tx_(tx), ty_(ty), tz_(tz),
        rotx_(rotx), roty_(roty), rotz_(rotz), visible_(true)
        {
            objectID_ = nextID();
        }
    void draw();
    virtual void doDraw() = 0;

    /* getters */
    float getTx() { return tx_; } const
    float getTy() { return ty_; } const
    float getTz() { return tz_; } const
    float getRotx() { return rotx_; } const
    float getRoty() { return roty_; } const
    float getRotz() { return rotz_; } const
    bool getVisible() { return visible_; } const
    int getID() { return objectID_; } const

    /* Single line functions */
    int nextID() { return NEXTID++; }

    ~Object() { }

protected:
    /* setters */
    void setTx(float tx) { tx_ = tx; }
    void setTy(float ty) { ty_ = ty; }
    void setTz(float tz) { tz_ = tz; }
    void setRotx(float rotx) { rotx_ = rotx; }
    void setRoty(float roty) { roty_ = roty; }
    void setRotz(float rotz) { rotz_ = rotz; }
    void setVisible(bool visible) { visible_ = visible; }

private:
    int objectID_;
    float tx_, ty_, tz_;
    float rotx_, roty_, rotz_;
    bool visible_;

    static int NEXTID;
};

};
