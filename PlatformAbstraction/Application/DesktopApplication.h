#pragma once

#include "Application.h"

// this subclass of Application is for Desktop platforms
// e.g. Windows, Mac, Linux
// we'll probably use SDL/OpenGL so this one Application class
// will work for all 3 platforms

class DesktopApplication : public Application
{
	void InitApplication();
	void QuitApplication();
};