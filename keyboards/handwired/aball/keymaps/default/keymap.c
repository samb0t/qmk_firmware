/* Copyright 2020 Richard Sutherland
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
#include "print.h"
//enum custom_keycodes {
//    DRAG_SCROLL = SAFE_RANGE,
//};
//
//bool set_scrolling = true;//start with false
//
//// Modify these values to adjust the scrolling speed
//#define SCROLL_DIVISOR_H 8.0
//#define SCROLL_DIVISOR_V 8.0
//
//// Variables to store accumulated scroll values
//float scroll_accumulated_h = 0;
//float scroll_accumulated_v = 0;
//
//// Function to handle mouse reports and perform drag scrolling
//report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//    // Check if drag scrolling is active
//    if (set_scrolling && host_keyboard_led_state().caps_lock) {
//        // Calculate and accumulate scroll values based on mouse movement and divisors
//        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
//        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;
//
//        // Assign integer parts of accumulated scroll values to the mouse report
//        mouse_report.h = (int8_t)scroll_accumulated_h;
//        mouse_report.v = (int8_t)scroll_accumulated_v;
//
//        // Update accumulated scroll values by subtracting the integer parts
//        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
//        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
//
//        // Clear the X and Y values of the mouse report
//        mouse_report.x = 0;
//        mouse_report.y = 0;
//    }
//    return mouse_report;
//}
//
//// Function to handle key events and enable/disable drag scrolling
//// see: https://www.reddit.com/r/ploopy/comments/nlvgkq/how_to_scroll_with_the_trackball_nano/
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case DRAG_SCROLL:
//            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
//            set_scrolling = record->event.pressed;
//            break;
//        default:
//            break;
//    }
//
//    set_scrolling = true; //remove this and replace with numlock
//    return true;
//}
//
//// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
//layer_state_t layer_state_set_user(layer_state_t state) {
//    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
//    return state;
//}

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(5000);
    pointing_device_init_user();
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  debug_mouse=true;
  print("string");
}
