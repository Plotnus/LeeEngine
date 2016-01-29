#pragma once

#if _WIN32 || _WIN64
#if _WIN64
#define LEE_ENV_64
#else
#define LEE_ENV_32
#endif

#if __GNUC__ // for gcc... we still need to handle clang
#if __x86_64__
#define LEE_ENV_64
#else
#define LEE_ENV_32
#endif
