/**
 *
 * Started On: Tuesday December 15 2015
 * By: Jonathan Plotner
 */

#include "FVector.hpp"

namespace SSym          //Company Name
{
namespace LeeEngine     //Project Name
{
    //******************//
    //** CONSTRUCTORS **//
    //******************//
    FVector::FVector()
    : m_X{0.f}
    , m_Y{0.f}
    , m_Z{0.f}
    {
        return;
    }
    
    FVector::FVector(const float& in_X
                    ,const float& in_Y
                    ,const float& in_Z
                     )
    : m_X{in_X}
    , m_Y{in_Y}
    , m_Z{in_Z}
    {
        return;
    }
    
    FVector::FVector(const FVector& in_Vector)
    : m_X{in_Vector.m_X}
    , m_Y{in_Vector.m_Y}
    , m_Z{in_Vector.m_Z}
    {
        return;
    }
    //********************(*//
    //** CONST OPERATIONS **//
    //**********************//
    FVector FVector::CrossProduct(const FVector& in_Vector) const
    {
        FVector r_CrossProduct = FVector(0.f, 0.f, 0.f);
        
        r_CrossProduct.m_X = (this->m_Y * in_Vector.m_Z) - (this->m_Z * in_Vector.m_Y);
        r_CrossProduct.m_Y = (this->m_Z * in_Vector.m_X) + (this->m_X * in_Vector.m_Z);
        r_CrossProduct.m_Z = (this->m_X * in_Vector.m_Y) - (this->m_Y * in_Vector.m_X);
        
        return r_CrossProduct;
    }
    
    float FVector::DotProduct(const FVector& in_Vector) const
    {
        float r_DotProduct = 0.f;
        
        r_DotProduct += (this->m_X * in_Vector.m_X);
        r_DotProduct += (this->m_Y * in_Vector.m_Y);
        r_DotProduct += (this->m_Z * in_Vector.m_Z);

        return r_DotProduct;
    }
    
    float FVector::GetMagnitude() const
    {
        float r_Magnitude = 0.f;
        
        r_Magnitude += m_X * m_X;
        r_Magnitude += m_Y * m_Y;
        r_Magnitude += m_Z * m_Z;
        
        r_Magnitude  = sqrt(r_Magnitude);
        
        return r_Magnitude;
    }
    
    float FVector::GetMagnitudeSquared() const
    {
        float r_MagnitudeSquared = 0.f;
        
        r_MagnitudeSquared += m_X * m_X;
        r_MagnitudeSquared += m_Y * m_Y;
        r_MagnitudeSquared += m_Z * m_Z;
        
        return r_MagnitudeSquared;
    }
    
    float FVector::GetX() const
    {
        return m_X;
    }
    
    float FVector::GetY() const
    {
        return m_Y;
    }
    
    float FVector::GetZ() const
    {
        return m_Z;
    }
    //**************//
    //** MUTATORS **//
    //**************//
    void FVector::Normalize()
    {
        (*this) /= this->GetMagnitude();
    }
    //************************//
    //** OPERATOR OVERLOADS **//
    //************************//
    float FVector::operator[] (const int& in_Index) const
    {
        float r_Val = 0.f;
        switch (in_Index)
        {
            case 0:
                r_Val = m_X;
            case 1:
                r_Val = m_Y;
            case 2:
                r_Val = m_Z;
        }

        return r_Val;
    }
    
    FVector FVector::operator+  (const FVector& in_V) const
    {
        FVector r_SummedVectors = FVector(0.f, 0.f, 0.f);
        
        r_SummedVectors.m_X = this->m_X + in_V.m_X;
        r_SummedVectors.m_Y = this->m_Y + in_V.m_Y;
        r_SummedVectors.m_Z = this->m_Z + in_V.m_Z;
        
        return r_SummedVectors;
    }
    
    FVector FVector::operator-  (const FVector& rhs) const
    {
        FVector r_SummedVectors = FVector(0.f, 0.f, 0.f);
        
        r_SummedVectors.m_X = this->m_X - rhs.m_X;
        r_SummedVectors.m_Y = this->m_Y - rhs.m_Y;
        r_SummedVectors.m_Z = this->m_Z - rhs.m_Z;
        
        return r_SummedVectors;
    }

    void operator+= (FVector& lhs, const FVector& rhs)
    {
        lhs.m_X += rhs.m_X;
        lhs.m_Y += rhs.m_Y;
        lhs.m_Z += rhs.m_Z;
    }

    void operator-=  (FVector& lhs, const FVector& rhs)
    {
        lhs.m_X -= rhs.m_X;
        lhs.m_Y -= rhs.m_Y;
        lhs.m_Z -= rhs.m_Z;
    }

    void operator*=  (FVector& lhs, const float& in_float)
    {
        lhs.m_X *= in_float;
        lhs.m_Y *= in_float;
        lhs.m_Z *= in_float;
    }

    void operator/=  (FVector& lhs, const float& in_float)
    {
        lhs.m_X /= in_float;
        lhs.m_Y /= in_float;
        lhs.m_Z /= in_float;
    }
    void FVector::operator/=  (const float& rhs)
    {
        this->m_X /= rhs;
        this->m_Y /= rhs;
        this->m_Z /= rhs;
    }
};//end namespace LeeEngine
};//end namespace SSym