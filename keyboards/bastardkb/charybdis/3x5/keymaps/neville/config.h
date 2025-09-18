/**
* Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

/* ---------------- VIA ---------------- */
#ifdef VIA_ENABLE
#    undef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif // VIA_ENABLE

/* ---------------- Tapping ---------------- */
#ifndef TAPPING_TERM
#    define TAPPING_TERM 200   // default tapping term
#endif  // TAPPING_TERM

#ifndef __arm__
#    define NO_ACTION_ONESHOT  // disable unused features on non-ARM
#endif

/* ---------------- Charybdis-specific ---------------- */
#ifdef POINTING_DEVICE_ENABLE
    #define POINTING_DEVICE_SCROLL_ENABLE
    #define POINTING_DEVICE_INVERT_V

    // Automatically enable pointer layer when moving the trackball.
    #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
    #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 200
    #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#endif // POINTING_DEVICE_ENABLE

/* ---------------- Combos ---------------- */
#define COMBO_COUNT 3
#define COMBO_TERM 120

/* ---------------- Layering ---------------- */
#define LAYER_STATE_8BIT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

#define HOLD_ON_OTHER_KEY_PRESS
//#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD

/* ---------------- RGB ---------------- */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

//#define CHARYBDIS_DRAGSCROLL_REVERSE_X
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

/* ==========================================================
   Pointing Device Configuration (Trackball + Touchpad)
   ========================================================== */
#ifdef POINTING_DEVICE_ENABLE
    #define POINTING_DEVICE_COMBINED   // merge PMW3360 + Cirque reports

    /* --- PMW3360 (SPI) --- */
    #define PMW3360_CS_PIN    B0
    #define PMW3360_SCLK_PIN  B1
    #define PMW3360_MOSI_PIN  B2
    #define PMW3360_MISO_PIN  B3

    /* --- Cirque Pinnacle (I2C) --- */
    #define CIRQUE_PINNACLE_ADDR 0x2A   // default I²C address
    #define I2C1_SCL_PIN D0
    #define I2C1_SDA_PIN D1
#endif
