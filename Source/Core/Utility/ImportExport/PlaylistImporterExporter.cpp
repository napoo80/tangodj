/*
  ==============================================================================

    MediaImporter.cpp
    Created: 29 Dec 2013 8:29:59pm
    Author:  Gaston

  ==============================================================================
*/

#include "PlaylistImporterExporter.h"


/*PlaylistImporterExporter::PlaylistImporterExporter (String name, StringArray extensions)
: Thread ("Import export thread"), formatName (name), fileExtensions (extensions), isProcessing(false), operationType(0)
{
}

PlaylistImporterExporter::PlaylistImporterExporter (StringRef name, StringRef extensions)
: Thread ("Import export thread"), formatName (name.text), fileExtensions (StringArray::fromTokens (extensions, false)) , isProcessing(false), operationType(0)
{
}
*/
PlaylistImporterExporter::~PlaylistImporterExporter()
{
}

bool PlaylistImporterExporter::canHandleFile (const File& f)
{
    for (int i = 0; i < fileExtensions.size(); ++i)
        if (f.hasFileExtension (fileExtensions[i]))
            return true;
    
    return false;
}

const String& PlaylistImporterExporter::getFormatName() const                { return formatName; }
const StringArray& PlaylistImporterExporter::getFileExtensions() const       { return fileExtensions; }
