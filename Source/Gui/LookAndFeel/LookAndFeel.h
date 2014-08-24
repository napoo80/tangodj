/*
 *  DemoLookAndFeel.h
 *  dRowAudio Demo
 *
 *  Created by David Rowland on 29/12/2011.
 *  Copyright 2011 dRowAudio. All rights reserved.
 *
 */

#include "../../Common/Headers.h"

#ifndef __TANGODJ_LOOKANDFEEL_H__
#define __TANGODJ_LOOKANDFEEL_H__

class TangoDJLookAndFeel : public LookAndFeel_V3
{
public:
    TangoDJLookAndFeel();
    
    ~TangoDJLookAndFeel();

//    static void drawBevel (Graphics& g, Rectangle<int> innerBevelBounds, float bevelThickness, Colour baseColour);
//
//    static void drawBevel (Graphics& g, Rectangle<float> innerBevelBounds, float bevelThickness, Colour baseColour);
    
    /*void drawButtonBackground (Graphics& g,
                               Button& button,
                               const Colour& backgroundColour,
                               bool isMouseOverButton,
                               bool isButtonDown);
    */
private:
};

#endif  // __TANGODJ_LOOKANDFEEL_H__