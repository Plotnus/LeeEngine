add_library(Math
	FMatrix.cpp
	FMatrix.hpp
	##
	FQuaternion.cpp
	FQuaternion.hpp
	##
	FVector.cpp
	FVector.hpp
	##
	GlobalConstants.cpp
	GlobalConstants.hpp
	##
	TNumericLimits.cpp
	TNumericLimits.hpp
	)
add_executable(FVectorTest FVector.cpp Tests/FVectorTest.cpp)
#add_executable(FMatrixTest FMatrix.cpp FMatrixTest.cpp)
#add_executable(FQuaternionTest FQuaternion.cpp FQuaternionTest.cpp)
