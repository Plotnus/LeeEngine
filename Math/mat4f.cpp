/**
 * mat4f implementation
 *
 * written by Jon Plotner
 *
 */

#include "mat4f.h"

 mat4f::mat4f()
:m_data{ 0, 0, 0, 0
       , 0, 0, 0, 0
       , 0, 0, 0, 0 }
 {

 }

mat4f::mat4f(  const vec4f& col0
             , const vec4f& col1
             , const vec4f& col2
             , const vec4f& col3 )
:m_data{
      col0.m_x, col0.m_y, col0.m_z, col0.m_w
    , col1.m_x, col1.m_y, col1.m_z, col1.m_w
    , col2.m_x, col2.m_y, col2.m_z, col2.m_w
    , col3.m_x, col3.m_y, col3.m_z, col3.m_w }
{
    
}

mat4f::~mat4f()
{

}

std::string
mat4f::getString()
{
    std::string result = "";
    //row0
    result += "mat3f: " + std::to_string(m_data[0]);
    result +=       " " + std::to_string(m_data[4]);
    result +=       " " + std::to_string(m_data[8]);
    result +=       " " + std::to_string(m_data[12]);
    result += "\n";
    //row1
    result += "       " + std::to_string(m_data[1]);
    result +=       " " + std::to_string(m_data[5]);
    result +=       " " + std::to_string(m_data[9]);
    result +=       " " + std::to_string(m_data[13]);
    result += "\n";
    //row2
    result += "       " + std::to_string(m_data[2]);
    result +=       " " + std::to_string(m_data[6]);
    result +=       " " + std::to_string(m_data[10]);
    result +=       " " + std::to_string(m_data[14]);
    result += "\n";
    //row3
    result += "       " + std::to_string(m_data[3]);
    result +=       " " + std::to_string(m_data[7]);
    result +=       " " + std::to_string(m_data[11]);
    result +=       " " + std::to_string(m_data[15]);
    result += "\n";
    
    return result;
}

float
mat4f::operator()(unsigned int row, unsigned int col) const
{
    return m_data[(4 * col) + row];
}

vec4f
mat4f::operator* (const vec4f& vec) const
{
    vec4f result;
    result.m_x = (m_data[0]*vec.m_x) + (m_data[4]*vec.m_y) + (m_data[8]*vec.m_z) +  (m_data[12] * vec.m_w);
    result.m_y = (m_data[1]*vec.m_x) + (m_data[5]*vec.m_y) + (m_data[9]*vec.m_z) +  (m_data[13] * vec.m_w);
    result.m_z = (m_data[2]*vec.m_x) + (m_data[6]*vec.m_y) + (m_data[10]*vec.m_z) + (m_data[14] * vec.m_w);
    result.m_w = (m_data[3]*vec.m_x) + (m_data[7]*vec.m_y) + (m_data[11]*vec.m_z) + (m_data[15] * vec.m_w);
     
    result.m_w = (vec.m_w == 0)? 0.f : 1.f; //maintain the point/vector notation

    return result;
}

mat4f
mat4f::operator* (const mat4f& other) const
{
    mat4f result = mat4f();
    for(int i = 0; i < 16; ++i)
    {
        int a = i%4;
        int b = i/4;
        result.m_data[i]  = m_data[a+ 0] * other.m_data[b+0];
        result.m_data[i] += m_data[a+ 4] * other.m_data[b+1];
        result.m_data[i] += m_data[a+ 8] * other.m_data[b+2];
        result.m_data[i] += m_data[a+12] * other.m_data[b+3];
    }
    
    return result;
}

 mat4f
 mat4f::operator+ (const mat4f& mat) const
 {
    mat4f result;
    for(int i = 0; i < 4; ++i)
    {
        result.m_data[i] = m_data[i] + mat.m_data[i];
    }
    return result;
 }
