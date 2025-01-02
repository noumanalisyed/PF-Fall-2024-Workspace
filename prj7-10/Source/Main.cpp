/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application and was created by PROJUCER automatically

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MajorComponent.h"

using namespace juce;

class TheDJisOPApplication : public JUCEApplication
{
public:
    TheDJisOPApplication() {}

    const String getApplicationName() override { return ProjectInfo::projectName; }
    const String getApplicationVersion() override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override { return true; }

    //==============================================================================
    void initialise(const String& commandLine) override
    {
        // Application initialization code
        mainWindow.reset(new MainWindow(getApplicationName()));
    }

    void shutdown() override
    {
        // Application shutdown code
        mainWindow = nullptr; // Deletes our window
    }
    //==============================================================================
    class AppConfiguration
    {
    public:
        const String getApplicationName() { return ProjectInfo::projectName; }
        const String getApplicationVersion() { return ProjectInfo::versionString; }
        bool moreThanOneInstanceAllowed() { return true; }
    };
    //==============================================================================
    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const String& commandLine) override
    {
        // Invoked when another instance of the app is launched while this one is running
    }

    //==============================================================================
    class MainWindow : public DocumentWindow
    {
    public:
        MainWindow(String name)
            : DocumentWindow(name,
                Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId),
                DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MajorComponent(), true);

#if JUCE_IOS || JUCE_ANDROID
            setFullScreen(true);
#else
            setResizable(true, true);
            centreWithSize(getWidth(), getHeight());
#endif

            setVisible(true);
        }

        void closeButtonPressed() override
        {
            // Called when the user tries to close this window
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION(TheDJisOPApplication)