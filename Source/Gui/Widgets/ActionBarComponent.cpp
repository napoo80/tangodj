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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ActionBarComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ActionBarComponent::ActionBarComponent (CoreManager* coreManager)
{
    addAndMakeVisible (saveplayListButton = new TextButton (String::empty));
    saveplayListButton->setButtonText (TRANS("v"));
    saveplayListButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    saveplayListButton->addListener (this);
    saveplayListButton->setColour (TextButton::buttonColourId, Colour (0xff313132));
    saveplayListButton->setColour (TextButton::buttonOnColourId, Colour (0xff7a7ab0));

    addAndMakeVisible (importplayListButton = new TextButton (String::empty));
    importplayListButton->setButtonText (TRANS("^"));
    importplayListButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    importplayListButton->addListener (this);
    importplayListButton->setColour (TextButton::buttonColourId, Colour (0xff313132));
    importplayListButton->setColour (TextButton::buttonOnColourId, Colour (0xff7a7ab0));

    addAndMakeVisible (clearPlaylist = new TextButton (String::empty));
    clearPlaylist->setButtonText (TRANS("Clear"));
    clearPlaylist->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    clearPlaylist->addListener (this);
    clearPlaylist->setColour (TextButton::buttonColourId, Colour (0xff313132));
    clearPlaylist->setColour (TextButton::buttonOnColourId, Colour (0xff7a7ab0));

    addAndMakeVisible (settingsButton = new TextButton (String::empty));
    settingsButton->setButtonText (TRANS("*"));
    settingsButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    settingsButton->addListener (this);
    settingsButton->setColour (TextButton::buttonColourId, Colour (0xff313132));
    settingsButton->setColour (TextButton::buttonOnColourId, Colour (0xff7a7ab0));


    //[UserPreSize]
    //removeChildComponent(newplayListButton);

    //[/UserPreSize]

    setSize (350, 35);


    //[Constructor] You can add your own custom stuff here..
    playlistManager = coreManager->getPlaylistManager();
    audioPlayer = coreManager->getAudioPlayer();
    //[/Constructor]
}

ActionBarComponent::~ActionBarComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    saveplayListButton = nullptr;
    importplayListButton = nullptr;
    clearPlaylist = nullptr;
    settingsButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ActionBarComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1d1d1d));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ActionBarComponent::resized()
{
    saveplayListButton->setBounds (0, 0, 50, 35);
    importplayListButton->setBounds (51, 0, 50, 35);
    clearPlaylist->setBounds (248, 0, 50, 35);
    settingsButton->setBounds (299, 0, 50, 35);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ActionBarComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == saveplayListButton)
    {
        //[UserButtonCode_saveplayListButton] -- add your button handler code here..
        playlistManager->savePlaylist(0);
        //[/UserButtonCode_saveplayListButton]
    }
    else if (buttonThatWasClicked == importplayListButton)
    {
        //[UserButtonCode_importplayListButton] -- add your button handler code here..
        playlistManager->importPlaylist();
        //[/UserButtonCode_importplayListButton]
    }
    else if (buttonThatWasClicked == clearPlaylist)
    {
        //[UserButtonCode_clearPlaylist] -- add your button handler code here..
        playlistManager->cleanPlaylist(playlistManager->getCurrentPlaylistIndex());
        //[/UserButtonCode_clearPlaylist]
    }
    else if (buttonThatWasClicked == settingsButton)
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..
        audioPlayer->showAudioPreferences(this);
        //[/UserButtonCode_settingsButton]
    }

    //[UserbuttonClicked_Post]

    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ActionBarComponent" componentName=""
                 parentClasses="public Component" constructorParams="CoreManager* coreManager"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="350" initialHeight="35">
  <BACKGROUND backgroundColour="ff1d1d1d"/>
  <TEXTBUTTON name="" id="135db1df9fefe077" memberName="saveplayListButton"
              virtualName="" explicitFocusOrder="0" pos="0 0 50 35" bgColOff="ff313132"
              bgColOn="ff7a7ab0" buttonText="v" connectedEdges="15" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="" id="bfa4ae281d9747da" memberName="importplayListButton"
              virtualName="" explicitFocusOrder="0" pos="51 0 50 35" bgColOff="ff313132"
              bgColOn="ff7a7ab0" buttonText="&#94;" connectedEdges="15" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="" id="d53d89e50cdd2d09" memberName="clearPlaylist" virtualName=""
              explicitFocusOrder="0" pos="248 0 50 35" bgColOff="ff313132"
              bgColOn="ff7a7ab0" buttonText="Clear" connectedEdges="15" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="" id="7bb078e245bfa64e" memberName="settingsButton" virtualName=""
              explicitFocusOrder="0" pos="299 0 50 35" bgColOff="ff313132"
              bgColOn="ff7a7ab0" buttonText="*" connectedEdges="15" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
