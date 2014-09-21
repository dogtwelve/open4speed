//----------------------------------------------------------------------------------------
/**
 * \file       stdafx.h
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Includition of common header files
*/
//----------------------------------------------------------------------------------------

#pragma once

#ifdef ANDROID
#define ZIP_ARCHIVE
#endif

#define GLM_FORCE_RADIANS
#include <cstring>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <png.h>

#ifdef ANDROID
#include "app.h"
#include <GLES2/gl2.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <zip.h>
#endif

#include "components/interfaces/input.h"
#include "components/interfaces/texture.h"
#include "components/interfaces/shader.h"
#include "components/interfaces/model.h"
#include "components/interfaces/sound.h"
#include "car.h"
#include "components/interfaces/physics.h"
#include "components/interfaces/renderer.h"
#include "components/physics/bullet.h"

#ifndef ANDROID
#include "components/sound/fmodapi.h"
#endif
#include "components/sound/soundpool.h"

#include "components/input/airacer.h"
#include "components/input/aitraffic.h"
#include "components/input/keyboard.h"

#include "utils/io.h"
#include "components/texture/bmp24.h"
#include "components/texture/pngloader.h"
#include "components/texture/pxxloader.h"
#include "components/texture/rgb.h"
#include "components/shader/glsl.h"
#include "components/model/modelo4s.h"
#include "components/renderer/glphong.h"

#include "utils/engine.h"
#include "utils/math.h"
#include "utils/switch.h"
#include "common.h"
