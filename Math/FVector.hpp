/**
 * "The large is done with the small." -Lao Tzu
 *
 * Created on Tuesday, December 15, 2015
 * By: Plotner
 * 
 *
 *
 */
#pragma once

#include <cmath>

namespace SSym      //Company Name
{
namespace LeeEngine //Project Name
{
    class FVector
    {
    public:
        //******************//
        //** CONSTRUCTORS **//
        //******************//
        /**
         * @brief Empty constructor sets values to zero
         */
        FVector();
        /**
         * @brief Constructor from individual floats
         * @param in_X float for the X value of the vector
         * @param in_Y float for the Y value of the vector
         * @param in_Z float for the Z value of the vector
         */
        FVector(const float& in_X, const float& in_Y, const float& in_Z);
        /**
         * @brief copy constructor
         * @param in_Vector the FVector that is being copied
         */
        FVector(const FVector& in_Vector);
        //********************//
        //** GET OPERATIONS **//
        //********************//
        /**
         * @brief
         */
        FVector CrossProduct(const FVector& in_Vector) const;
        /**
         * @brief
         */
        float DotProduct(const FVector& in_Vector) const;
        /**
         * @brief
         */
        float GetX() const;
        /**
         * @brief
         */
        float GetY() const;
        /**
         * @brief
         */
        float GetZ() const;
        /**
         * @brief
         */
        float GetMagnitude() const;
        /**
         * @brief
         */
        float GetMagnitudeSquared() const;

        
        //**************//
        //** MUTATORS **//
        //**************//
        
        /**
         * @brief
         */
        void Normalize();
        /**
         * @brief
         * @param
         * @param
         * @param
         */
        void Scale(const float in_ScaleX, const float in_ScaleY, const float in_ScaleZ);
        /**
         * @brief
         * @param
         */
        void ScaleUniform(const float in_UniformScale);
        
        
        
        //******************************//
        //** CONST OPERATOR OVERLOADS **//
       //*******************************//
        /**
         * @brief
         * @param
         */
        float operator[] (const int& in_Index) const;
        /**
         * @brief
         * @param
         */
        FVector operator+  (const FVector& in_V) const;
        /**
         * @brief
         * @param
         */
        void operator+= (const FVector& in_V);
        /**
         * @brief
         * @param
         */
        FVector operator-  (const FVector& in_V) const;
        /**
         * @brief
         * @param
         */
        float operator-= (const FVector& in_V);
        /**
         * @brief
         * @param
         */
        float operator*  (const float& in_Scale) const;
        /**
         * @brief
         * @param
         */
        float operator*= (const FVector& in_Scale);
        /**
         * @brief
         * @param
         */
        FVector operator/  (const float& in_Scale) const;
        /**
         * @brief
         * @param
         */
        void operator/= (const float& in_Scale);
        /**
         * @brief assignment
         * @param
         */
        void operator=  (const FVector& in_V);
        
        
        float m_X; /** The X value of the vector */
        float m_Y; /** The Y value of the vector */
        float m_Z; /** The Z value of the vector */
    protected:
    private:
        
    };

}
    
};