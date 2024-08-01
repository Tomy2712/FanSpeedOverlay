#define TESLA_INIT_IMPL

#include <tesla.hpp>

#include "fanSpeedOverlayGui.hpp"

class FanSpeedOverlay : public tsl::Overlay {
public:
                                             // libtesla already initialized fs, hid, pl, pmdmnt, hid:sys and set:sys
    virtual void initServices() override {}  // Called at the start to initialize all services necessary for this Overlay
    virtual void exitServices() override {}  // Called at the end to clean up all services previously initialized

    virtual void onShow() override {}    // Called before overlay wants to change from invisible to visible state
    virtual void onHide() override {}    // Called before overlay wants to change from visible to invisible state

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
        return initially<FanSpeedOverlayGui>();
    }
};

int main(int argc, char **argv) {
    return tsl::loop<FanSpeedOverlay>(argc, argv);
}