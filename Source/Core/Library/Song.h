/*
  ==============================================================================

    Song.h
    Created: 31 Dec 2013 3:43:55pm
    Author:  Gaston

  ==============================================================================
*/


#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED
#include "../../../JuceLibraryCode/JuceHeader.h"

struct Song
{
    // Members
public:
    String filePath;
    String name;
    String artist;
    String comment;
    uint year;
    String gender;
    double length;
    bool isCortina;
    double sampleRate;
    
    // Methods
   
public:
    Song()
    {
        name = "EMPTY";
        isCortina = false;
    }
    bool isEmpty(){
        return name == "EMPTY";
    }
    
};
#endif  // SONG_H_INCLUDED
