/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
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
#include QMK_KEYBOARD_H

#define SCROLL_DIVISOR_H 50.0
#define SCROLL_DIVISOR_V 50.0

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;


//start wiggle
bool set_scrolling = false;

unsigned long time;


bool PloopyAcceleration = false;
bool PloopyNumlockScroll = false;
int16_t PloopyNumlockScrollVDir = 1;

int scrollX=0;
int scrollY=0;

int countShake=0;
bool lastDir=false;
int lastShake=0;
int lastShakeSwitch=0;
//end wiggle

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // wiggle ball detection
    if(timer_read()-lastShakeSwitch>250)
    {

        if(timer_read()-lastShake>150)countShake=0;

        if(mouse_report.x> 1 && mouse_report.y<3 && !lastDir)
        {
            countShake++;
            lastShake=timer_read();
            lastDir=!lastDir;
        }
        if(mouse_report.x<-1 && mouse_report.y<3 && lastDir)
        {
            countShake++;
            lastShake=timer_read();
            lastDir=!lastDir;
        }

        if(countShake>3)
        {
            set_scrolling=!set_scrolling;
            countShake=0;
            lastShake=timer_read();
            lastShakeSwitch=timer_read();
        }
    }

    bool doScroll = set_scrolling || host_keyboard_led_state().caps_lock|| host_keyboard_led_state().num_lock;
    //https://docs.qmk.fm/features/pointing_device
    // Check if drag scrolling is active
    if (doScroll) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

void suspend_power_down_user(void) {
    // Switch off sensor + LED making trackball unable to wake host
    adns5050_power_down();
}

void suspend_wakeup_init_user(void) {
    adns5050_init();
}
