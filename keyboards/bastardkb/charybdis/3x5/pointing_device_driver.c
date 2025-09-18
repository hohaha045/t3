#include "pointing_device.h"
#include "drivers/sensors/pmw3360.h"
#include "drivers/sensors/cirque_pinnacle.h"
#include "print.h"

// Called once at startup
void pointing_device_init(void) {
    pmw3360_init();
    cirque_pinnacle_init();
    uprintf("Custom pointing_device_init: PMW3360 and Cirque initialized\n");
}

// Called every matrix scan, must return the combined report
report_mouse_t pointing_device_get_report(void) {
    report_mouse_t pmw_report = pmw3360_get_report();
    report_mouse_t cirque_report = cirque_pinnacle_get_report();

    // Merge both reports
    report_mouse_t combined = {0};

    combined.x = pmw_report.x + cirque_report.x;
    combined.y = pmw_report.y + cirque_report.y;
    combined.v = pmw_report.v + cirque_report.v;
    combined.h = pmw_report.h + cirque_report.h;

    combined.buttons = pmw_report.buttons | cirque_report.buttons;

    // Useful for debugging!
    uprintf("Custom get_report: PMW x=%d y=%d Cirque x=%d y=%d Result x=%d y=%d\n",
            pmw_report.x, pmw_report.y, cirque_report.x, cirque_report.y, combined.x, combined.y);

    return combined;
}
