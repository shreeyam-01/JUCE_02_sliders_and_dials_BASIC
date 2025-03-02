#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    dial1.setSliderStyle(juce::Slider::SliderStyle::Rotary); 
    dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 40);

    dial2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 40);

    dial3.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    dial3.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);

    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);
    addAndMakeVisible(dial3);

    setSize (200, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::blueviolet);
}

void MainComponent::resized()
{
    juce::Rectangle<int> area = getLocalBounds();
    juce::Rectangle<int> dialArea = area.removeFromTop(area.getHeight() / 2);


    dial1.setBounds(dialArea.removeFromLeft(area.getWidth()/2));
    dial2.setBounds(dialArea.removeFromRight(area.getWidth() / 2));
    dial3.setBounds(area);
}
