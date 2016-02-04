#pragma once

#include "MemoryPool.h"

// call InitializeAllPools() on engine startup and ShutdownAllPools() on engine shutdown.
// I believe this strategy will work even on constrained platforms (as on those platforms
// you should just grab as much memory as possible anyway)

// the number of blocks for each pool might have to change though :(

extern void InitializeAllPools();
extern void ShutdownAllPools();

typedef MemoryPool<80, 8192> Pool80;