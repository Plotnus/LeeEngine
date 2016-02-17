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

// pre-declares
class vec3f;

class mat3f
{

public:
    mat3f();
    mat3f( const vec3f& col0
         , const vec3f& col1
         , const vec3f& col2
    );
    
    mat3f(const mat3f& other);
    mat3f(const mat3f * const other);
    ~mat3f();

    /*
     * @brief calculates and return the trace of the matrix
     */
    
    
    float
    m_data[16];

    mat3f
    getTranspose();

    mat3f
    getUpperTriMat();

    mat3f
    getLowerTriMat();

    mat3f
    getDiagonalMat();

    float&
    operator()(unsigned int row, unsigned int col) const;

    /**
     * @brief matrix matrix component wise additios
     * @param other the matrix being added to this
     * @retval mat3f the component wise sum of this and other
     */
    mat3f
    operator+ (const mat3f& mat) const;
    /**
     * @brief matrix vector transformation/multiplication
     * @param vec the vector being post multiplied to this mat3f
     * @retval vec3f the resultant vector from the postmultiplf
     */
    vec3f
    operator* (const vec3f& vec) const;
    
    mat3f
    operator* (const mat3f other) const;
    
    mat3f
    operator= (const mat3f other);
    const static mat3f identity;
};

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
