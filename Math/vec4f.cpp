/**
 *
 * Started On: Tuesday December 15 2015
 * By: Jonathan Plotner
 */

#include "vec4f.h"
#include <cassert>
#include <cmath>

//******************//
//** CONSTRUCTORS **//
//******************//
vec4f::vec4f()
: m_x{0.f}
, m_y{0.f}
, m_z{0.f}
, m_w{0.f}
{

}

vec4f::vec4f(const float& x
            ,const float& y
            ,const float& z
            ,const float& w
                 )
: m_x{x}
, m_y{y}
, m_z{z}
, m_w{w}
{

}

vec4f::vec4f(const vec4f& vect)
: m_x{vect.m_x}
, m_y{vect.m_y}
, m_z{vect.m_z}
, m_w{vect.m_w}
{

}

vec4f::~vec4f()
{
    
}
//********************(*//
//** CONST OPERATIONS **//
//**********************//
vec4f
vec4f::crossProduct(const vec4f& other) const
{
    assert(this->m_w == 0.f);
    assert(other.m_w ==0.f);
    
    vec4f result = vec4f(0.f, 0.f, 0.f, 0.f);
    result.m_x = (this->m_y * other.m_z) - (this->m_z * other.m_y);
    result.m_y = (this->m_z * other.m_x) + (this->m_x * other.m_z);
    result.m_z = (this->m_x * other.m_y) - (this->m_y * other.m_x);
    
    return result;
}

float
vec4f::dotProduct(const vec4f& other) const
{
    assert(this->m_w == 0.f);
    assert(other.m_w == 0.f);
    
    float result = 0.f;
    result += (this->m_x * other.m_x);
    result += (this->m_y * other.m_y);
    result += (this->m_z * other.m_z);
    
    return result;
}

float
vec4f::getMagnitude() const
{
    assert(this->m_w == 0.f);
    
    return sqrt(getMagnitudeSquared());
}

float
vec4f::getMagnitudeSquared() const
{
    assert(this->m_w == 0.f);
    
    float result = 0.f;
    result += m_x * m_x;
    result += m_y * m_y;
    result += m_z * m_z;
    
    return result;
}

std::string
vec4f::getString() const
{
    std::string result = "vec4f:";
    result +=  " m_x=" + std::to_string(m_x);
    result += ", m_y=" + std::to_string(m_y);
    result += ", m_z=" + std::to_string(m_z);
    result += ", m_w=" + std::to_string(m_w);
    
    return result;
}

//**************//
//** MUTATORS **//
//**************//
void
vec4f::normalize()
{
    assert(this->m_w == 0.f);
    
    (*this) /= this->getMagnitude();
}
//************************//
//** OPERATOR OVERLOADS **//
//************************//
float
vec4f::operator[] (const int& index) const
{
    assert(index >= 0);
    assert(index <= 3);
    
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
            break;
        case 3:
            result = m_w;
            break;
    }
    
    return result;
}

vec4f&
vec4f::operator= (const vec4f& other)
{
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_z = other.m_z;
    this->m_w = other.m_w;
    
    return *this;
}

vec4f
vec4f::operator+ (const vec4f& other) const
{
    vec4f result = vec4f();
    result.m_x = this->m_x + other.m_x;
    result.m_y = this->m_y + other.m_y;
    result.m_z = this->m_z + other.m_z;
    result.m_w = this->m_w + other.m_w;
    
    if ( result.m_w > 1.f ) {result.m_w = 1.f;}
    
    return result;
}
void
vec4f::operator+= (const vec4f& other)
{
    *this = *this + other;
}

vec4f
vec4f::operator-  (const vec4f& other) const
{
    vec4f result = vec4f();
    result.m_x = this->m_x - other.m_x;
    result.m_y = this->m_y - other.m_y;
    result.m_z = this->m_z - other.m_z;
    result.m_w = this->m_w - other.m_w;
    
    //assert here to make sure that the operation makes sense mathematically
    /** @todo: insert code here so that the operation enforces proper conceptual usage */
    
    return result;
}

void
vec4f::operator-=  (const vec4f& other)
{
    *this = *this - other;
}

vec4f
vec4f::operator*  (const float& scale) const
{
    
    vec4f result = vec4f();
    result.m_x = this->m_x * scale;
    result.m_y = this->m_y * scale;
    result.m_z = this->m_z * scale;
    
    return result;
}


void
vec4f::operator*=  (const float& scale)
{
    this->m_x *= scale;
    this->m_y *= scale;
    this->m_z *= scale;

}
/** @todo: add component wise multiplication and division */

vec4f
vec4f::operator/  (const float& scale) const
{
    vec4f result = vec4f();
    
    result.m_x = this->m_x/scale;
    result.m_y = this->m_y/scale;
    result.m_z = this->m_z/scale;
    
    return result;
}

void
vec4f::operator/=  (const float& scale)
{
    this->m_x /= scale;
    this->m_y /= scale;
    this->m_z /= scale;
}
