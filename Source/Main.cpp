#include "Common/Headers.h"
#include "Gui/MainWindow.h"

class TangoDjApplication  : public JUCEApplication
{
public:
    TangoDjApplication()
    {
    }

    ~TangoDjApplication()
    {
    }

    void initialise (const String& /*commandLine*/)
    {
#if JUCE_DEBUG && DROWAUDIO_UNIT_TESTS
        UnitTestRunner testRunner;
        testRunner.runAllTests();
#endif
        
        /*ScopedPointer<SplashScreen> splash = new SplashScreen ("Tango DJ",
                                                              ImageCache::getFromMemory (BinaryData::splash_screen_png, BinaryData::splash_screen_pngSize),
                                                              #if JUCE_MAC
                                                               true);
                                                              #else
                                                               false);
                                                              #endif*/
        
        mainWindow = new MainAppWindow();
    }

    void shutdown()
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit()
    {
        quit();
    }
    
    const String getApplicationName()
    {
        return "Tango DJ";
    }

    const String getApplicationVersion()
    {
        return ProjectInfo::versionString;
    }

    bool moreThanOneInstanceAllowed()
    {
        return false;
    }

    void anotherInstanceStarted (const String& /*commandLine*/)
    {
        
    }

private:
    ScopedPointer <MainAppWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that starts the app.
START_JUCE_APPLICATION(TangoDjApplication)