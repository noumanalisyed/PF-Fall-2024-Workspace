#pragma once

#include "JuceHeader.h"
#include "AudioBox.h"
#include "SoundWaveViewer.h"

class DeckControl : public juce::Component,
                public juce::Button::Listener,
                public juce::Slider::Listener,
                public juce::Timer
{
public:
    DeckControl(AudioBox* player,
            juce::AudioFormatManager& formatManagerToUse,
            juce::AudioThumbnailCache& cacheToUse,
            std::vector<juce::URL>* trackFilesUrl,
            std::vector<std::string>* trackTitles,
            int _guiIdentifier);
    ~DeckControl();

private:
    void buttonClicked(juce::Button* button) override;
    void sliderValueChanged(juce::Slider* slider) override;
    void timerCallback() override;
    void paint(juce::Graphics& g) override;
    void resized() override;

    AudioBox* player;

    int guiIdentifier;

    juce::Label playbackSpeedLabel;
    juce::Label volumeLabel;
    juce::Label positionLabel;
    juce::Label goBackOrGoForward5SecondsLabel;

    juce::TextButton loadButton{ "LOAD" };
    juce::ArrowButton goBack5secondsButton{ "GO BACK 5 SECONDS", 0.5, juce::Colours::red };
    juce::ArrowButton goForward5SecondsButton{ "JUMP 5 SECONDS", 0, juce::Colours::red };
    juce::TextButton playButton{ "PLAY" };
    juce::TextButton stopButton{ "STOP" };
    juce::TextButton playFromBeginningButton{ "START OVER" };
    juce::TextButton loopSongButton{ "LOOP DISABLED" };

    bool loopEnabled;
    bool isPlaying;
    juce::Slider volumeSlider;
    juce::Slider playbackSpeedSlider;
    juce::Slider positionSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckControl)
};