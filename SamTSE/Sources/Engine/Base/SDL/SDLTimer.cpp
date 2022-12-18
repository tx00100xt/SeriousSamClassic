/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

/* rcg10072001 Moved stuff into this file. */
#define __STDC_LIMIT_MACROS 1

#include "SDL.h"
#include <Engine/Engine.h>
#include <Engine/Base/Timer.h>

void CTimer::Sleep(DWORD milliseconds)
{
    SDL_Delay(milliseconds);
}

// end of SDLTimer.cpp ...


