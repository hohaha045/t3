#include "pointing_device.h"
#include "print.h"

void pointing_device_init(void) {
    uprintf("Custom pointing_device_init called\n");
}

report_mouse_t pointing_device_get_report(void) {
    report_mouse_t mouse_report = {0};
    mouse_report.x = 0;
    mouse_report.y = 0;
    uprintf("Custom pointing_device_get_report called\n");
    return mouse_report;
}
