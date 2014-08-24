#include "MainWindow.h"
#include "MainComponent.h"


MainAppWindow::MainAppWindow()
: DocumentWindow (JUCEApplication::getInstance()->getApplicationName(),
                  Colours::darkgrey,
                  DocumentWindow::allButtons)
{
    setUsingNativeTitleBar (true);
    //setTitleBarHeight(10);
    LookAndFeel::setDefaultLookAndFeel (&lookAndFeel);
    setupColours();
    
	MainComponent * const contentComponent = new MainComponent ();
    
    setContentOwned (contentComponent, false);
	setVisible (true);
    setResizable (true, true);
	setTopLeftPosition(0,0);
	Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
	//int x = r.getWidth();
	int height = r.getHeight();
    setResizeLimits (350, 350, 350, height);
	setSize(350, height);
}

MainAppWindow::~MainAppWindow()
{
}

void MainAppWindow::closeButtonPressed()
{
    MessageManager::getInstanceWithoutCreating()->deleteInstance();
    JUCEApplication::getInstance()->systemRequestedQuit();
}

void MainAppWindow::setupColours()
{
    LookAndFeel& laf = getLookAndFeel();
    laf.setColour (TextButton::buttonColourId, Colours::lightgrey);
    laf.setColour (TextButton::buttonOnColourId, Colours::grey);
    laf.setColour (ToggleButton::textColourId, Colours::white);
    laf.setColour (Slider::rotarySliderFillColourId, Colours::white);
}
