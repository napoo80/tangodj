
#include "PlayListComponent.h"
#include <iostream>
#include "../../Core/Utility/SongHelper.h"

PlayListComponent::PlayListComponent (CoreManager* coreManager)
{
    playlistManager = coreManager->getPlaylistManager();
    currentPlaylist = playlistManager->getCurrentPlaylist();
    audioPlayer = coreManager->getAudioPlayer();
	playListBox = nullptr;
    addAndMakeVisible (playListBox = new ListBox ("PlayList", this));
    //playListBox->setLookAndFeel(&csLnF);
    playListBox->setRowHeight (30);
    playListBox->setColour (ListBox::backgroundColourId, Colour (0xff222222));
	playListBox->setMultipleSelectionEnabled (true);
    LookAndFeel::getDefaultLookAndFeel().setColour(TextEditor::textColourId, Colours::grey);
    setLookAndFeel(&LookAndFeel::getDefaultLookAndFeel());
    audioFormatManager.registerBasicFormats();
    audioPlayer->addActionListener(this);
    playlistManager->addActionListener(this);
    dropIndex = -1;
}

PlayListComponent::~PlayListComponent()
{
}

void PlayListComponent::resized()
{
    playListBox->setBounds (0, 0, getWidth(), getHeight());
}

void PlayListComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff222222));
}

int PlayListComponent::getNumRows()
{
    int size = currentPlaylist->size();
	return size;
}

void PlayListComponent::paintListBoxItem (int rowNumber, Graphics & g, int width, int height, bool rowIsSelected)
{
    
    Song currentSong = currentPlaylist->getSong(rowNumber);
    //g.fillAll (Colour (0xff292929));
    
    g.fillAll (Colour (0xff222222));
    
    /*g.setGradientFill (ColourGradient (Colours::darkgrey,
     128.0f, static_cast<float> (-56),
     Colours::black,
     128.0f, 80.0f,
     false));
     */
    
    if(currentSong.isCortina){
        g.fillAll (Colour (0xff292929));
    }
    //g.fillRect (0, 0, 350, 30);
    
    if (rowIsSelected)
    {
        g.fillAll (Colours::darkgrey);
        g.setColour (Colours::white);
    }
    if(!currentSong.isEmpty()){
        
        g.setColour (Colour (0xff666666));
        
        int fontType = Font::plain;
        if (rowNumber == audioPlayer->getCurrentSongIndex())
        {
            g.setColour (Colour(0xffa6ca64));
            fontType = Font::plain;
        }else{
            g.setColour (Colour (0xffcfcfcf));
        }
        
        if(currentSong.isCortina){
            g.setFont (Font (13.00f, fontType));
            g.drawText ("- " + currentSong.name + " -",
                        0, 0, 336, 30,
                        Justification::centred, true);
        }else{
            
            /*g.drawText (String(rowNumber + 1),
             3, 0, 13, 30,
             Justification::centred, true);*/
            
            
            g.setFont (Font (14.00f, fontType));
            g.drawText (currentSong.name,
                        27, 0, 152, 30,
                        Justification::centredLeft, true);
            
            g.setColour (Colour (0xff666666));
            g.setFont (Font (10.00f, Font::plain));
            
            g.setColour (Colour (0xff858585));
            g.setFont (Font (13.00f, Font::plain));
            g.drawText (currentSong.artist,
                        185, 0, 125, 30,
                        Justification::centredLeft, true);
            
            g.setColour (Colour (0xff858585));
            g.setFont (Font (12.00f, Font::plain));
            
            
            String gender = currentSong.gender;
            
            String letter = "o";
            if(gender.equalsIgnoreCase("tango")){
                letter = "t";
            }else if(gender.equalsIgnoreCase("milonga")){
                letter = "m";
            }else if(gender.equalsIgnoreCase("vals")){
                letter = "v";
            }
            g.drawText (letter,
                        3, 0, 13, 30,
                        Justification::centred, true);
            
            
            g.drawText (String(currentSong.year),
                        315, 0, 28, 30,
                        Justification::centredRight, true);
            if(currentSong.isCortina){
                
                g.setColour (Colour (0xff464646));
                g.fillRect (0, 0, 350, 1);
                
                g.setColour (Colour (0xff464646));
                g.fillRect (0, 29, 350, 1);
            }
            
            
            
        }
        
        if(rowNumber == dropIndex){
            g.setColour (Colour (0xff719664));
            g.fillRect (0, 0, 350, 1);
        }else{
            if(dropIndex == currentPlaylist->size() && rowNumber == currentPlaylist->size()-1){
                g.setColour (Colour (0xff719664));
                g.fillRect (0, 29, 350, 1);
            }
        }}
    
}
/*
 
 g.fillAll (Colour (0xff222222));
 g.fillAll (Colour (0xff292929));
 g.fillRect (0, 0, 350, 30);
 
 //g.setColour (Colour (0xff52684c));
 int fontType = Font::plain;
 if (rowNumber == audioPlayer->getCurrentSongIndex())
 {
 g.setColour (Colour(0xffa6ca64));
 fontType = Font::bold;
 }else{
 g.setColour (Colour (0xffcfcfcf));
 }
 
 */


