/**
 *
 * Started On: Tuesday December 15 2015
 * By: Jonathan Plotner
 */

#include "vec3f.h"
#include <cassert>

//******************//
//** CONSTRUCTORS **//
//******************//
vec3f::vec3f()
: m_x{0.f}
, m_y{0.f}
, m_z{0.f}
{

}

vec3f::vec3f(const float x
            ,const float y
            ,const float z
                 )
: m_x{x}
, m_y{y}
, m_z{z}
{

}

vec3f::vec3f(const vec3f& vect)
: m_x{vect.m_x}
, m_y{vect.m_y}
, m_z{vect.m_z}
{

}

vec3f::~vec3f()
{
    
}
//********************(*//
//** CONST OPERATIONS **//
//**********************//
vec3f
vec3f::crossProduct(const vec3f& other) const
{
    vec3f result = vec3f(0.f, 0.f, 0.f);
    result.m_x = (this->m_y * other.m_z) - (this->m_z * other.m_y);
    result.m_y = (this->m_z * other.m_x) + (this->m_x * other.m_z);
    result.m_z = (this->m_x * other.m_y) - (this->m_y * other.m_x);
    
    return result;
}

float
vec3f::dotProduct(const vec3f& other) const
{
    float result = 0.f;
    result += (this->m_x * other.m_x);
    result += (this->m_y * other.m_y);
    result += (this->m_z * other.m_z);
    
    return result;
}

float
vec3f::getMagnitude() const
{
    return sqrt(getMagnitudeSquared());
}

float
vec3f::getMagnitudeSquared() const
{
    float result = 0.f;
    result += m_x * m_x;
    result += m_y * m_y;
    result += m_z * m_z;
    
    return result;
}

std::string
vec3f::getString() const
{
    std::string result = "vec4f: ";
    
    result +=   "m_x="+std::to_string(m_x);
    result += ", m_y="+std::to_string(m_y);
    result += ", m_z="+std::to_string(m_y)+"\n";
    
    return result;
}
//**************//
//** MUTATORS **//
//**************//
void
vec3f::normalize()
{
    (*this) /= this->getMagnitude();
}
//************************//
//** OPERATOR OVERLOADS **//
//************************//
float
vec3f::operator[] (const int& index) const
{
    assert(index >= 0);
    assert(index <= 2);
    
    float result = 0.f;
    switch (index)
    {
        case 0:
            result = m_x;
            break;
        case 1:
            result = m_y;
            break;
        case 2:
            result = m_z;
    }
    
    return result;
}

vec3f&
vec3f::operator= (const vec3f& other)
{
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_z = other.m_z;
    
    return *this;
}

vec3f
vec3f::operator+ (const vec3f& other) const
{
    vec3f result = vec3f(0.f, 0.f, 0.f);
    result.m_x = this->m_x + other.m_x;
    result.m_y = this->m_y + other.m_y;
    result.m_z = this->m_z + other.m_z;
    
    return result;
}
void
vec3f::operator+= (const vec3f& other)
{
    *this = *this + other;
}

vec3f
vec3f::operator-  (const vec3f& other) const
{
    vec3f result = vec3f();
    result.m_x = this->m_x - other.m_x;
    result.m_y = this->m_y - other.m_y;
    result.m_z = this->m_z - other.m_z;
    
    return result;
}

void
vec3f::operator-=  (const vec3f& other)
{
    *this = *this - other;
}

vec3f
vec3f::operator*  (const float& scale) const
{
    vec3f result = vec3f();
    result.m_x = this->m_x * scale;
    result.m_y = this->m_y * scale;
    result.m_z = this->m_z * scale;
    
    return result;
}


void
vec3f::operator*=  (const float& scale)
{
    this->m_x *= scale;
    this->m_y *= scale;
    this->m_z *= scale;

}

vec3f
vec3f::operator/  (const float& scale) const
{
    vec3f result = vec3f();
    
    result.m_x = this->m_x/scale;
    result.m_y = this->m_y/scale;
    result.m_z = this->m_z/scale;
    
    return result;
}

void
vec3f::operator/=  (const float& rhs)
{
    this->m_x /= rhs;
    this->m_y /= rhs;
    this->m_z /= rhs;
}

