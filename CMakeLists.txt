cmake_minimum_required (VERSION 3.1)
project (LeeEngine)

# SET COMPILER 
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

# ADD SUB DIRECTORIES
add_subdirectory(Math)
#add_subdirectory(Animation)
#add_subdirectory(Controllers)
#add_subdirectory(Graphics)
#add_subdirectory(Physics)
#add_subdirectory(Sound)
#add_subdirectory(Utilities)

# ADD EXECUTABLES
add_executable(LeeEngine LeeEngine.cpp)


