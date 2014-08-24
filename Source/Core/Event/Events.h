/*
  ==============================================================================

    Events.h
    Created: 29 Dec 2013 10:14:39pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED
#include "JuceHeader.h"

class Events
{
public:
    
    static const String PLAY;
    static const String PAUSE;
    static const String STOP;
    static const String SONG_START;
    static const String SONG_END;
	static const String SONG_ADDED;
	static const String SONG_REMOVED;
    static const String SONG_EDITED;
    
     static const String GAIN_CHANGE;
    static const String PLAYLIST_UPDATED;
    static const String CURRENT_PLAYLIST_CHANGE;
    
    
private:
    Events(){};
};



#endif  // EVENTS_H_INCLUDED
