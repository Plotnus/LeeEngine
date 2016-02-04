#pragma once

#if _WIN32 || _WIN64
#define LEE_ENGINE_PLAT_WIN
#endif

#ifdef __APPLE__
#define LEE_ENGINE_PLAT_MACOSX
#endif

#ifdef __linux__
#define LEE_ENGINE_PLAT_LINUX
#endif