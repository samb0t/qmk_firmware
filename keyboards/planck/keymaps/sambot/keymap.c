/* Copyright 2015-2017 Jack Humbert
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

#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _NPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  FUNCTION,
  NPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctl  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Raise| Alt  | Win  |Raise |Click |Space |Lower | NPAD | esc  |  Ms2 | Ms1  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB           , KC_Q  , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC} ,
  {MT(MOD_LCTL,KC_ESC) , KC_A  , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT} ,
  {KC_LSFT          , KC_Z  , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT } ,
  {FUNCTION         , RAISE , KC_LALT , KC_LGUI , RAISE , KC_BTN1, KC_SPC , LOWER , NPAD    , KC_ESC  , KC_BTN2 , KC_BTN1}
}           ,

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL },
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_HOME,    KC_PGUP, KC_PGDN, KC_END}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  | SRLU |  MS2 |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  | SRLD |  MS3 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {_______, KC_F1,   KC_F2,   KC_WH_U, KC_BTN2, KC_CAPS, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_WH_D, KC_BTN3, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______,  _______,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______,  _______,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______,  _______},
  {KC_CAPS, _______,  _______,  MU_ON,   MU_OFF,  _______,   _______,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | Prev | Play | Next |      |      |Pg Up | Home |Pg Dn |Prt Sc| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Mute | Vol+ |      | Left | Down |  Up  |Right | End  | Ent  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |BkLght|      |      |      |      |      | End  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Esc  |             | Esc  | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {KC_ESC , _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_PGUP, KC_HOME, KC_PGDN, KC_PSCR, KC_DEL},
  {_______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , KC_ENT},
  {_______, _______, BACKLIT, _______, _______, _______, _______, _______, KC_END , _______, _______, _______},
  {_______, _______, _______, _______, KC_ESC , _______, _______, KC_ESC , KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Number Pad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  7   |  8   |  9   |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  4   |  5   |  6   |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  1   |  2   |  3   |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |  0   |  .   |  /   |
 * `-----------------------------------------------------------------------------------'
 */
[_NPAD] = {
  {_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_7    , KC_8 , KC_9   , KC_PLUS} ,
  {_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_4    , KC_5 , KC_6   , KC_MINS} ,
  {_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_1    , KC_2 , KC_3   , KC_ASTR} ,
  {_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0 , KC_DOT , KC_SLSH}
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;
    case NPAD:
      if (record->event.pressed) {
        layer_on(_NPAD);
      } else {
        layer_off(_NPAD);
      }
      return false;
      break;
  }
  return true;
}
