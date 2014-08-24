/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_133557228_INCLUDED
#define BINARYDATA_H_133557228_INCLUDED

namespace BinaryData
{
    extern const char*   default_album_jpg;
    const int            default_album_jpgSize = 35621;

    extern const char*   icon_png;
    const int            icon_pngSize = 38317;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    extern const int namedResourceListSize;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
