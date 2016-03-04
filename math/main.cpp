#include "mat3f.h"
#include "vec3f.h"
//#include "vec4f.h"
//#include "mat4f.h"
#include <iostream>
#include <string>

int main()
{
    std::cout<<"LeeEngine says, \"Hello World!\""<<std::endl;
    std::cout<<std::endl;
    
    vec3f vector = vec3f();
    std::cout << "Expeted Result: 0 vector" << std::endl;
    std::cout << "Actual Result:" << std::endl;
    std::cout << vector.getString();
    
    mat3f mat3= mat3f();
    std::cout << "Expeted Result: 0 mat3f" << std::endl;
    std::cout << "Actual Result:" << std::endl;
    std::cout << mat3.getString();
    
//    vec4f vec4 = vec4f();
//    std::cout << "Expeted Result: 0 vector" << std::endl;
//    std::cout << "Actual Result:" << std::endl;
//    std::cout << vec4.getString() << std::endl;
    
//    mat4f mat4= mat4f();
//    std::cout << "Expeted Result: 0 mat4f" << std::endl;
//    std::cout << "Actual Result:" << std::endl;
//    std::cout << mat4.getString();
    
}
