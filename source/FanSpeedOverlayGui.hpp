#pragma once

#include <tesla.hpp>

class FanSpeedOverlayGui : public tsl::Gui {
    public:
        FanSpeedOverlayGui();
        //virtual ~FanSpeedOverlayGui();

        virtual tsl::elm::Element *createUI() final override;

        virtual void update() final override;

    private:
        tsl::elm::StepTrackBar *fanSpeedSlider;
        tsl::elm::ListItem *maxSpeedButton;
};