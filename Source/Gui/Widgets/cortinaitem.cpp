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

#include "cortinaitem.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NewComponent::NewComponent ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (350, 30);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NewComponent::~NewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    g.setGradientFill (ColourGradient (Colours::darkgrey,
                                       128.0f, static_cast<float> (-56),
                                       Colours::black,
                                       128.0f, 80.0f,
                                       false));
    g.fillRect (0, 0, 350, 30);

    g.setColour (Colour (0xff52684c));
    g.setFont (Font (14.00f, Font::bold));
    g.drawText (TRANS("Amarras"),
                0, 0, 336, 30,
                Justification::centredRight, true);

    g.setColour (Colour (0xff464646));
    g.fillRect (0, 29, 350, 1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewComponent::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="350" initialHeight="30">
  <BACKGROUND backgroundColour="ff222222">
    <RECT pos="0 0 350 30" fill="linear: 128 -56, 128 80, 0=ff555555, 1=ff000000"
          hasStroke="0"/>
    <TEXT pos="0 0 336 30" fill="solid: ff52684c" hasStroke="0" text="Amarras"
          fontname="Default font" fontsize="14" bold="1" italic="0" justification="34"/>
    <RECT pos="0 29 350 1" fill="solid: ff464646" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
