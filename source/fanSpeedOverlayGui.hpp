#pragma once

#include "utils.hpp"

class FanSpeedOverlayGui : public tsl::Gui {
    public:
        FanSpeedOverlayGui();


        virtual tsl::elm::Element *createUI() final override;

        virtual void update() final override;

    private:
        tsl::elm::CategoryHeader *speedSlideHeader;
        tsl::elm::StepTrackBar *fanSpeedSlider;
        tsl::elm::ListItem *maxSpeedButton;
        tsl::elm::ListItem *FanSpeedLabel;
};