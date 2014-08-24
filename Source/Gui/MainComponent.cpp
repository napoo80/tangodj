#include "MainComponent.h"


MainComponent::MainComponent()
{
    
    coreManager = new CoreManager();
	playlistPanel = new PlaylistPanel(coreManager);
    addAndMakeVisible(playlistPanel);
}

MainComponent::~MainComponent ()
{
    removeChildComponent(playlistPanel);
    //delete coreManager;
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    
}

void MainComponent::resized()
{
    int width = getWidth();
    int height = getHeight();
	playlistPanel->setBounds (0, 0, width, height);
}




