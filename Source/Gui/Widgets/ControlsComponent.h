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

#ifndef __JUCE_HEADER_EEFFF9A6E88064D2__
#define __JUCE_HEADER_EEFFF9A6E88064D2__

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
class ControlsComponent  : public Component,
                           public ActionListener,
                           public SliderListener,
                           public ButtonListener
{
public:
    //==============================================================================
    ControlsComponent (MainAudioPlayer* audioPlayer_);
    ~ControlsComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //Action Listener
    void actionListenerCallback (const String& message);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* volume_png;
    static const int volume_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainAudioPlayer* audioPlayer;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextButton> nextButton;
    ScopedPointer<TextButton> lockPlay;
    Image cachedImage_volume_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControlsComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_EEFFF9A6E88064D2__
