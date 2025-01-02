#pragma once

#include <JuceHeader.h>

class SoundWaveViewer : public juce::Component, public juce::ChangeListener
{
public:
    // Constructor and destructor
    SoundWaveViewer(juce::AudioFormatManager& formatManagerToUse, juce::AudioThumbnailCache& cacheToUse);
    ~SoundWaveViewer();

    // Load song URL into AudioThumbnail instance
    void loadURL(juce::URL audioURL);

    // Set the relative position of the playhead
    void setPositionRelative(double pos);

private:
    // Inherited from JUCE Component class
    void paint(juce::Graphics&) override;
    void resized() override;

    // Inherited from JUCE ChangeListener class
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    juce::AudioThumbnail audioThumb;
    bool fileLoaded;
    double position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundWaveViewer)
};