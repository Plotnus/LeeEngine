/**
 * mat3f implementation
 *
 * written by Jon Plotner
 *
 */

#include "mat3f.h"
#include "vec3f.h"
#include <cassert>

const
mat3f mat3f::identity = mat3f( 1, 0, 0
                             , 0, 1, 0
                             , 0, 0, 1 );
const
mat3f mat3f::zero = mat3f();

mat3f::mat3f()
: m_data{ 0, 0, 0
        , 0, 0, 0
        , 0, 0, 0 }
{

}

mat3f::mat3f(const float val0, const float val1, const float val2
            ,const float val3, const float val4, const float val5
            ,const float val6, const float val7, const float val8)
: m_data{ val0, val1, val2
        , val3, val4, val5
        , val6, val7, val8 }
{

}

mat3f::mat3f(  const vec3f& col0
             , const vec3f& col1
             , const vec3f& col2)
: m_data{ col0.m_x, col0.m_y, col0.m_z
        , col1.m_x, col1.m_y, col1.m_z
        , col2.m_x, col2.m_y, col2.m_z }
{
    
}

mat3f::mat3f(const mat3f& other)
{
    memcpy(this, &other, sizeof(mat3f) );
}

mat3f::mat3f(const mat3f * const other)
{
    memcpy(this, other, sizeof(mat3f) );
}

mat3f::~mat3f()
{

}

vec3f
mat3f::gaussianElimination(const vec3f& other)
{
    vec3f result = vec3f(other);
    for (int col = 0; col < 3; ++col)
    {
        // find the element with the larges absolute value in column p
        int maxVal = abs(getElement(col,col));
        int maxRowIndex = col;
        for (int row = i; row < 3; ++row)
        {

        }
        // if max element is not in row p swap rows

        // set pivot element to one

        // clear the lower column entries

    }
    //backwards substitution
    for (int row = 2; row >= 1; --row)
    {
        for (int col = row+1; col < 3; ++col)
        {
            //subtract out known quantities
        }
    }
    return result;
}
mat3f
mat3f::getAdjoint() const
{
    mat3f result = mat3f();
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            float cofactor = this->getCofactor(row,col);
            if ( (row%2 == 1) ^ (col%2 == 1) )
            {
                cofactor *= -1;
            }
            result(row,col) = cofactor;
        }
    }

    return result;
}

float
mat3f::getCofactor(const int row, const int col) const
{
    assert (row >= 0 && row <= 2);
    assert (col >= 0 && row <= 2);

    // when row || col == 1 then the high/low are swaped.
    // this is handeled by multiplying the resulting determinate
    // by -1 once for each case
    int lowRowIndex = (row+1)%3;
    int highRowIndex = (row+2)%3;
    int lowColIndex = (col+1)%3;
    int highColIndex= (col+2)%3;

    float result = 0;
    result += getElement(lowRowIndex, lowColIndex)  * getElement(highRowIndex, highColIndex);
    result -= getElement(highRowIndex, lowColIndex) * getElement(lowRowIndex, highColIndex);
    if ( (row == 1) ^ (col == 1) )
    {
        result *= -1;
    }
    return result;
}

float
mat3f::getDeterminant() const
{
    float result = 0.f;
    result += m_data[0] * m_data[4] * m_data[8];
    result += m_data[3] * m_data[7] * m_data[2];
    result += m_data[6] * m_data[1] * m_data[5];
    result -= m_data[6] * m_data[4] * m_data[2]; 
    result -= m_data[3] * m_data[1] * m_data[8];
    result -= m_data[0] * m_data[7] * m_data[5];

    return result;
}

float
mat3f::getElement(const int row, const int col) const
{
    assert( row >= 0 && row < 3);
    assert( col >= 0 && col < 3);

    return m_data[ row + (3*col) ];
}

mat3f
mat3f::getInverse() const
{
    mat3f inverse = mat3f();
    inverse = getAdjoint();
    inverse /= getDeterminant();
    return inverse;
}

float
mat3f::getEigenValue() const
{
    float result = 0.f;

    return result;
}

