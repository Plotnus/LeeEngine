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

class Mat4x4f
{
public:
    Mat4x4f();
    ~Mat4x4f();

    float m_data[4][4];

    float& operator()(unsigned int row, unsigned int col) const;

    Vec4f operator* (const Vec4f& vec) const;
    /**
     * @brief matrix matrix component wise additios
     * @param other the matrix being added to this
     * @retval Mat4x4f the component wise sum of this and other
     */
    Mat4x4f operator+ (const Mat4x4f& mat) const;
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
