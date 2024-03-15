/*
  ==============================================================================

    ReverbComponent.h
    Created: 15 Mar 2024 3:26:02pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MyLookAndFeel.h"

//==============================================================================
/*
*/
class ReverbComponent  : public juce::Component
{
public:
    ReverbComponent()
    {
        createKnob(dtSlider, 0.1, 0.1, 60, 0.01);
        createKnob(dampSlider, 0, 0, 1, 0.01);
        createKnob(sizeSlider, 1, 0.5, 3, 0.01);
        createKnob(earlyDiffSlider, 0.5, 0, 1, 0.01);
        createKnob(feedbackSlider, 0.5, 0, 1, 0.01);
        createKnob(modDepthSlider, 0.0, 0.0, 1, 0.01);
        createKnob(modFreqSlider, 1, 0, 10, 0.01);
        createKnob(dryWetMixSlider, 0.5, 0, 1, 0.01);
    }

    ~ReverbComponent() override
    {
        dtSlider.setLookAndFeel(nullptr);
        dampSlider.setLookAndFeel(nullptr);
        sizeSlider.setLookAndFeel(nullptr);
        earlyDiffSlider.setLookAndFeel(nullptr);
        feedbackSlider.setLookAndFeel(nullptr);
        modDepthSlider.setLookAndFeel(nullptr);
        modFreqSlider.setLookAndFeel(nullptr);
        dryWetMixSlider.setLookAndFeel(nullptr);
    }

    void paint (juce::Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

        //g.setColour (juce::Colours::grey);
        //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    }

    void resized() override
    {
        dtSlider.setBounds(0, 0, 100, 100);
        dampSlider.setBounds(125, 0, 100, 100);
        sizeSlider.setBounds(250, 0, 100, 100);
        earlyDiffSlider.setBounds(375, 0, 100, 100);
        feedbackSlider.setBounds(0, 125, 100, 100);
        modDepthSlider.setBounds(125, 125, 100, 100);
        modFreqSlider.setBounds(250, 125, 100, 100);
        dryWetMixSlider.setBounds(375, 125, 100, 100);
    }

    void createKnob(juce::Slider& slider, double initialValue, double minRange, double maxRange, double increment) {
        addAndMakeVisible(slider);
        slider.setLookAndFeel(&myLookAndFeel);
        slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        slider.setRange(minRange, maxRange, increment);
        slider.setValue(initialValue);
        slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 20);
        slider.setNumDecimalPlacesToDisplay(2);
    }

    juce::Slider dtSlider;
    juce::Slider dampSlider;
    juce::Slider sizeSlider;
    juce::Slider earlyDiffSlider;
    juce::Slider feedbackSlider;
    juce::Slider modDepthSlider;
    juce::Slider modFreqSlider;
    juce::Slider dryWetMixSlider;

private:
    MyLookAndFeel myLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)
};