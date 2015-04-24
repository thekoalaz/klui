/** stdafx.h : include file for standard system include files,
 *   or project specific include files that are used frequently, but
 * are changed infrequently
**/

#pragma once

#ifdef __WIN32__
    #include <Windows.h>
#endif
#include <stdio.h>
#include <tchar.h>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
//#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <vector>
#include <tuple>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>

#define _USE_MATH_DEFINES
#include <math.h>
//#define M_PI 3.1415926535897932384626433832795f
