/*
  ==============================================================================

    SongHelper.cpp
    Created: 22 Jan 2014 5:29:11pm
    Author:  Gaston

  ==============================================================================
*/

#include "SongHelper.h"
#include "MetaData/TagReader.h"

static const double oneOver60 = 1.0 / 60.0;

namespace SongHelper
{
    Song parseFromPath(String path)
    {
        File tempFile(path);
        //AudioFormatReader* audioFormatReader = audioFormatManager.createReaderFor(tempFile);
        //if(audioFormatReader != nullptr){
        Song song = TagReader::parseSong(tempFile);
        return song;
    }
    
    /** Converts a time in seconds to a timecode string displaying mins, secs and 1/10th secs.
     */
    const String timeToTimeString (const double seconds)
    {
        const double absSecs = fabs (seconds);
        const String sign ((seconds < 0) ? "-" : "");
        
        //    const int hours = (int) (absSecs * oneOver60Squared);
        const int mins  = ((uint32) (absSecs * oneOver60)) % 60u;
        const int secs  = ((uint32) absSecs) % 60u;
        //const int tenthSecs  = (int) ((absSecs - (int) absSecs) * 10);
        
        String t (sign);
        
        t	<< String (mins).paddedLeft ('0', 2) << ":"
		<< String (secs).paddedLeft ('0', 2); //<< "."
		//<< String (tenthSecs).paddedLeft ('0', 0);
        return t;
    }
}
