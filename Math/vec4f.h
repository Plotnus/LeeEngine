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

/** @todo: add doxygen comments
class vec4f
{
public:
    //******************//
    //** CONSTRUCTORS **//
    //******************//
    /**
     * @brief Empty constructor sets values to zero
     */
    vec4f();
    /**
     * @brief Constructor from individual floats
     * @param x float for the X value of the vector
     * @param y float for the Y value of the vector
     * @param z float for the Z value of the vector
     * @param w float, 1 means this is a point, 0 means this is a vector
     */
    vec4f(const float x, const float y, const float z, const float w );
    /**
     * @brief copy constructor
     * @param other the vec4f that is being copied
     */
    vec4f(const vec4f& other);

    /** vec4f Destructor */
    ~vec4f();
    //********************//
    //** GET OPERATIONS **//
    //********************//
    /**
     * @brief cross  dot mag magsqr
     */
    vec4f CrossProduct(const vec4f& other) const;
    /**
     * @brief
     */
    float DotProduct(const vec4f& other) const;

    /**
     * @brief
     */
    float GetMagnitude() const;
    /**
     * @brief
     */
    float GetMagnitudeSquared() const;
    
    
    //**************//
    //** MUTATORS **//
    //**************//
    
    /**
     * @brief
     */
    void Normalize();
    /**
     * @brief
     * @param
     * @param
     * @param
     */
    void Scale(const float sx, const float sy, const float sz);
    /**
     * @brief
     * @param
     */
    void Scale(const float scale);
    
    
    
    //******************************//
    //** CONST OPERATOR OVERLOADS **//
    //*******************************//
    /**
     * @brief
     * @param
     */
    float operator[] (const int& index) const;
    /**
     * @brief
     * @param
     */
    vec4f& operator= (const vec4f& other);
    /**
     * @brief
     * @param
     */
    vec4f operator+  (const vec4f& other) const;
    /**
     * @brief
     * @param
     */
    void operator+= (const vec4f& other);
    /**
     * @brief
     * @param
     */
    vec4f operator-  (const vec4f& other) const;
    /**
     * @brief
     * @param
     */
    float operator-= (const vec4f& other);
    /**
     * @brief
     * @param
     */
    vec4f operator*  (const float& scale) const;
    
    /**
     * @brief
     * @param
     */
    float operator*= (const vec4f& scale);
    /**
     * @brief
     * @param
     */
    vec4f operator/  (const float& scale) const;
    /**
     * @brief component wise division
     * @param
     */
    vec4f operator/  (const vec4f& other) const;
    /**
     * @brief
     * @param
     */
    void operator/= (const float& scale);
    
    
    
    float m_x; /** The x value of the vector */
    float m_y; /** The y value of the vector */
    float m_z; /** The z value of the vector */
    float m_w; /** The w value of the vector, 0 for a vector, 1 for a point */
protected:
private:
    
};