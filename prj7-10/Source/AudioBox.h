#pragma once

#include "JuceHeader.h"
#include "AudioFlow.h"

using namespace juce;

class AudioBox : public AudioSource, public Component {
public:
    AudioBox(AudioFormatManager& _formatManager, std::vector<URL>* trackFilesUrl, std::vector<std::string>* trackTitles);
    ~AudioBox();

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void loadURL(URL audioURL);
    void setGain(double gain);
    void setSpeed(double ratio);
    void setPosition(double posInSecs);
    void setPositionRelative(double pos);
    double getLengthInSeconds();
    void start();
    void stop();
    double getPositionRelative();

private:
    void paint(Graphics&) override;
    void resized() override;

    AudioFormatManager& formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    AudioTransportSource reverseTransportSource;
    ResamplingAudioSource resampleSource{ &transportSource, false, 2 };
    ResamplingAudioSource reverseResampleSource{ &reverseTransportSource, false, 2 };

    AudioFlow customVisualizer;

    std::atomic<float> magnitude{ 0.0f };
    double currentVolume;
};