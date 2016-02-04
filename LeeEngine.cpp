// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LeeEngineConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
 
#include "PlatformAbstraction/Application/PlatformApplication.h"

static void LeeEngineMathTests(char** argv)
{
    double inputValue = atof(argv[1]);

    #ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
    #else
    double outputValue = sqrt(inputValue);
    #endif

    fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
}

int main (int argc, char *argv[])
{
    // also cmd line parsing should be separated too because it COULD get complicated idk
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d.%d\n", argv[0],
                LeeEngine_VERSION_MAJOR,
                LeeEngine_VERSION_MINOR,
                LeeEngine_VERSION_PATCH);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }

    // eventually we need to make this main function a bit more complex, because i know that ios will need some changes
    // same with android (definitely android lol...that java)
    // for now though, start up our shit
    Application* theGame = new PlatformApplication();
    theGame->InitApplication();

    LeeEngineMathTests();

    theGame->QuitApplication();
    delete theGame;

    return 0;
}

