/*
  ==============================================================================

    PlaylistManager.cpp
    Created: 12 Jan 2014 5:54:31pm
    Author:  Gaston

  ==============================================================================
*/

#include "PlaylistManager.h"
#include <iostream>
#include "../Utility/SongHelper.h"

PlaylistManager::PlaylistManager()
{
    if(playlists.size() == 0){
        //add default playlist
        addPlaylist();
    }
    currentPlaylist = 0;
}

PlaylistManager::~PlaylistManager (){
    
}
void PlaylistManager::savePlaylist(int playListId){
    
    Playlist playlist = playlists.getReference(playListId);
    
    if(playlist.size())
    {
	    /*XmlElement playlistElement ("playlist");
        playlistElement.setAttribute("xmlns", "http://xspf.org/ns/0/");
        playlistElement.setAttribute("version", "1");
	    XmlElement * trackListElement = playlistElement.createNewChildElement("trackList");
	    for(int i = 0; i < playlist.size(); i++){
            XmlElement * track = trackListElement->createNewChildElement("track");
            XmlElement * location = track->createNewChildElement("location");
            String value = "file:///" + URL::addEscapeChars(playlist.getSong(i).filePath, true);
            location->addChildElement(XmlElement::createTextElement(value));
        }
        
        
	    FileChooser fileSaver("Save PlayList", File::nonexistent, "*.xspf");
	    if(fileSaver.browseForFileToSave  (true))
	    {
		    String s = fileSaver.getResult().getFullPathName();
		    if(fileSaver.getResult().getFileName().contains("."))
			    s = s.dropLastCharacters (s.length() - s.indexOf("."));
		    s.append(".xspf", 5);
		    playlistElement.writeToFile (File::getCurrentWorkingDirectory().getChildFile (s), String::empty);
	    }*/
  
        
        FileChooser fileSaver("Save PlayList", File::nonexistent, "*.m3u");
	    if(fileSaver.browseForFileToSave  (true))
	    {
		    String s = fileSaver.getResult().getFullPathName();
		    if(fileSaver.getResult().getFileName().contains("."))
			    s = s.dropLastCharacters (s.length() - s.indexOf("."));
		    s.append(".m3u", 4);
            
            File file (File::getCurrentWorkingDirectory().getChildFile (s));
            Logger *log = Logger::getCurrentLogger();
            
            FileOutputStream stream (file);
            if (!stream.openedOk()) {
                log->writeToLog ("failed to open stream");
               
            }else{
                String m3uText ("#EXTM3U\n");
                for(int i = 0; i < playlist.size(); i++){
                    
                    Song song = playlist.getSong(i);
                    m3uText = m3uText + "#EXTINF:" + String(song.length) + "," + song.name + "\n";
                    m3uText = m3uText + song.filePath + "\n";
                }
                stream.setPosition (0);
                stream.truncate();
                bool asUTF16 = false;
                bool byteOrderMark = false;
                stream.writeText (m3uText, asUTF16, byteOrderMark);
            }
	    }
    }

}
void PlaylistManager::importPlaylist(){
    
    FileChooser chooser ("Choose an m3u playlist to import...", File::nonexistent, "*.m3u", true);
    if (chooser.browseForFileToOpen()) {
        
    }
}

void PlaylistManager::cleanPlaylist(int index){
    getPlaylist(index)->clean();
}

int PlaylistManager::getCurrentPlaylistIndex(){
    return currentPlaylist;
}

int PlaylistManager::addPlaylist(){
    int id = playlists.size() + 1;
    Playlist playlist(id, "", *this);
    playlists.add(playlist);
    return id;
}

void PlaylistManager::removePlaylist(int index){}

Playlist* PlaylistManager::getPlaylist(int index){
    return &playlists.getReference(index);
}

Playlist* PlaylistManager::getCurrentPlaylist(){
    return getPlaylist(currentPlaylist);
}