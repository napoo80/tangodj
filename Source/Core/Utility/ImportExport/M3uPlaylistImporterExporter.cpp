/*
  ==============================================================================

    M3uPlaylistIO.cpp
    Created: 26 Jan 2014 5:16:48pm
    Author:  Gaston

  ==============================================================================
*/

/*#include "M3uPlaylistImporterExporter.h"
#include "../SongHelper.h"

M3uPlaylistImporterExporter::M3uPlaylistImporterExporter()   : PlaylistImporterExporter("m3u", ".m3u .m3u8"){}

//M3uPlaylistImporterExporter::M3uPlaylistImporterExporter()   : PlaylistImporterExporter("m3u", ".m3u .m3u8"){}

void M3uPlaylistImporterExporter::importPlaylist(const File& fileToImport, Playlist* playlist){
    }


void M3uPlaylistImporterExporter::exportPlaylist(const File& fileToTest, Playlist* playlist){
    
}

void M3uPlaylistImporterExporter::run(){

    Logger *log = Logger::getCurrentLogger();
    FileInputStream stream (operationFile);
    if (!stream.openedOk()) {
        log->writeToLog ("failed to open stream");
    }else{
        String line = stream.readNextLine();
        bool lastLineExtInf = false;
        while (line.length())
        {
            if(line.contains("#EXTINF")){
                lastLineExtInf = true;
            }else if(lastLineExtInf){
                lastLineExtInf = false;
                if(!line.isEmpty()){
                    playlist->addSong(SongHelper::parseFromPath(line));
                }
            }
            line = stream.readNextLine();
        }
    }

    
}*/