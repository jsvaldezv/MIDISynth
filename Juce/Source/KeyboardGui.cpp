/*
  ==============================================================================

    KeyboardGui.cpp
    Created: 29 May 2022 8:01:14pm
    Author:  ximec

  ==============================================================================
*/

#include <JuceHeader.h>
#include "KeyboardGui.h"

//==============================================================================
KeyboardGui::KeyboardGui(MidiSynthAudioProcessor& p): keyboardComponent (keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard), audioProcessor (p)
{
    addAndMakeVisible (keyboardComponent);
    startTimer(400);
}

KeyboardGui::~KeyboardGui(){}

void KeyboardGui::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::red);
}

void KeyboardGui::resized()
{
    keyboardComponent.setBoundsRelative(0.0f, 0.0f, 1.0f, 1.0f);
}

void KeyboardGui::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}