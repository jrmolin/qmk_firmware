/* Copyright 2021 mo
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
#include "muse.h"

// Defines names for use in layer keycodes and the keymap
typedef enum _layer_names {
    _LETTER = 0,
    _BASIC,
    _TOMS,
    _LAYER_COUNT
} layer_names;

#define HI_HAT_CLOSED MI_D_4
#define HI_HAT_OPEN MI_C_4
#define HI_HAT_HALF_OPEN MI_Cs_4
#define HI_HAT_PEDAL MI_F_4
#define TOM_HI MI_C_3
#define TOM_MID MI_A_2
#define TOM_LOW MI_F_2
#define SNARE MI_D_2
#define KICK MI_C_2
#define RIDE MI_Ds_3
#define SPLASH MI_G_3
#define CRASH_RIGHT MI_A_3
#define CRASH_LEFT MI_Ds_3


// We need to include this after the custom keycode definitions
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LETTER] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E, KC_F
    ),
    /* Basic three-piece trap set (hi-hat, kick, snare) */
    [_BASIC] = LAYOUT(
        HI_HAT_CLOSED, HI_HAT_HALF_OPEN, HI_HAT_PEDAL, KICK, SNARE, CRASH_LEFT
    ),
    /* Basic three-piece trap set (hi-hat, kick, snare) */
    [_TOMS] = LAYOUT(
        TOM_HI,  TOM_MID,  TOM_LOW, SPLASH, RIDE, CRASH_RIGHT
    ),
};
// clang-format on

