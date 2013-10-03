//----------------------------------------------------------------------------------------
/**
 * \file       glphong.h
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      GL renderer draws geometry and other things on screen
*/
//----------------------------------------------------------------------------------------


#ifndef GLPHONG_H
#define GLPHONG_H

#include "stdafx.h"

/**
 * @brief The glphong class is implementation of OpenGL ES 2.0
 */
class glphong : public renderer {
public:

    /**
     * @brief glphong constructor
     */
    glphong();

    /**
     * @brief lookAt implements GLUlookAt
     * @param eyex is eye vector coordinate
     * @param eyey is eye vector coordinate
     * @param eyez is eye vector coordinate
     * @param centerx is camera center coordinate
     * @param centery is camera center coordinate
     * @param centerz is camera center coordinate
     * @param upx is up vector coordinate
     * @param upy is up vector coordinate
     * @param upz is up vector coordinate
     */
    void lookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
                GLfloat centerx, GLfloat centery, GLfloat centerz,
                GLfloat upx, GLfloat upy, GLfloat upz);

    /**
     * @brief perspective implements GLUPerspective
     * @param fovy is fov angle
     * @param aspect is screen aspect ration
     * @param zNear is near cutting plate
     * @param zFar is far cutting plane
     */
    void perspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);

    /**
     * @brief clear clears fragmet/depth buffer
     * @param colors true to clear both, false to clear only depth buffer
     */
    void clear(bool colors);

    /**
     * @brief multMatrix multiplies with matrix
     * @param matrix is 4x4 matrix in OpenGL format
     */
    void multMatrix(float* matrix);

    /**
     * @brief popMatrix pops matrix from stack
     */
    void popMatrix();

    /**
     * @brief pushMatrix pushs current matrix to stack
     */
    void pushMatrix();

    /**
     * @brief rotateX rotate around X axis
     * @param value is angle
     */
    void rotateX(float value);

    /**
     * @brief rotateX rotate around Y axis
     * @param value is angle
     */
    void rotateY(float value);

    /**
     * @brief rotateX rotate around Z axis
     * @param value is angle
     */
    void rotateZ(float value);

    /**
     * @brief scale scales current matrix
     * @param value is amount of scale(1 to keep current)
     */
    void scale(float value);

    /**
     * @brief translate translates object
     * @param x is translate coordinate
     * @param y is translate coordinate
     * @param z is translate coordinate
     */
    void translate(float x, float y, float z);

    /**
     * @brief renderButton renders button in GUI mode
     * @param x is position x
     * @param y is position y
     * @param w is width
     * @param h is height
     * @param layer is distance from camera
     * @param button is button texture
     * @param text is button text
     */
    void renderButton(float x, float y, float w, float h, float layer, texture* button, const char* text);

    void renderDynamic(GLfloat *vertices, GLfloat *coords, shader* sh, texture* txt, int triangleCount);

    /**
     * @brief renderImage renders image in GUI mode
     * @param x is position x
     * @param y is position y
     * @param w is width
     * @param h is height
     * @param layer is distance from camera
     * @param image is image texture
     */
    void renderImage(float x, float y, float w, float h, float layer, texture* image);

    /**
     * @brief renderModel renders model into scene
     * @param m is instance of model to render
     * @param physic is physical model instance
     * @param gamma is requested render gamma
     */
    void renderModel(model* m);

    /**
     * @brief renderSubModel renders model into scene
     * @param m is instance of model to render
     * @param physic is physical model instance
     * @param gamma is requested render gamma
     */
    void renderSubModel(model* mod, model3d m);

    /**
     * @brief renderText renders text in GUI mode
     * @param x is position x
     * @param y is position y
     * @param layer is distance from camera
     * @param text is button text
     */
    void renderText(float x, float y, float layer, const char* text);

    /**
     * @brief setMode sets rendering mode
     * @param mode is mode index
     */
    void setMode(int mode);
};

#endif // GLPHONG_H
