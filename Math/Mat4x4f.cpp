/**
 * Mat4x4f implementation
 *
 * written by Jon Plotner
 *
 */

 #include "Mat4x4f.h"

 Mat4x4f::Mat4x4f()
 {

 }

 Mat4x4f::~Mat4x4f()
 {

 }

 float& Mat4x4f::operator()(unsigned int row, unsigned int col)
 {
    return m_data[col][row];
 }

 Vec4f Mat4x4f::operator* (const Vec4f& vec)
 {
    Vec4f result;
    result.m_x = (m_data[0][0]*vec.m_x) + (m_data[0][1]*vec.m_y) + (m_data[0][2]*vec.m_z);
    result.m_y = (m_data[1][0]*vec.m_x) + (m_data[1][1]*vec.m_y) + (m_data[1][2]*vec.m_z); 
    result.m_y = (m_data[2][0]*vec.m_x) + (m_data[2][1]*vec.m_y) + (m_data[2][2]*vec.m_z);

    return result;
 }

 Mat4x4f
 Mat4x4f::operator+ (const Mat4x4f& mat) const
 {
    Mat4x4f result;
    for(int i=0; i<=2; ++i)
    {
        for (int j=0; j<=2; ++j)
        {
            result[i][j] = m_data[i][j] + other.m_data[i][j];
        }
    }
    return result;
 }
