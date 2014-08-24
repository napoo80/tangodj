
#ifndef __TANGODJ_TOPPANEL_H__
#define __TANGODJ_TOPPANEL_H__

// Juce related definitions go here
#include "../../Common/Headers.h"
#include "../../Core/Audio/MainAudioPlayer.h"
#include "../../Core/Manager/CoreManager.h"
#include "../Widgets/ControlsComponent.h"
#include "../Widgets/PlayInfoComponent.h"
#include "../Widgets/PlayListComponent.h"
#include "../Widgets/ActionBarComponent.h"

class PlaylistPanel : public Component
    {
        // Members
    private:
        ScopedPointer<CoreManager> coreManager;
        ScopedPointer<PlayInfoComponent> playInfoComponent;
        ScopedPointer<ControlsComponent> controlsComponent;
        ScopedPointer<PlayListComponent> playListComponent;
        ScopedPointer<ActionBarComponent> actionBarComponent;
        // Methods
    public:
        // Component interface
        /** This resize and set components on screen */
        void resized ();
        /** This paints graphical components */
        void paint (Graphics & g);
        /** Get controlBar component */    
        ControlsComponent * getControlsComponent();

        // Constructor & Destructor
    public:
        /** Constructor 
            @param[in-out] audioDeviceManager   Device manager holding audio device on which music is being played
            @param[in-out] audioFilePlayer      Audio Player's actual implementation which do play files */
        PlaylistPanel (CoreManager* coreManager_);
        /** Destructor */
        ~PlaylistPanel ();
        // (prevent copy constructor and operator= being generated..)
    private:
        PlaylistPanel (const PlaylistPanel&);
        const PlaylistPanel& operator= (const PlaylistPanel&);
    };
#endif //__TANGODJ_TOPPANEL_H__