#include "JuceHeader.h"
#include "SoundWaveViewer.h"

using namespace juce;

//==============================================================================
SoundWaveViewer::SoundWaveViewer(AudioFormatManager& formatManagerToUse, AudioThumbnailCache& cacheToUse)
    : audioThumb(1000, formatManagerToUse, cacheToUse),
    fileLoaded(false),
    position(0)
{
    audioThumb.addChangeListener(this);
}

SoundWaveViewer::~SoundWaveViewer()
{
}

void SoundWaveViewer::paint(Graphics& g)
{
    g.fillAll(Colours::lightblue);
    g.setColour(Colours::blue.withAlpha(0.5f));
    g.drawRect(getLocalBounds().toFloat(), 2.0f);

    if (fileLoaded) {
        g.setColour(Colours::blue);
        audioThumb.drawChannel(g, getLocalBounds(), 0.0, audioThumb.getTotalLength(), 0.0, 1.0f);

        g.setColour(Colours::red);
        g.fillRect(position * getWidth(), 0, 2, getHeight());
    }
    else {
        g.setFont(Font(16.0f));
        g.setColour(Colours::black);
        g.drawText("Load a song from the playlist...", getLocalBounds(), Justification::centred, true);
    }
}

void SoundWaveViewer::resized()
{
}

void SoundWaveViewer::loadURL(URL audioURL)
{
    audioThumb.clear();
    fileLoaded = audioThumb.setSource(new URLInputSource(audioURL));
    if (fileLoaded) {
        repaint();
    }
    else {
        // Handle failure to load
    }
}

void SoundWaveViewer::changeListenerCallback(ChangeBroadcaster* source)
{
    repaint();
}

void SoundWaveViewer::setPositionRelative(double pos)
{
    if (pos != position) {
        position = pos;
        repaint();
    }
}