void PlayListComponent::deleteKeyPressed (int /*rowSelected*/)
{
    if(playListBox->getNumSelectedRows())
    {
        const SparseSet <int> currentSelected = playListBox->getSelectedRows();
        for(int i = 0; i < currentSelected.size(); i++)
        {
            currentPlaylist->removeSong(currentSelected[i] - i);
        }
        playListBox->deselectAllRows();
        playListBox->updateContent();
    }
    
}

void PlayListComponent::returnKeyPressed (int lastRowSelected)
{
    songPlayedByClick(lastRowSelected);
}

void PlayListComponent::listBoxItemDoubleClicked (int row, const MouseEvent & /*e*/)
{
    songPlayedByClick(row);
}

void PlayListComponent::songPlayedByClick(const int index)
{
    playListBox->deselectAllRows();
    playListBox->selectRow(index);
    audioPlayer->play(index);
    playListBox->repaint();
}

void PlayListComponent::listBoxItemClicked (int row, const MouseEvent& e){
    
    // for popup menu's item selection use result
    int result = 0;
    
    const SparseSet <int> currentSelected = playListBox->getSelectedRows();
    if(e.mods.isLeftButtonDown())
    {
        // do stuff for left mouse click
    }else if(e.mods.isRightButtonDown())
    {
        PopupMenu rightClickMenu;
        if(currentSelected.size()==1){
            if(currentPlaylist->getSong(row).isCortina){
                rightClickMenu.addItem (1, "Unmark as cortina", true);
            }else{
                rightClickMenu.addItem (1, "Mark as cortina", true);
            }
        }
        rightClickMenu.addItem (2, "Delete", true);
        result = rightClickMenu.show();
    }
    
    if(result != 0)
    {
        if(result == 1)
        {
            currentPlaylist->toggleCortinaTag(row);
            playListBox->deselectAllRows();
        }else if (result == 2)
        {
            deleteKeyPressed(row);
        }
    }
}

bool PlayListComponent::isInterestedInFileDrag (const StringArray & /*filesNamesArray*/)
{
    return true;
}

void PlayListComponent::filesDropped (const StringArray & filesNamesArray, int x, int y)
{
    //String audioFormats = audioFormatManager.getWildcardForAllFormats();
    for(int i = 0; i < filesNamesArray.size(); i++)
    {
        
        currentPlaylist->addSong(SongHelper::parseFromPath(filesNamesArray[i]));
        //}else{
          //  DBG("Format not supported! : " + String(tempFile.getFileExtension()));
        //}
    }
}

var PlayListComponent::getDragSourceDescription(const SparseSet<int>& selectedRows)
{
    String desc;
    for (int i = 0; i < selectedRows.size(); ++i)
        desc << (selectedRows [i] + 1) << " ";
    playListBox->updateContent();
    return desc.trim();
}

void PlayListComponent::itemDropped (const SourceDetails & dragSourceDetails)
{
    int x = dragSourceDetails.localPosition.getX();
    int y =  dragSourceDetails.localPosition.getY();
    int insertionIndex = playListBox->getInsertionIndexForPosition (x, y);
    Array<int> sourceIndices;
    String sourceIndexString = dragSourceDetails.description.toString();
    
    while(sourceIndexString.length())
    {
        sourceIndices.add(sourceIndexString.upToFirstOccurrenceOf (" ", false, false).getIntValue() - 1);
        sourceIndexString = sourceIndexString.fromFirstOccurrenceOf (" ", false, false);
    }
    
    if(dropIndex != -1 && sourceIndices.size()>0){
        int moveIndex = dropIndex;
        int firstIndexToMove = sourceIndices.getReference(0);
        if(firstIndexToMove < insertionIndex){
            moveIndex = dropIndex-1;
        }
        currentPlaylist->moveSongs(moveIndex, sourceIndices);
        for(int i = 0; i < sourceIndices.size(); i++)
        {
            playListBox->selectRow (moveIndex + i);
        }
        playListBox->updateContent();
        repaint();
    }
    dropIndex = -1;
}

void PlayListComponent::itemDragMove (const SourceDetails& dragSourceDetails){
    int x = dragSourceDetails.localPosition.getX();
    int y =  dragSourceDetails.localPosition.getY()-10;
    int insertionIndex = playListBox->getInsertionIndexForPosition (x, y);
    dropIndex = insertionIndex;
    playListBox->repaint();
}

void PlayListComponent::itemDragExit (const SourceDetails& dragSourceDetails){
    dropIndex = -1;
}

bool PlayListComponent::isInterestedInDragSource (const SourceDetails & /*dragSourceDetails*/)
{
    return true;
}

void PlayListComponent::actionListenerCallback (const String& message){
    
    if (message.equalsIgnoreCase(Events::SONG_END) || message.equalsIgnoreCase(Events::SONG_START))
    {
        repaint();
    }
    if (message.equalsIgnoreCase(Events::PLAYLIST_UPDATED) || message.equalsIgnoreCase(Events::SONG_EDITED))
    {
        playListBox->updateContent();
    }
}

