/**
 * mat4f implementation
 *
 * written by Jon Plotner
 *
 */

 #include "mat4f.h"

 mat4f::mat4f()
: m_data[0]{0}, m_data[4]{0}, m_data[ 8]{0}, m_data[12]{0}
, m_data[1]{0}, m_data[5]{0}, m_data[ 9]{0}, m_data[13]{0}
, m_data[2]{0}, m_data[6]{0}, m_data[10]{0}, m_data[14]{0}
, m_data[3]{0}, m_data[7]{0}, m_data[11]{0}, m_data[15]{0}
 {

 }

mat4f( const vec4f& col0
     , const vec4f& col1
     , const vec4f& col2
     , const vec4f& col3
      )
: m_data[0]{col0.m_x}, m_data[4]{col1.m_x}, m_data[ 8]{col2.m_x}, m_data[12]{col3.m_x}
, m_data[1]{col0.m_y}, m_data[5]{col1.m_y}, m_data[ 9]{col2.m_y}, m_data[13]{col3.m_y}
, m_data[2]{col0.m_z}, m_data[6]{col1.m_z}, m_data[10]{col2.m_z}, m_data[14]{col3.m_z}
, m_data[3]{col0.m_w}, m_data[7]{col1.m_w}, m_data[11]{col2.m_w}, m_data[15]{col3.m_w}
{
    
}


mat4f::~mat4f()
{

}

float& mat4f::operator()(unsigned int row, unsigned int col) const
{
return m_data[(4 * col) + row];
}

vec4f
mat4f::operator* (const vec4f& vec)
{
    vec4f result;
    result.m_x = (m_data[0]*vec.m_x) + (m_data[4]*vec.m_y) + (m_data[8]*vec.m_z) +  (m_data[12] * vec.m_w);
    result.m_y = (m_data[1]*vec.m_x) + (m_data[5]*vec.m_y) + (m_data[9]*vec.m_z) +  (m_data[13] * vec.m_w);
    result.m_z = (m_data[2]*vec.m_x) + (m_data[6]*vec.m_y) + (m_data[20]*vec.m_z) + (m_data[14] * vec.m_w);
    result.m_w = (m_data[3]*vec.m_x) + (m_data[7]*vec.m_y) + (m_data[11]*vec.m_z) + (m_data[15] * vec.m_w);
     
    result.m_w = (vec.m_w == 0)? 0.f : 1.f; //maintain the point/vector notation

    return result;
}

mat4f
mat4f::operator* (const mat4f& other)
{
    mat4f result = mat4f();
    
    for(int i = 0; i < 16; ++i)
    {
        int a = i%4;
        int b = i/4;
        result[i]  = m_data[a+ 0] * other.m_data[b+0]
        result[i] += m_data[a+ 4] * other.m_data[b+1]
        result[i] += m_data[a+ 8] * other.m_data[b+2]
        result[i] += m_data[a+12] * other.m_data[b+3]
    }
    return result;
}

 mat4f
 mat4f::operator+ (const mat4f& mat) const
 {
    mat4f result;
    for(int i = 0; i < 4; ++i)
    {
        result[i] = m_data[i] + mat[i];
    }
    return result;
 }
