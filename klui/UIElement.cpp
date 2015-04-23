#include "UIElement.hpp"

using namespace std;
using namespace klui;

/** Global variables **/
int UIElement::NEXTID = 0;

/** UIElement Class **/
/** Abstract class that defines the basic properties of an UI element
 *
**/

void UIElement::init()
{
     UIElemId_ = nextId();
}
