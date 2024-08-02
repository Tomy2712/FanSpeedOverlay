#define TESLA_INIT_IMPL

#include "fanSpeedOverlayGui.hpp"


class FanSpeedOverlay : public tsl::Overlay {
    public:
        virtual void initServices() override {
            tsl::hlp::doWithSmSession([this]{
                if (R_SUCCEEDED(fanInitialize())) {
                    if (hosversionAtLeast(7,0,0))
                        fanCheck = fanOpenController(&fanCon, 0x3D000001);
                    else
                        fanCheck = fanOpenController(&fanCon, 1);
                }
            });

        }

        virtual void exitServices() override {
            fanControllerClose(&fanCon);
            fanExit();
        }

        virtual void onShow() override {}    // Called before overlay wants to change from invisible to visible state
        virtual void onHide() override {}    // Called before overlay wants to change from visible to invisible state

        virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
            return initially<FanSpeedOverlayGui>();
        }
};

int main(int argc, char **argv) {
    return tsl::loop<FanSpeedOverlay>(argc, argv);
}