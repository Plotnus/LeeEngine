#include "Pools.h"

void InitializeAllPools()
{
	Pool80::get().StartUp();
}

void ShutdownAllPools()
{
	Pool80::get().ShutDown();
}