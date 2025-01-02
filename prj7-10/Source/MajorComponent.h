#pragma once

#include "JuceHeader.h"
#include "AudioBox.h"
#include "DeckControl.h"
#include "PlaylistPanel.h"

using namespace juce;

class MajorComponent : public AudioAppComponent
{
public:
    // Constructor
    MajorComponent();

    // Destructor
    ~MajorComponent();

    //==============================================================================
    // AudioAppComponent overrides
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    // Graphics overrides
    void paint(Graphics& g) override;
    void resized() override;

private:
    // Data members
    std::vector<std::string> songTitles;
    std::vector<URL> audioFileUrl;
    AudioFormatManager audioFormatMgr;
    AudioThumbnailCache audioThumbCache{ 100 };
    PlaylistPanel playlistPanel{ &audioPlayer1, &audioPlayer2, audioFormatMgr, audioThumbCache };
    AudioBox audioPlayer1{ audioFormatMgr, &audioFileUrl, &songTitles };
    AudioBox audioPlayer2{ audioFormatMgr ,&audioFileUrl, &songTitles };
    DeckControl deckControl1{ &audioPlayer1, audioFormatMgr, audioThumbCache, &audioFileUrl, &songTitles, 1 };
    DeckControl deckControl2{ &audioPlayer1, audioFormatMgr, audioThumbCache, &audioFileUrl, &songTitles, 2 };
    MixerAudioSource audioMixerSource;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MajorComponent)
};