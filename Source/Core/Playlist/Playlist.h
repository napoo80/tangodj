/*
  ==============================================================================

    Playlist.h
    Created: 12 Jan 2014 5:28:49pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include "../Library/Song.h"
#include "../../Common/Headers.h"


class Playlist
{

private:
    int playlistId;
    String name;
    Array<Song> songs;
    ActionBroadcaster* _broadcaster;
    int currentPlayIndex;
public:
    Playlist(int id_, String name_, ActionBroadcaster& broadcaster);
    ~Playlist();
    void addSong (Song song);
    void toggleCortinaTag (int index);
    void removeSong (int index);
    Song getSong(int index);
    Array<Song> getSongList();
    void setPlaylistName(String newName){name = newName;};
    int size();
    void setCurrentPlayIndex(const int index);
    int getCurrentPlayIndex();
    void moveSongs(int startIndex, Array<int> elements);
    void clean();
    
};


#endif  // PLAYLIST_H_INCLUDED
