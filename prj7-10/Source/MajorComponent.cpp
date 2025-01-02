/*
    File: MajorComponent.cpp
    Description: Implementation file for the MajorComponent class.
*/

#include "MajorComponent.h"

// Using the JUCE namespace for convenience
using namespace juce;

// Constructor
MajorComponent::MajorComponent()
{
    // Setting initial size
    setSize(1280, 720);

    // Checking and requesting audio recording permissions if necessary
    if (RuntimePermissions::isRequired(RuntimePermissions::recordAudio) && !RuntimePermissions::isGranted(RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request(RuntimePermissions::recordAudio, [&](bool granted) { if (granted)  setAudioChannels(2, 2); });
    }
    else
    {
        setAudioChannels(0, 2);
    }

    // Adding and making visible components
    addAndMakeVisible(playlistPanel);
    addAndMakeVisible(deckControl1);
    addAndMakeVisible(deckControl2);
    addAndMakeVisible(audioPlayer1);
    addAndMakeVisible(audioPlayer2);

    // Registering basic audio formats
    audioFormatMgr.registerBasicFormats();
}

// Destructor
MajorComponent::~MajorComponent()
{
    // Shutting down audio
    shutdownAudio();
}

// Prepares to play audio
void MajorComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // Prepare each player and mixer source
    audioPlayer1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    audioPlayer2.prepareToPlay(samplesPerBlockExpected, sampleRate);

    audioMixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);

    // Adding player sources to the mixer
    audioMixerSource.addInputSource(&audioPlayer1, false);
    audioMixerSource.addInputSource(&audioPlayer2, false);
}

// Gets the next audio block
void MajorComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    // Getting the next audio block from the mixer source
    audioMixerSource.getNextAudioBlock(bufferToFill);
}

// Releases audio resources
void MajorComponent::releaseResources()
{
    // Releasing resources of each player and mixer source
    audioPlayer1.releaseResources();
    audioPlayer2.releaseResources();
    audioMixerSource.releaseResources();
}

// Paints the component
void MajorComponent::paint(Graphics& g)
{
    // Fills the component with a dark blue color
    g.fillAll(Colours::darkblue);
}

// Resizes the components within the main component
void MajorComponent::resized()
{
    // Calculating dimensions for each component based on the window height
    int windowTenth = getHeight() / 10;
    playlistPanel.setBounds(0, 0, getWidth(), windowTenth * 5);
    audioPlayer1.setBounds(0, windowTenth * 5, getWidth() / 2, windowTenth * 2.25);
    audioPlayer2.setBounds(getWidth() / 2, windowTenth * 5, getWidth() / 2, windowTenth * 2.25);
    deckControl1.setBounds(0, windowTenth * 7.25, getWidth() / 2, windowTenth * 2.75);
    deckControl2.setBounds(getWidth() / 2, windowTenth * 7.25, getWidth() / 2, windowTenth * 2.75);
}