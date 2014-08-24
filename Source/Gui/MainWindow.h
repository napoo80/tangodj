#ifndef __TANGODJ_MAINWINDOW_H__
#define __TANGODJ_MAINWINDOW_H__

#include "../Common/Headers.h"
#include "LookAndFeel/LookAndFeel.h"

//==============================================================================
class MainAppWindow   : public DocumentWindow
{
public:
    //==============================================================================
    MainAppWindow();
    ~MainAppWindow();
    
    void closeButtonPressed();
    
    
    /* Note: Be careful when overriding DocumentWindow methods - the base class
     uses a lot of them, so by overriding you might break its functionality.
     It's best to do all your work in you content component instead, but if
     you really have to override any DocumentWindow methods, make sure your
     implementation calls the superclass's method.
     */
    
private:
    TangoDJLookAndFeel lookAndFeel;
    void setupColours();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAppWindow)
};


#endif  // __TANGODJ_MAINWINDOW_H__
