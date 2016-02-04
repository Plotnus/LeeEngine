#include "DesktopApplication.h"

#include "../../Memory/Pools.h"

#if defined LEE_ENGINE_PLAT_WIN  || defined LEE_ENGINE_PLAT_MACOSX || defined LEE_ENGINE_PLAT_LINUX

void DesktopApplication::InitApplication()
{
	InitializeAllPools();
}

void DesktopApplication::QuitApplication()
{
	ShutdownAllPools();
}

#endif