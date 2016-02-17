/**
 * "The large is done with the small." -Lao Tzu
 *
 * Created on Tuesday, December 15, 2015
 * By: Plotner
 *
 *
 *
 */
#pragma once

#include <cmath>
#include <string>

class vec3f
{
public:
    //////////////////////
    //// CONSTRUCTORS ////
    //////////////////////

     /**
     * @brief Empty constructor sets values to zero
     */
    vec3f();
    /**
     * @brief Constructor from individual floats
     * @param x float for the X value of the vector
     * @param y float for the Y value of the vector
     * @param z float for the Z value of the vector
     */
    vec3f(const float x, const float y, const float z);
    /**
     * @brief copy constructor
     * @param other the vec3f that is being copied
     */
    vec3f(const vec3f& other);

    /** vec3f Destructor */
    ~vec3f();
    //********************//
    //** GET OPERATIONS **//
    //********************//
    /**
     * @brief cross  dot mag magsqr
     */
    vec3f
    crossProduct(const vec3f& other) const;
    /**
     * @brief
     */
    float
    dotProduct(const vec3f& other) const;

    /**
     * @brief
     */
    float
    getMagnitude() const;
    /**
     * @brief
     */
    float
    getMagnitudeSquared() const;
    
    std::string
    getString() const;
    
    //**************//
    //** MUTATORS **//
    //**************//
    
    /**
     * @brief
     */
    void
    normalize();
    /**
     * @brief
     * @param
     * @param
     * @param
     */
    void
    scale(const float sx, const float sy, const float sz);
    /**
     * @brief
     * @param
     */
    void
    scale(const float scale);
    
    
    
    //******************************//
    //** CONST OPERATOR OVERLOADS **//
    //*******************************//
    /**
     * @brief
     * @param
     */
    float
    operator[] (const int& index) const;
    /**
     * @brief
     * @param
     */
    vec3f&
    operator= (const vec3f& other);
    /**
     * @brief
     * @param
     */
    vec3f
    operator+  (const vec3f& other) const;
    /**
     * @brief
     * @param
     */
    void
    operator+= (const vec3f& other);
    /**
     * @brief
     * @param
     */
    vec3f
    operator-  (const vec3f& other) const;
    /**
     * @brief
     * @param
     */
    void
    operator-= (const vec3f& other);
    /**
     * @brief
     * @param
     */
    vec3f
    operator*  (const float& scale) const;
    
    /**
     * @brief
     * @param
     */
    void
    operator*= (const float& scale);
    /**
     * @brief
     * @param
     */
    vec3f
    operator/  (const float& scale) const;
    /**
     * @brief component wise division
     * @param
     */
    vec3f
    operator/  (const vec3f& other) const;
    /**
     * @brief
     * @param
     */
    void
    operator/= (const float& scale);
    
    
    
    float m_x; /** The x value of the vector */
    float m_y; /** The y value of the vector */
    float m_z; /** The z value of the vector */
protected:
private:
    
};
