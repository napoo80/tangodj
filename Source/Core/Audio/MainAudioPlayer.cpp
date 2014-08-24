/*
  ==============================================================================

    AudioManager.cpp
    Created: 22 Dec 2013 6:56:52pm
    Author:  Gaston

  ==============================================================================
*/

#include "MainAudioPlayer.h"
#include <iostream>
#if JUCE_WINDOWS
#include <windows.h>
#endif
using namespace std;

#if JUCE_WINDOWS
void usleep(__int64 usec) 
{ 
    HANDLE timer; 
    LARGE_INTEGER ft; 

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL); 
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
    WaitForSingleObject(timer, INFINITE); 
    CloseHandle(timer); 
}
#endif


MainAudioPlayer::MainAudioPlayer() : bufferingThread("MainAudioPlayer AudioBuffer"){
    
    
    const String error (audioDeviceManager.initialise (0, /* number of input channels */
													   2, /* number of output channels */
													   0, /* no XML settings.. */
													   true  /* select default device on failure */));
    if (error.isNotEmpty())
    {
        AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                     ProjectInfo::projectName,
                                     "Couldn't open an output device!\n\n" + error);
    }
    else
    {
		audioSourcePlayer.setSource(&transport);
        
        // start the IO device pulling its data from our callback..
        audioDeviceManager.addAudioCallback (this);
    }
    
    // Sets format manager to be able to read wav aiff flac ogg and OS specific (aac m4a wmv) etc
    formatManager.registerBasicFormats();
    
	//audioMeterOutputL = audioMeterOutputR = sharedMeterOutputL = sharedMeterOutputR = 0.f;
    
    bufferingThread.startThread();
    
    //applyEQ.referTo(currentEqDetails.On);
    
    transport.addChangeListener(this);
    
    //audioDeviceManager.initialise (0, 2, nullptr, true);
 //   audioSourcePlayer.setSource (&bufferTransformAudioSource);
    audioDeviceManager.addAudioCallback (this);
    //audioDeviceManager.initialise (1, 2, nullptr, true);
    
    
    //audioFilePlayer.addListener(this);
    //audioFilePlayer.getAudioTransportSource()->addChangeListener (this);
    audioSourcePlayer.setGain(0.5);
}

MainAudioPlayer::~MainAudioPlayer ()
{
    audioSourcePlayer.setSource (nullptr);
    audioDeviceManager.removeAudioCallback (this);
    
    bufferingThread.stopThread(100);
    audioSourcePlayer.setSource (nullptr);
	transport.setSource(nullptr);//unload the current file
    transport.removeChangeListener(this);
    bufferingAudioSource = nullptr;
    audioDeviceManager.removeAudioCallback(this);
    
}


/*void MainAudioPlayer::fileChanged (AudioFilePlayer* player){};

void MainAudioPlayer::audioFilePlayerSettingChanged (AudioFilePlayer* player, int settingCode){};
 */

void MainAudioPlayer::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    audioSourcePlayer.audioDeviceIOCallback (inputChannelData,
                                             numInputChannels,
                                             outputChannelData,
                                             numOutputChannels,
                                             numSamples);

    /*if (fftDemo->isShowing())
     fftDemo->processBlock (outputChannelData[0], numSamples);
     
     meterL.copySamples (outputChannelData[0], numSamples);
     
     if (numOutputChannels > 1)
     meterR.copySamples (outputChannelData[1], numSamples);
	*/
}

void MainAudioPlayer::audioDeviceAboutToStart (AudioIODevice* device)
{
    audioSourcePlayer.audioDeviceAboutToStart (device);
    //fftDemo->setSampleRate (device->getCurrentSampleRate());
}

void MainAudioPlayer::audioDeviceStopped()
{
    audioSourcePlayer.audioDeviceStopped();
}

Song MainAudioPlayer::getCurrentSong()
{
    if(currentPlaylist->getCurrentPlayIndex() != -1){
        return currentPlaylist->getSong(currentPlaylist->getCurrentPlayIndex());
    }else{
        return EMPTY_SONG;
    }
    
}

void MainAudioPlayer::transportStoppedOrStarted (){
    if(!transport.isPlaying()){
		if(transport.hasStreamFinished())
        {
			sendActionMessage(Events::SONG_END);
            if(hasNextSong()){
                next();
            }else{
                stop();
            }
		}
        
	}
}

int MainAudioPlayer::getCurrentSongIndex()
{
    return currentPlaylist->getCurrentPlayIndex();
}

void MainAudioPlayer::stop (){
    if(transport.isPlaying()){
        transport.stop();
    }
    sendActionMessage(Events::STOP);
    currentPlaylist->setCurrentPlayIndex(-1);
    
}

void MainAudioPlayer::play (){
    if(currentPlaylist->getCurrentPlayIndex() == -1){
        if(currentPlaylist->size()>0){
            play(0);
        }
    }else{
        //audioFilePlayer.start();
        transport.start();
        sendActionMessage(Events::PLAY);
    }
    
}

bool MainAudioPlayer::hasNextSong(){
    
    return currentPlaylist->getCurrentPlayIndex() < (currentPlaylist->size()-1);
}

void MainAudioPlayer::play (int index){
    
    currentPlaylist->setCurrentPlayIndex(index);
    Song song = getCurrentSong();
    if(transport.isPlaying()){
         transport.stop();
    }
    File newFile (song.filePath);
    if (newFile.existsAsFile())
    {
        bool songStart = false;
        //audioFilePlayer.setFile(File(song.filePath));
        loadFile(song);
        Song _currentSong = song;
        _currentSong.length = transport.getLengthInSeconds();
        //transport.prepareToPlay
        transport.start();
        /*_currentSong.length = audioFilePlayer.getLengthInSeconds();
        audioFilePlayer.setLoopTimes(0, _currentSong.length);
		audioFilePlayer.setLoopBetweenTimes(false);
        *//*        if(audioFilePlayer.getCurrentPosition() == 0){
            songStart = true;
        }*/
        
        if(transport.getCurrentPosition() == 0){
            songStart = true;
        }
        transport.start();
        sendActionMessage(Events::PLAY);
        if(songStart){
            sendActionMessage(Events::SONG_START);
        }
        
    }
    
}




