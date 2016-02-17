/**
 * This class is a 4x4 matrix class for the Lee Engine
 * 
 * "If you spend too much time thinking about a thing
 *     you never get it done"   -Bruce Lee
 *
 * Matrices are stored in colom major order
 *
 * Written by Jonathan Platner
 */

 #pragma once

class mat4f
{
public:
    mat4f();
    mat4f( const vec4f& col0
         , const vec4f& col1
         , const vec4f& col2
         , const vec4f& col3
    );
    
    ~mat4f();

    /*
     * @brief calculates and return the trace of the matrix
     */
    
    
    float m_data[16];

    float& operator()(unsigned int row, unsigned int col) const;

    vec4f operator* (const vec4f& vec) const;
    
    mat4f operator* (const mat4f other) const;
    
    mat4f operator= (const mat4f other);
    /**
     * @brief matrix matrix component wise additios
     * @param other the matrix being added to this
     * @retval mat4f the component wise sum of this and other
     */
    mat4f operator+ (const mat4f& mat) const;

    const static mat4f identity;
}

 /*
  * @todo implement the following (taken from the section of book)
  * Matrix addition
  * Scalar Multiplication
  * Transpose
  * Vector Representations
  * Block Matrices
  * Matrix Product
  * Vector Transformations
  * Combining Linear Transformations
  * Identity Matrix
  * Performing Vector Operations with Matrices
  */
