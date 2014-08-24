#ifndef __TANGODJ_MAINCOMPONENT_H__
#define __TANGODJ_MAINCOMPONENT_H__

#include "../Common/Headers.h"
#include "../Core/Audio/MainAudioPlayer.h"
#include "../Core/Manager/CoreManager.h"
#include "Panels/PlaylistPanel.h"


class MainComponent  : public Component, public DragAndDropContainer
{
public:
    
    MainComponent();
    ~MainComponent();
    
    void paint (Graphics& g);
    void resized();
    
    // Members
private:
    
    ScopedPointer<PlaylistPanel> playlistPanel;
    CoreManager* coreManager;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

#endif   // __TANGODJ_MAINCOMPONENT_H__