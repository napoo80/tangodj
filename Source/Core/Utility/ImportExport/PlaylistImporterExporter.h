/*
  ==============================================================================

    MediaImporter.h
    Created: 29 Dec 2013 8:29:59pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef MEDIAIMPORTER_H_INCLUDED
#define MEDIAIMPORTER_H_INCLUDED
#include "../../../Common/Headers.h"
#include "../../Playlist/Playlist.h"

class PlaylistImporterExporter : public Thread
{
public:

    virtual ~PlaylistImporterExporter();

    const String& getFormatName() const;
    
    const StringArray& getFileExtensions() const;
    
    virtual bool canHandleFile (const File& file);
    
    //virtual void importPlaylist (const File& file, Playlist* playlist);
    
    //virtual void exportPlaylist (const File& file, Playlist* playlist);

    //virtual void run();

    
protected:

    //PlaylistImporterExporter (String formatName, StringArray fileExtensions);
    //PlaylistImporterExporter (StringRef name, StringRef extensions);
    File& operationFile;
    Playlist* playlist;
    int operationType;
    static const int IMPORT = 0;
    static const int EXPORT = 0;
    bool isProcessing;

private:
    
    //==============================================================================
    
    String formatName;
    StringArray fileExtensions;
    
};


#endif  // MEDIAIMPORTER_H_INCLUDED
