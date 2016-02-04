#pragma once

#if _WIN32 || _WIN64
#ifdef _WIN64
#define LEE_ENV_64
#else
#define LEE_ENV_32
#endif

#ifdef __GNUC__ || defined __clang__ // for gcc... we still need to handle clang
#ifdef __x86_64__
#define LEE_ENV_64
#else
#define LEE_ENV_32
#endif
