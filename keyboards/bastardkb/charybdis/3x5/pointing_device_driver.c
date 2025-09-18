#include "pointing_device.h"
#include "drivers/sensors/cirque_pinnacle.h"
#include "print.h"

void pointing_device_init(void) {
    cirque_pinnacle_init();
    uprintf("Custom pointing_device_init: Cirque initialized\n");
}

report_mouse_t pointing_device_get_report(void) {
    report_mouse_t cirque_report = cirque_pinnacle_get_report();

    // Debug print for troubleshooting
    uprintf("Custom get_report: Cirque x=%d y=%d v=%d h=%d btn=%d\n",
            cirque_report.x, cirque_report.y, cirque_report.v, cirque_report.h, cirque_report.buttons);

    return cirque_report;
}
