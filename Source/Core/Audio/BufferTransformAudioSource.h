#ifndef __TANGODJ_BUFFERTRANSFORMAUDIOSOURCE_H__
#define __TANGODJ_BUFFERTRANSFORMAUDIOSOURCE_H__

#include "../../Common/Headers.h"

//==============================================================================
class BufferTransformAudioSource :  public AudioSource
{
public:
    //==============================================================================
    BufferTransformAudioSource (AudioSource* source,
                                bool deleteSourceWhenDeleted = false);
    
    /** Destructor. */
    ~BufferTransformAudioSource();
    
    /** Setting this to true does not apply the buffer. */
    void setBypass (bool shouldBypass);
    
    /** Returns all of the settings.
     */
    Buffer& getBuffer()     {   return buffer;    }

    /** @internal. */
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    
    /** @internal. */
    void releaseResources();
    
    /** @internal. */
    void getNextAudioBlock (const AudioSourceChannelInfo& info);
        
private:
    OptionalScopedPointer<AudioSource> source;
    Buffer buffer;
    bool isBypassed;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BufferTransformAudioSource);
};

#endif //__TANGODJ_BUFFERTRANSFORMAUDIOSOURCE_H__