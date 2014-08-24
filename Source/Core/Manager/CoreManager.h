/*
  ==============================================================================

    AudioManager.h
    Created: 22 Dec 2013 6:56:52pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef COREMANAGER_H_INCLUDED
#define COREMANAGER_H_INCLUDED

#include "../../Common/Headers.h"
#include "../Playlist/PlaylistManager.h"
#include "../Audio/MainAudioPlayer.h"


class  CoreManager
{
public:
    //==============================================================================
    CoreManager();
    ~CoreManager();
    
    MainAudioPlayer* getAudioPlayer();
    PlaylistManager* getPlaylistManager();
private:
    ScopedPointer<MainAudioPlayer> audioPlayer;
    ScopedPointer<PlaylistManager> playListManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CoreManager)
};

#endif  // COREMANAGER_H_INCLUDED
