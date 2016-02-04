#pragma once

#include "Application.h"

#include "../PlatformDefines.h"

// this subclass of Application is for Desktop platforms
// e.g. Windows, Mac, Linux
// we'll probably use SDL/OpenGL so this one Application class
// will work for all 3 platforms

#if defined LEE_ENGINE_PLAT_WIN  || defined LEE_ENGINE_PLAT_MACOSX || defined LEE_ENGINE_PLAT_LINUX

class DesktopApplication : public Application
{
	void InitApplication() override;
	void QuitApplication() override;
};

#endif