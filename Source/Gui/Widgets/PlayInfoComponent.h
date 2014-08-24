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

#ifndef __JUCE_HEADER_51153A3C2203555E__
#define __JUCE_HEADER_51153A3C2203555E__

//[Headers]     -- You can add your own extra header files here --
#include "../../Common/Headers.h"
#include "../../Core/Audio/MainAudioPlayer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PlayInfoComponent  : public Component,
                           public ActionListener,
                           public Timer,
                           public SliderListener
{
public:
    //==============================================================================
    PlayInfoComponent (MainAudioPlayer* audioPlayer_);
    ~PlayInfoComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void hideComponents();
    void showComponents();
    void actionListenerCallback (const String& message);
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);

    // Binary resources:
    static const char* default_album_jpg;
    static const int default_album_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainAudioPlayer* audioPlayer;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> songLabel;
    ScopedPointer<Label> artistTitle;
    ScopedPointer<Slider> sliderSongTime;
    ScopedPointer<Label> timeLabel;
    ScopedPointer<Label> tangoDJLabel;
    Image cachedImage_default_album_jpg;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayInfoComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_51153A3C2203555E__
