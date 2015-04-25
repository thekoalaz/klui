#include "Object.hpp"
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;
using namespace scene;

/** Global variables **/
int Object::NEXTID = 0;

void Object::draw()
{
    if (!visible_)
    {
        return;
    }

    glPushMatrix();
    glTranslated(tx_, ty_, tz_);
    glRotated(rotx_, 1, 0, 0);
    glRotated(roty_, 0, 1, 0);
    glRotated(rotz_, 0, 0, 1);
    doDraw();

    glPopMatrix();
}
