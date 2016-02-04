#pragma once

#include "../PlatformDefines.h"

#if defined LEE_ENGINE_PLAT_WIN  || defined LEE_ENGINE_PLAT_MACOSX || defined LEE_ENGINE_PLAT_LINUX

#include "DesktopApplication.h"
typedef DesktopApplication PlatformApplication; // each subclass of Application should create a typedef like this

#endif