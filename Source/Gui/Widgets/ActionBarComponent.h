/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_3C924A6B77C37EC4__
#define __JUCE_HEADER_3C924A6B77C37EC4__

//[Headers]     -- You can add your own extra header files here --
#include "../../Common/Headers.h"
#include "../../Core/Playlist/PlaylistManager.h"
#include "../../Core/Manager/CoreManager.h"
#include "../../Core/Audio/MainAudioPlayer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ActionBarComponent  : public Component,
                            public ButtonListener
{
public:
    //==============================================================================
    ActionBarComponent (CoreManager* coreManager);
    ~ActionBarComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PlaylistManager* playlistManager;
    MainAudioPlayer* audioPlayer;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> saveplayListButton;
    ScopedPointer<TextButton> importplayListButton;
    ScopedPointer<TextButton> clearPlaylist;
    ScopedPointer<TextButton> settingsButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActionBarComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3C924A6B77C37EC4__
