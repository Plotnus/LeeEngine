/**
 * mat3f implementation
 *
 * written by Jon Plotner
 *
 */

#include "mat3f.h"
#include "vec3f.h"
#include <cassert>

 mat3f::mat3f()
: m_data{
      0, 0, 0
    , 0, 0, 0
    , 0, 0, 0}
{

}

mat3f::mat3f(  const vec3f& col0
             , const vec3f& col1
             , const vec3f& col2
            )
: m_data{
    col0.m_x, col0.m_y, col0.m_z,
    col1.m_x, col1.m_y, col1.m_z,
    col2.m_x, col2.m_y, col2.m_z}
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

mat3f
mat3f::getTranspose()
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
mat3f::getUpperTriMat()
{
    mat3f result = mat3f(*this);

    result.m_data[1] = 0.f;
    result.m_data[2] = 0.f;
    result.m_data[5] = 0.f;
    
    return result;
}

mat3f
mat3f::getLowerTriMat()
{
    mat3f result = mat3f(*this);

    result.m_data[3] = 0.f;
    result.m_data[6] = 0.f;
    result.m_data[7] = 0.f;

    return result;
    
}

mat3f
mat3f::getDiagonalMat()
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
mat3f::operator()(unsigned int row, unsigned int col) const
{
    assert(row<3 && col<3);
    
    return m_data[(3 * col) + row];
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
