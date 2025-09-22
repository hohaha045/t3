#include "drivers/sensors/cirque_pinnacle.h"
#include "pointing_device.h"
#include "print.h" // For debug output to QMK console

void pointing_device_driver_init(void) {
    // Initialize only the Cirque Pinnacle trackpad
    cirque_pinnacle_init();
    uprintf("Trackpad only: Cirque Pinnacle initialized\n");
}

report_mouse_t pointing_device_driver_get_report(report_mouse_t* mouse_report) {
    // Get pointer report ONLY from the trackpad
    report_mouse_t report = cirque_pinnacle_get_report();
    // Copy result to the mouse_report pointer if QMK expects it
    *mouse_report = report;
    return report;
}

void pointing_device_driver_task(void) {
    // If QMK version expects a periodic task, call the trackpad task
    cirque_pinnacle_task();
}
