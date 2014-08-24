
#include "PlaylistPanel.h"

PlaylistPanel::PlaylistPanel (CoreManager* coreManager_) : coreManager(coreManager_)
{
    addAndMakeVisible( playInfoComponent = new PlayInfoComponent(coreManager->getAudioPlayer()) );
    addAndMakeVisible( playListComponent = new PlayListComponent(coreManager) );
    addAndMakeVisible( controlsComponent = new ControlsComponent(coreManager->getAudioPlayer()) );
    addAndMakeVisible( actionBarComponent = new ActionBarComponent(coreManager) );
	setSize(getWidth(), getHeight());
}

PlaylistPanel::~PlaylistPanel ()
{
    removeChildComponent(playInfoComponent);
    removeChildComponent(controlsComponent);
    removeChildComponent(playListComponent);
    removeChildComponent(actionBarComponent);
}
void PlaylistPanel::resized ()
{
    playInfoComponent->setBounds(0, 0, getWidth(), 90);
    controlsComponent->setBounds(0, 90, getWidth(), 35);
    playListComponent->setBounds(0, 125, getWidth(), getHeight()-160);
    actionBarComponent->setBounds(0, getHeight()-35, getWidth(), 35);
}
void PlaylistPanel::paint (Graphics & g)
{
    // backGround Filling
    g.fillAll (Colour (0xff292929));
}

ControlsComponent * PlaylistPanel::getControlsComponent()
{
    return controlsComponent;
}
