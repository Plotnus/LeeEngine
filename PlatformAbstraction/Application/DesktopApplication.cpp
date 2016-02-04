#include "DesktopApplication.h"

#include "../../Memory/Pools.h"

void DesktopApplication::InitApplication()
{
	InitializeAllPools();
}

void DesktopApplication::QuitApplication()
{
	ShutdownAllPools();
}