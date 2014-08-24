/*
  ==============================================================================

    AudioManager.cpp
    Created: 22 Dec 2013 6:56:52pm
    Author:  Gaston

  ==============================================================================
*/

#include "CoreManager.h"

CoreManager::CoreManager(){
    playListManager = new PlaylistManager();
    audioPlayer = new MainAudioPlayer();
    audioPlayer->setCurrentPlaylist(playListManager->getCurrentPlaylist());
    playListManager->addActionListener(audioPlayer);
}

CoreManager::~CoreManager ()
{
    audioPlayer = nullptr;
    playListManager = nullptr;
}

MainAudioPlayer* CoreManager::getAudioPlayer()
{
    return audioPlayer;
}

PlaylistManager* CoreManager::getPlaylistManager()
{
    return playListManager;
}