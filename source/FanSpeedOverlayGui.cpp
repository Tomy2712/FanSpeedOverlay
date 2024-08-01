#include "FanSpeedOverlayGui.hpp"

FanSpeedOverlayGui::FanSpeedOverlayGui() {}

tsl::elm::Element* FanSpeedOverlayGui::createUI() {
    // A OverlayFrame is the base element every overlay consists of. This will draw the default Title and Subtitle.
    // If you need more information in the header or want to change it's look, use a HeaderOverlayFrame.
    auto frame = new tsl::elm::OverlayFrame("FanSpeedOverlay", "v0.0.1");
    auto list = new tsl::elm::List();


    this->fanSpeedSlider =  new tsl::elm::StepTrackBar("\uE13C", 20);
    list->addItem(this->fanSpeedSlider);

    this->maxSpeedButton = new tsl::elm::ListItem("100\% Fan");
    this->maxSpeedButton->setClickListener([this](std::uint64_t keys) {
    if (keys & HidNpadButton_A) {
        if (this->maxSpeedButton->getValue() == "On") {
            this->maxSpeedButton->setValue("Off");
            return true;
        }
        this->maxSpeedButton->setValue("On");
        return true;
    }
    return false;
    });
    this->maxSpeedButton->setValue("Off");
    list->addItem(this->maxSpeedButton);

    // Add the list to the frame for it to be drawn
    frame->setContent(list);

    // Return the frame to have it become the top level element of this Gui
    return frame;
}

// Called once every frame to update values
void FanSpeedOverlayGui::update() {}