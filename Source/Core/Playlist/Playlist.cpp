/*
  ==============================================================================

    Playlist.cpp
    Created: 12 Jan 2014 6:15:33pm
    Author:  Gaston

  ==============================================================================
*/

#include "Playlist.h"

Playlist::Playlist(int id_, String name_, ActionBroadcaster& broadcaster): playlistId(id_)
{
    name = name_;
    _broadcaster = &broadcaster;
    currentPlayIndex = -1;
}

Playlist::~Playlist(){
}

void Playlist::addSong (Song song){
    songs.add(song);
    if(song.sampleRate >= 44100.0){
        _broadcaster->sendActionMessage(Events::PLAYLIST_UPDATED);
    }else{
        AlertWindow::showMessageBoxAsync (AlertWindow::NoIcon,
                                          "Cannot be added",
                                          "Sample rate under 41.000 kHz in not supported yet.",
                                          "ok");

    }
    
}
void Playlist::removeSong (int index){
    if(-1 < index && index < songs.size()){
        
        if(currentPlayIndex>index){
            currentPlayIndex--;
        } else if(currentPlayIndex == index){
            currentPlayIndex= -1;
        }
        songs.remove(index);
        _broadcaster->sendActionMessage(Events::PLAYLIST_UPDATED);
    }
}
Song Playlist::getSong(int index){
    
    if(index < songs.size()){
        return songs.getReference(index);
    }else{
        return EMPTY_SONG;
    }
}

void Playlist::toggleCortinaTag (int index){
    Song song = songs.getReference(index);
    song.isCortina = !song.isCortina;
    songs.set(index, song);
    _broadcaster->sendActionMessage(Events::SONG_EDITED);
}

Array<Song> Playlist::getSongList(){
    return songs;
}

int Playlist::size(){
    return songs.size();
}

void Playlist::setCurrentPlayIndex(const int index){
    currentPlayIndex = index;
}
int Playlist::getCurrentPlayIndex(){
    return currentPlayIndex;
}

void Playlist::clean(){
    songs.clear();
    currentPlayIndex = -1;
     _broadcaster->sendActionMessage(Events::PLAYLIST_UPDATED);
}

void Playlist::moveSongs(int startIndex, Array<int> elements){
    if(startIndex > -1 && startIndex < songs.size()){
        int itemOffset = 0;
        int indexOffset = 0;
        
        for (int i = 0;  i < elements.size(); i++)
        {
            int indexFrom = elements.getReference(i) + itemOffset;
            int indexTo = startIndex + indexOffset;
            String move = String("Song move: ") + String(indexFrom) + String("-->") + String(indexTo);
            DBG(move);
            if(indexFrom == currentPlayIndex){
                currentPlayIndex = indexTo;
            }else{
                if(indexFrom >= currentPlayIndex && indexTo<=currentPlayIndex){
                    currentPlayIndex++;
                }else if(indexFrom <= currentPlayIndex && indexTo>=currentPlayIndex){
                    currentPlayIndex--;
                }
            }
            songs.move(indexFrom, indexTo);
            
            if(elements.size()>i+1 && startIndex >= elements.getReference(i+1)){
                itemOffset--;
            }else {
                itemOffset= 0;
            }
            
            
            indexOffset++;
            
        }
        _broadcaster->sendActionMessage(Events::PLAYLIST_UPDATED);
    }
    
    DBG("----------");
}