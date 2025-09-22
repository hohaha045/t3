#include "drivers/sensors/cirque_pinnacle.h"
#include "pointing_device.h"
#include "print.h" // For debug output to QMK console

void pointing_device_driver_init(void) {
    // Initialize Cirque Pinnacle trackpad only
    cirque_pinnacle_init();
    uprintf("Trackpad only: Cirque Pinnacle initialized\n");
}

report_mouse_t pointing_device_driver_get_report(report_mouse_t* mouse_report) {
    // Get pointer report from the trackpad only
    report_mouse_t report = cirque_pinnacle_get_report();
    *mouse_report = report;
    return report;
}

void pointing_device_driver_task(void) {
    // If QMK expects a periodic task, call the trackpad task function
    cirque_pinnacle_task();
}
