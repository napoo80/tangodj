/*
  ==============================================================================

    AudioManager.h
    Created: 22 Dec 2013 6:56:52pm
    Author:  Gaston

  ==============================================================================
*/

#ifndef MAINAUDIOPLAYER_H_INCLUDED
#define MAINAUDIOPLAYER_H_INCLUDED

#include "../../Common/Headers.h"
//#include "BufferTransformAudioSource.h"
#include "../Library/Song.h"
#include "../Playlist/Playlist.h"




class  MainAudioPlayer : public AudioIODeviceCallback,
                         public ActionBroadcaster,
                         public ActionListener,
                         public Timer,
                         public ChangeListener
{
public:
    //==============================================================================
    MainAudioPlayer();
    ~MainAudioPlayer();
    
    
    //AudioIODeviceCallback interface
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples);
    void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    virtual void actionListenerCallback (const String& message);
    virtual void changeListenerCallback (ChangeBroadcaster* source);
    void timerCallback();
    
    
    //==============================================================================
    /** Called when the player's file is changed.
     
     You can find out the new file using AudioFilePlayer::getFile().
     */
    /*void fileChanged (AudioFilePlayer* player);*/
    
    /** Called when the the player is stopped or started.
     You can find out if it is currently stopped with isPlaying().
     */
    /*void playerStoppedOrStarted (AudioFilePlayer* player);*/
    
    /** To avoid having to create a new listener interface for each subclass of AudioFilePlayer
     you can call this and send a SettingCode to your listeners to identify what sort of change occured
     e.g. playback rate, filter gain etc.
     */
    /*void audioFilePlayerSettingChanged (AudioFilePlayer* player, int settingCode);*/
    
    //AudioManager inferface
    //bool setSong(const Song location);
    void play();
    void play(int index);
    void stop();
    void pause();
    void next();
    void fadeoutAndNext();
    bool hasNextSong();
    void setCurrentPlaylist(Playlist* currentPlaylist_);
    int  loadFile (const Song song);
    //bool songReady();
    
    //Current song methods
    void setPosition(const double newPosition);
    const double getTimeRemaining();
    bool isPlaying();
    Song getCurrentSong();
    int getCurrentSongIndex();

    /** Sets the playback volume
     @param incomingVolume The volume between 0-1
     */
	void setVolume(const double incomingVolume);
    /** Returns the current playback volume
     @return The volume
     */
    double getVolume();
    
    void showAudioPreferences(Component* centerComponent);

    
    // Members
private:

    void transportStoppedOrStarted ();
    /** Audio Playing Helper members */
    AudioDeviceManager audioDeviceManager;
    AudioSourcePlayer audioSourcePlayer;
    AudioFormatManager formatManager;
    
    AudioTransportSource transport;
    TimeSliceThread bufferingThread;
    
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
    ScopedPointer<BufferingAudioSource> bufferingAudioSource;
    
    //AudioFilePlayerExt audioFilePlayer;
    //BufferTransformAudioSource bufferTransformAudioSource;
    Playlist* currentPlaylist;
    double generalGain;
    int fadeoutSteps;
    
    
    /*Configurations::BufferTransformAudioSource      bufferTransformAudioSource;*/
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAudioPlayer)
};

#endif  // MAINAUDIOPLAYER_H_INCLUDED
