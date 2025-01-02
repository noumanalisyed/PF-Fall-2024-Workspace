#include "AudioFlow.h"
using namespace juce;

AudioFlow::AudioFlow() : AudioVisualiserComponent(2){
    setBufferSize(1024);
    setSamplesPerBlock(16);
    setColours(Colours::dodgerblue, Colours::dodgerblue);
}