/*
  ==============================================================================

    PlaylistManager.h
    Created: 12 Jan 2014 5:54:31pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef PLAYLISTMANAGER_H_INCLUDED
#define PLAYLISTMANAGER_H_INCLUDED

#include "../../Common/Headers.h"
#include "../Library/Song.h"
#include "Playlist.h"

class PlaylistManager: public ActionBroadcaster
{

public:
    
    PlaylistManager ();
    ~PlaylistManager ();
    int addPlaylist();
    void removePlaylist(int index);
    Playlist* getPlaylist(int index);
    void cleanPlaylist(int index);
    int getCurrentPlaylistIndex();
    Playlist* getCurrentPlaylist();
    void savePlaylist(int playListId);
    void importPlaylist();
    

private:
    
    Array<Playlist> playlists;
    int currentPlaylist;

};


#endif  // PLAYLISTMANAGER_H_INCLUDED
