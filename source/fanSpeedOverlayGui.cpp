#include "fanSpeedOverlayGui.hpp"

FanSpeedOverlayGui::FanSpeedOverlayGui() {}

tsl::elm::Element* FanSpeedOverlayGui::createUI() {
    // A OverlayFrame is the base element every overlay consists of. This will draw the default Title and Subtitle.
    // If you need more information in the header or want to change it's look, use a HeaderOverlayFrame.
    auto frame = new tsl::elm::OverlayFrame("FanSpeedOverlay", "v0.1.0");
    auto list = new tsl::elm::List();

    this->speedSlideHeader = new tsl::elm::CategoryHeader("");
    list->addItem(this->speedSlideHeader);

    this->fanSpeedSlider =  new tsl::elm::StepTrackBar("", 20);
    this->fanSpeedSlider->setProgress(2);
    this->fanSpeedSlider->setValueChangedListener([this](std::uint8_t val) {
        fanSpeedSelected = val*5/100.f;
    });
    list->addItem(this->fanSpeedSlider);

    this->maxSpeedButton = new tsl::elm::ListItem("Applied Speed");
    this->maxSpeedButton->setClickListener([this](std::uint64_t keys) {
        if (R_SUCCEEDED(fanCheck)) {
            if (keys & HidNpadButton_A) {
                if (this->maxSpeedButton->getValue() == "On") {
                    this->maxSpeedButton->setValue("Off");
                    return true;
                }
                this->maxSpeedButton->setValue("On");
                return true;
            }
        }
        return false;
    });

    this->maxSpeedButton->setValue("Off");
    list->addItem(this->maxSpeedButton);
    this->FanSpeedLabel = new tsl::elm::ListItem("Fan Speed:");
    list->addItem(this->FanSpeedLabel);

    // Add the list to the frame for it to be drawn
    frame->setContent(list);

    // Return the frame to have it become the top level element of this Gui
    return frame;
}

// Called once every frame to update values
void FanSpeedOverlayGui::update() {
    float fanSpeed = 0;
    this->speedSlideHeader->setText(std::format("Speed: {:.2f}%", fanSpeedSelected*100));
    if (R_SUCCEEDED(fanCheck)) {
        if (this->maxSpeedButton->getValue() == "On") 
            fanControllerSetRotationSpeedLevel(&fanCon, fanSpeedSelected);

        fanControllerGetRotationSpeedLevel(&fanCon, &fanSpeed);
    }
    this->FanSpeedLabel->setValue(std::format("{:.2f}%", fanSpeed*100), true);

}