vec3f
mat3f::getEigenVector() const
{
    vec3f result = vec3f();

    return result;
}
mat3f
mat3f::getTranspose() const
{
    mat3f result = mat3f();

    result.m_data[0] = m_data[0];
    result.m_data[1] = m_data[3];
    result.m_data[2] = m_data[6];
    result.m_data[3] = m_data[1];
    result.m_data[4] = m_data[4];
    result.m_data[5] = m_data[7];
    result.m_data[6] = m_data[2];
    result.m_data[7] = m_data[5];
    result.m_data[8] = m_data[8];

    return result;
}

mat3f
mat3f::getUpperTriMat() const
{
    mat3f result = mat3f(*this);

    result.m_data[1] = 0.f;
    result.m_data[2] = 0.f;
    result.m_data[5] = 0.f;
    
    return result;
}

mat3f
mat3f::getLowerTriMat() const
{
    mat3f result = mat3f(*this);

    result.m_data[3] = 0.f;
    result.m_data[6] = 0.f;
    result.m_data[7] = 0.f;

    return result;
    
}

mat3f
mat3f::getDiagonalMat() const
{
    mat3f result = mat3f();

    result.m_data[0] = m_data[0];
    result.m_data[4] = m_data[4];
    result.m_data[9] = m_data[9];

    return result;
}

std::string
mat3f::getString() const
{
    std::string result = "";
    //first row
    result += "mat3f: ";
    result +=       std::to_string(m_data[0]);
    result += " " + std::to_string(m_data[3]);
    result += " " + std::to_string(m_data[6]);
    result += "\n";
    //second row
    result += "       ";
    result +=       std::to_string(m_data[1]);
    result += " " + std::to_string(m_data[4]);
    result += " " + std::to_string(m_data[7]);
    result += "\n";
    //third row
    result += "       ";
    result +=       std::to_string(m_data[2]);
    result += " " + std::to_string(m_data[5]);
    result += " " + std::to_string(m_data[8]);
    result += "\n";
    
    return result;
}

float
mat3f::getTrace() const
{
    float result = 0;
    result += m_data[0];
    result += m_data[4];
    result += m_data[8];

    return result;
}

float&
mat3f::operator()(const int row, const int col) 
{
   assert( row < 3 && row >= 0);
   assert( col < 3 && col >= 0);
   
    return m_data[ row + (3 * col) ];
}

mat3f
mat3f::operator* (const float scale) const
{
    mat3f result = mat3f();
    for (int i = 0; i < 9; ++i)
    {
        result.m_data[i] = scale * m_data[i];
    }
    return result;
}
vec3f
mat3f::operator* (const vec3f& vec) const
{
    vec3f result;
    result.m_x = (m_data[0]*vec.m_x) + (m_data[4]*vec.m_y) + (m_data[ 8]*vec.m_z);
    result.m_y = (m_data[1]*vec.m_x) + (m_data[5]*vec.m_y) + (m_data[ 9]*vec.m_z);
    result.m_z = (m_data[2]*vec.m_x) + (m_data[6]*vec.m_y) + (m_data[10]*vec.m_z);
     
    return result;
}

mat3f
mat3f::operator* (const mat3f& other) const
{
    mat3f result = mat3f();
    
    for(int i = 0; i<9; ++i)
    {
        int a = i%3;
        int b = i/3;
        result.m_data[i]  = m_data[a+ 0] * other.m_data[b+0];
        result.m_data[i] += m_data[a+ 3] * other.m_data[b+1];
        result.m_data[i] += m_data[a+ 6] * other.m_data[b+2];
    }
    return result;
}

 mat3f
 mat3f::operator+ (const mat3f& mat) const
 {
    mat3f result;
    for(int i = 0; i<9; ++i)
    {
        result.m_data[i] = m_data[i] + mat.m_data[i];
    }
    return result;
 }
mat3f&
mat3f::operator= (const mat3f& other)
{
    std::memcpy(this, &other, sizeof(mat3f));
    
    return *this;
}

mat3f&
mat3f::operator/= (const float scale)
{
    assert(scale != 0);
    (*this) = (*this)*(1.0/scale);
    return *this;
}

