
#ifndef __TANGODJ_PLAYLISTCOMPONENT_H__
#define __TANGODJ_PLAYLISTCOMPONENT_H__

#include "../../Common/Headers.h"
#include "../../Core/Audio/MainAudioPlayer.h"
#include "../../Core/Playlist/PlaylistManager.h"
#include "../../Core/Playlist/Playlist.h"
#include "../../Core/Manager/CoreManager.h"
class PlayListComponent :   public Component,
public ListBoxModel,
public FileDragAndDropTarget,
public DragAndDropTarget,
public ActionListener
{
public:
    
    PlayListComponent (CoreManager* coreManager);
    ~PlayListComponent();
    
    // Component interface
    /* This resize and set components on screen */
    void resized ();
    /* This paints graphical components */
    void paint (Graphics & g);
	void actionListenerCallback (const String& message);
    
    // ListBoxModel interface
    /* Get the Number of Rows in a playListBox */
    virtual int getNumRows();
    /* Paints the playListBox at regular interval */
    virtual void paintListBoxItem (int rowNumber, Graphics & g, int width, int height, bool rowIsSelected);
    /** Delete a song from the PlayList */
    void deleteKeyPressed (int rowSelected);
    /** Play a song from the PlayList when return key is pressed */
    void returnKeyPressed (int lastRowSelected);
    /** Play a song from the PlayList when the item is double clicked */
    void listBoxItemDoubleClicked (int row, const MouseEvent & e);
    void listBoxItemClicked (int row, const MouseEvent& e);
    //FileDragAndDropTarget interface
    /**	Callback to check whether this target is interested in the set of files being offered */
    virtual bool isInterestedInFileDrag (const StringArray & files);
    /** Callback to indicate that the user has dropped the files onto this component */
    virtual void filesDropped (const StringArray & files, int x, int y);
    
    
    ///* Drag and Drop feature in the ListBox */
    var getDragSourceDescription(const SparseSet<int>& selectedRows);
    virtual void itemDropped (const SourceDetails & dragSourceDetails);
    virtual bool isInterestedInDragSource (const SourceDetails & dragSourceDetails);
    virtual void itemDragMove (const SourceDetails& dragSourceDetails);
    virtual void itemDragExit  (const SourceDetails&);
    
    //Class Methods
    /** Get current playList from mediaArray in String
     ble click or keyboard enter */
    void songPlayedByClick(const int index);
    
    
private:
    //Members
    /** The index for the playing song */
    int                                     playingSongIndex;
    /** The index for the playing song */
    int                                     dropIndex;
    /** playListBox contains the list of Songs */
    ScopedPointer<ListBox>					playListBox;
    /** Browse button to browse the audio files from the disk */
    ScopedPointer<ImageButton>				browseImageButton;
    
    /** Contains the audio formats supported by the Player */
    AudioFormatManager						audioFormatManager;
    MainAudioPlayer* audioPlayer;
    PlaylistManager* playlistManager;
    Playlist* currentPlaylist;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayListComponent)
};

#endif   // __TANGODJ_PLAYLISTCOMPONENT_H__
