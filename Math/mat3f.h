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
#include <string>

// pre-declares
class vec3f;

class mat3f
{
    // static const data members
public:
   static const
   mat3f identity;
   static const
   mat3f zero;
public:
    mat3f();
    mat3f(const float val0, const float val1, const float val2
         ,const float val3, const float val4, const float val5
         ,const float val6, const float val7, const float val8);
    mat3f( const vec3f& col0
         , const vec3f& col1
         , const vec3f& col2);
    mat3f(const mat3f& other);
    mat3f(const mat3f * const other);
    ~mat3f();

    /*
     * @brief calculates and return the trace of the matrix
     */
    
    
    float
    m_data[16];
    // const get methods

    /**
     * @brief calculates and returns the adjoint of this matrix
     * @retval mat3f the adjoint of this matrix
     */
    mat3f
    getAdjoint() const;
    /**
     * @brief calulates an returns the cofactor(aka subdeterminant) of this mat3f
     * @param row the row  being excluded from this mat3f for cofactor calculation
     * @param col the column being excluded from this mat3f for cofactor calculation
     */
    float
    getCofactor(const int row, const int col) const;   
    /**
     * @brief calculates and returns the determinant of this matrix
     * @param row the row to be excluded from this mat3f in the cofactor calculation
     * @param col the column to be excluded from this mat3f in the cofactor calculation
     * @retval the value of the determinant of this matrix
     */
    float
    getDeterminant() const;
    /**
     * @brief calculates and returns the inverse of this matrix
     * @retval mat3f the inverse of this matrix
     */
     mat3f
     getInverse() const;
     /**
      * @brief calculates and returns the eigen-value of this matrix
      * @retval float the eigen-value of this matrix
      */
     float
     getEigenValue() const;
     /**
      * @brief calculates and returns the eigen-vector of this matrix
      * @retval vec3f the eigen-vector of this matrix
      */
    vec3f
    getEigenVector() const;
    /**
     * @brief calculates and returns the diagonal matr3f, equiv. to A*I, (I=Identity)
     * @retval mat3f the diagonal matrix of this
     */
    mat3f
    getDiagonalMat() const;
    /**
     * @brief returns the float value of matrik element M(row,col)
     * @param row the row of the matrix element
     * @param col the column of the matrix element
     * @retval float the value of the matrik element
     */
    float
    getElement(const int row, const int col) const;
   /**
    * @brief calculates and returns the lower triangular matrix for this
    * @retval mat3f the lower triangular matrix
    */
    mat3f
    getLowerTriMat() const;
    /**
     * @brief calculates and returns the transpose of this matrix
     * @retval mat3f the transpose of this matrix
     */
    mat3f
    getTranspose() const;
    /**
     * @brief calculates and return the upper triangle matrix for this matrix
     * @retval mat3f the upper triangle matrix for this matrix
     */
    mat3f
    getUpperTriMat() const;

    std::string
    getString() const;

    float
    getTrace() const;

    /**
     * @brief Gaussian Elimination for solving a system of equations
     * @param vect the constant vector that will be used in the Elimination
     * @retval vec3f the solution/result to this Matrix/Vector Gausian substitution
     */
    vec3f
    gaussianElimination(const vec3f& other);

    /**
     * @brief returns the matrix element at a given column and row
     * @param row the row of the element being fetched
     * @param col the column of the element being fetched
     * @retval float& the matrix element at row,col
     */
    float&
    operator()(const int row, const int col);

    /**
     * @brief matrix matrix component wise additios
     * @param other the matrix being added to this
     * @retval mat3f the component wise sum of this and other
     */
    mat3f
    operator+ (const mat3f& mat) const;
    /**
     * @brief scales the matrix
     * @param scale the value we scale the matrix by
     * @retval the scaled matrix
     */
     mat3f
     operator* (const float scale) const;
    /**
     * @brief matrix vector transformation/multiplication
     * @param vec the vector being post multiplied to this mat3f
     * @retval vec3f the resultant vector from the postmultiplf
     */
    vec3f
    operator* (const vec3f& vec) const;
    
    mat3f
    operator* (const mat3f& other) const;
    
    mat3f&
    operator= (const mat3f& other);

    /**
     * @brief dives the matrix by a given float
     * @param scale the float ew are divinding by
     * @retval a mat3f& for the object
     */
    mat3f&
    operator/= (const float scale);
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