int MainAudioPlayer::loadFile (const Song song)
{
    
    File audioFile(song.filePath);
	//this is called when the user changes the filename in the file chooser box
	if(audioFile.existsAsFile())
	{
        //if (soundTouch != nullptr)
         //   soundTouchSettings = soundTouch->getPlaybackSettings();
        
        //transport.stop();
        //audioStream = nullptr;
        //audioStream = new FileInputStream(audioFile);
        
		AudioFormatReader* reader = formatManager.createReaderFor (audioFile);
		
		if (reader != nullptr)
		{
            
            // unload the previous file source and delete it..
            transport.stop();
            transport.setSource (nullptr);
            //soundTouch = nullptr;
            bufferingAudioSource = nullptr;
            
            //eqFilters.setSampleRate(reader->sampleRate);
			currentAudioFileSource = new AudioFormatReaderSource (reader, true);
            
			// ..and plug it into our effects sources
            bufferingAudioSource = new BufferingAudioSource (currentAudioFileSource, bufferingThread, false, song.sampleRate*2);
            //soundTouch = new SoundTouchAudioSource (bufferingAudioSource);
            //soundTouch->setPlaybackSettings(soundTouchSettings);
            
            transport.setSource (bufferingAudioSource);
            
            AudioDeviceManager::AudioDeviceSetup config;
            audioDeviceManager.getAudioDeviceSetup (config);
            
            
            
            if (song.sampleRate != 0){
                config.sampleRate = song.sampleRate;
            }
            Logger::outputDebugString (String (song.sampleRate));
            audioDeviceManager.setAudioDeviceSetup(config, true);
            
            
			//sendChangeMessage();
            
            //Loaded fine
            return 0 ;
		}
        else
        {
            //Reader failed
            //transport.start();
            return 2;
        }
	}
	else
	{
        //Not found
        return 1;
	}	    
}




void MainAudioPlayer::pause (){
    if(transport.isPlaying()){
        transport.stop();
        sendActionMessage(Events::PAUSE);
    }
}

void MainAudioPlayer::setPosition (const double newPosition){
    transport.setPosition(newPosition);
}

const double MainAudioPlayer::getTimeRemaining (){
    /*double timeRemaining = audioFilePlayer.getLengthInSeconds() - audioFilePlayer.getCurrentPosition();
    return timeRemaining;*/
    return transport.getLengthInSeconds() - transport.getCurrentPosition();
}

bool MainAudioPlayer::isPlaying(){
    return transport.isPlaying();
}

void MainAudioPlayer::next(){
    if(hasNextSong()){
        Song nextSong = currentPlaylist->getSong(currentPlaylist->getCurrentPlayIndex());
        if(nextSong.isCortina){
            fadeoutAndNext();
        }else{
            play(currentPlaylist->getCurrentPlayIndex() + 1);
        }
    }
}

void MainAudioPlayer::fadeoutAndNext(){
    generalGain = audioSourcePlayer.getGain();
    //to be configured in settings
    fadeoutSteps = 60;
    if(hasNextSong()){
        startTimer(100);
    }
}

void MainAudioPlayer::timerCallback(){
    if(audioSourcePlayer.getGain()  == 0){
        audioSourcePlayer.setGain(generalGain);
        if(hasNextSong()){
            play(currentPlaylist->getCurrentPlayIndex() + 1);
        }
        stopTimer();
    }else{
        double diff = (generalGain / fadeoutSteps);
        double newGain = audioSourcePlayer.getGain() - diff;
        
        if(newGain <= diff){
            newGain = 0;
        }
        audioSourcePlayer.setGain(newGain);
        if(newGain == 0){
            //change for settings
            usleep(500);
        }
        
    }
    sendActionMessage(Events::GAIN_CHANGE);
    
}

void MainAudioPlayer::setVolume(const double incomingVolume)
{
	audioSourcePlayer.setGain(incomingVolume);
}

double MainAudioPlayer::getVolume()
{
    return audioSourcePlayer.getGain();
}

void MainAudioPlayer::setCurrentPlaylist(Playlist* currentPlaylist_){
    currentPlaylist = currentPlaylist_;
}

void MainAudioPlayer::actionListenerCallback (const String& message){

    if(message.equalsIgnoreCase(Events::SONG_ADDED) || message.equalsIgnoreCase(Events::SONG_REMOVED)|| message.equalsIgnoreCase(Events::PLAYLIST_UPDATED)){
        sendActionMessage(Events::PLAYLIST_UPDATED);
        if(currentPlaylist->getCurrentPlayIndex() == -1){
            stop();
        }
    }
}

void MainAudioPlayer::changeListenerCallback (ChangeBroadcaster* source){
    if(source == &transport){
        transportStoppedOrStarted();
    }
}


void MainAudioPlayer::showAudioPreferences(Component* centerComponent)
{
    AudioDeviceSelectorComponent audioSettingsComp (audioDeviceManager,
                                                    0, 2, 2, 2,
                                                    true, true, true, true);
    audioSettingsComp.setSize (500, 250);
    DialogWindow::showModalDialog ("Audio Settings", &audioSettingsComp, nullptr, Colours::lightgrey, true);
    
}


