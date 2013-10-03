//----------------------------------------------------------------------------------------
/**
 * \file       physics.h
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Physical model for scene, it detects collision and also calculate collision
 *             reactions. Also applies car physical and visual state.
*/
//----------------------------------------------------------------------------------------

#ifndef PHYSICS_H
#define PHYSICS_H

#include "stdafx.h"

/**
 * @brief The physics interface
 */
class physics {
public:
    bool locked;    ///< Locker for car controling

    /**
     * @brief physics desructor
     */
    virtual ~physics() {}

    /**
     * @brief addCar adds car into physical model
     * @param c is car instance
     */
    virtual void addCar(car* c) = 0;

    /**
     * @brief addModel adds model into physical model
     * @param m is 3D model for physical model
     */
    virtual void addModel(model *m) = 0;

    /**
     * @brief getMultiply gets engine speed multiply
     * @return count of multiply
     */
    virtual int getMultiply() = 0;

    /**
     * @brief getTransform counts OpenGL matrix of transformation
     * @param c is instance of car
     * @param index is index of object
     * @return transformation matrix
     */
    virtual void getTransform(car* c, int index, float* m) = 0;

    /**
     * @brief getTransform counts OpenGL matrix of transformation
     * @param index is index of object
     * @return transformation matrix
     */
    virtual void getTransform(int index, float* m) = 0;

    /**
     * @brief resetCar updates car state
     * @param c is instance of car
     */
    virtual void resetCar(car* c) = 0;

    /**
     * @brief updateCar updates car state
     * @param c is instance of car
     */
    virtual void updateCar(car* c) = 0;

    /**
     * @brief updateWorld updates world state
     */
    virtual void updateWorld() = 0;
};

#endif // PHYSICS_H
