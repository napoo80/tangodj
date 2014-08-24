/*
  ==============================================================================

    SongHelper.h
    Created: 22 Jan 2014 5:29:11pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef SONGHELPER_H_INCLUDED
#define SONGHELPER_H_INCLUDED

#include "../../Common/Headers.h"
#include "../../Core/Library/Song.h"

namespace SongHelper {
    Song parseFromPath(String path);
    const String timeToTimeString (const double seconds);
}


#endif  // SONGHELPER_H_INCLUDED
