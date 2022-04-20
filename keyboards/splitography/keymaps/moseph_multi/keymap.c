/* Copyright 2021 Alexis Jeandeau
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
#include "keymap_steno.h"

enum keyboard_layers {
    _QWERTY = 0,
    _TXBOLT,
    _PLOVER,
    _BLUE,
    _ORANGE,
    _GREEN,
    _NUM,
    _END_LAYERS,
};

enum keyboard_keycodes {
    QWERTY = SAFE_RANGE,
    BASE,
    BASE1,
    BASE2,
    TXBOLT,
    PLOVER,
    BLUE,
    ORANGE,
};

#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define TG_NUM TG(_NUM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ...................................................................... Qwerty
    //
    // http://www.keyboard-layout-editor.com/#/gists/1b04ce6be0cee6e5d2998b2a8efb8b09

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │  Esc │   Q  │   W  │   E  │   R  │   T  ││   Y  │   U  │   I  │   O  │   P  │ Bksp │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Ctrl │   A  │   S  │   D  │   F  │   G  ││   H  │   J  │   K  │   L  │   ;  │ Enter│
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Shift│   Z  │   X  │   C  │   V  │   B  ││   N  │   M  │   ,  │   .  │   /  │  GUI │
    // └──────┴──────┴──────┴──────┼──────┼──────┼┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │Orange│ Blue ││ Space│  Alt │
    //                             └──────┴──────┴┴──────┴──────┘

    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
                                            ORANGE,  BLUE,    KC_SPC,  KC_LALT
    ),

    // .................................................................. Blue Layer
    //
    // http://www.keyboard-layout-editor.com/#/gists/054b8bc0e31971bb962ea1c781232e0b

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │   `  │   1  │   2  │   3  │   4  │   5  ││   6  │   7  │   8  │   9  │   0  │      │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Ctrl │ Stop │ Prev │ Play │ Next │ +Vol ││   '  │   [  │   ]  │   [  │   ]  │   '  │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Shift│ Undo │  Cut │ Copy │ Paste│ -Vol ││ Mute │      │      │   -  │   =  │  GUI │
    // └──────┴──────┴──────┴──────┼──────┼──────┼┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │Orange│  f() ││  Del │  Alt │
    //                             └──────┴──────┴┴──────┴──────┘

    [_BLUE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_LCTL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, KC_QUOT, KC_LBRC, KC_RBRC, KC_LBRC, KC_RBRC, KC_QUOT,
        KC_LSFT, UNDO,    CUT,     COPY,    PASTE,   KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LGUI,
                                            ORANGE,  _______, KC_DEL,  KC_LALT
    ),

    // ................................................................ Orange Layer
    //
    // http://www.keyboard-layout-editor.com/#/gists/83ccc7c3faa78b1f67f6fef65063a248

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │Plover│  F1  │  F2  │  F3  │  F4  │      ││  App │   7  │   8  │   9  │      │      │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Ctrl │  F5  │  F6  │  F7  │  F8  │      ││      │   4  │   5  │   6  │      │      │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Shift│  F9  │  F10 │  F11 │  F12 │      ││   0  │   1  │   2  │   3  │   \  │  GUI │
    // └──────┴──────┴──────┴──────┼──────┼──────┼┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │  f() │ Blue ││  Tab │  Alt │
    //                             └──────┴──────┴┴──────┴──────┘

    [_ORANGE] = LAYOUT(
        PLOVER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_APP,  KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
        KC_LCTL, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, LCTL(KC_ENTER),
        KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSLS, KC_LGUI,
                                            _______, BLUE,    KC_TAB,  KC_LALT
    ),

    // ................................................................. Green Layer
    //
    // http://www.keyboard-layout-editor.com/#/gists/bc7902f1eada4d7d34d3445aa1eccdab

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │TxBolt│      │      │      │      │Scroll││   /  │   7  │   8  │   9  │   -  │      │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Ctrl │ Home │  Up  │  End │ PgUp │ Caps ││   *  │   4  │   5  │   6  │   +  │ Enter│
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Shift│ Left │ Down │ Right│ PgDn │  Num ││   0  │   1  │   2  │   3  │      │  GUI │
    // └──────┴──────┴──────┴──────┼──────┼──────┼┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │  f() │  f() ││  --  │  Alt │
    //                             └──────┴──────┴┴──────┴──────┘

    [_GREEN] = LAYOUT(
        TXBOLT,  QWERTY,  _______, _______, _______, KC_SLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______,
        KC_LCTL, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_CAPS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_ENT ,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, TG_NUM,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, KC_LGUI,
                                            _______, _______, XXXXXXX, KC_LALT
    ),

    // ................................................................... Num Layer
    //
    // http://www.keyboard-layout-editor.com/#/gists/bc7902f1eada4d7d34d3445aa1eccdab

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │      │      │      │      │      │      ││   /  │   7  │   8  │   9  │   -  │      │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Ctrl │ Home │  Up  │  End │ PgUp │      ││   *  │   4  │   5  │   6  │   +  │ Enter│
    // ├──────┼──────┼──────┼──────┼──────┼──────┼┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Shift│ Left │ Down │ Right│ PgDn │  f() ││   0  │   1  │   2  │   3  │      │  GUI │
    // └──────┴──────┴──────┴──────┼──────┼──────┼┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │  --  │  --  ││  --  │  Alt │
    //                             └──────┴──────┴┴──────┴──────┘

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        KC_LCTL, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_ENT ,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  BASE,   KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, KC_LGUI,
                                            XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT
    ),

    // ...................................................................... Plover
    //
    // http://www.keyboard-layout-editor.com/#/gists/27b8f8649393a8ba4071ba946a9306f4

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │   1  │   1  │   1  │   1  │   1  │   1  │   1  │   1  │   1  │   1  │   1  │   1  │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Base │   S  │   T  │   P  │   H  │   *  │   *  │   F  │   P  │   L  │   T  │   D  │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Base │   S  │   K  │   W  │   R  │   *  │   *  │   R  │   B  │   G  │   S  │   Z  │
    // └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │   A  │   O  │   E  │   U  │
    //                             └──────┴──────┴──────┴──────┘

    [_PLOVER] = LAYOUT(
        KC_1,  KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
        BASE1, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        BASE2, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                                          KC_C,    KC_V,    KC_N,    KC_M
    ),

    // ...................................................................... TxBolt
    //
    // http://www.keyboard-layout-editor.com/#/gists/27b8f8649393a8ba4071ba946a9306f4

    // ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
    // │   #  │   #  │   #  │   #  │   #  │   #  │   #  │   #  │   #  │   #  │   #  │   #  │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Base │   S  │   T  │   P  │   H  │   *  │   *  │   F  │   P  │   L  │   T  │   D  │
    // ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
    // │ Base │   S  │   K  │   W  │   R  │   *  │   *  │   R  │   B  │   G  │   S  │   Z  │
    // └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
    //                             │   A  │   O  │   E  │   U  │
    //                             └──────┴──────┴──────┴──────┘

    [_TXBOLT] = LAYOUT(
        STN_N1, STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC ,
        BASE1,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
        BASE2,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
                                           STN_A,   STN_O,   STN_E,   STN_U
    ),
};
// clang-format on

// ..................................................................... Keymaps

#define BASE_1 1
#define BASE_2 2
#define BASE_12 3
static uint8_t base_n = 0;

void (*base_layer)(void) = NULL;

void qwerty(void) {
    base_layer = qwerty;
    base_n     = 0;
    layer_move(0);
    set_single_persistent_default_layer(_QWERTY);
}

void plover(keyrecord_t *record) {
    if (record->event.pressed) {
        layer_move(0);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw  = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
    }
}

void txbolt(void) {
    layer_move(0);
    layer_on(_TXBOLT);
}

// ........................................................... User Keycode Trap

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                qwerty();
            }
            return false;
        case KC_QUOT:
            if ((biton32(layer_state) != _BLUE)) {
                break;
            }
            if (record->event.pressed) {
                register_code(KC_SLSH);
            } else {
                unregister_code(KC_SLSH);
            }
            return false;
        case BASE:
            if (record->event.pressed) {
                base_layer();
            }
            return false;
        case BASE1:
            if (record->event.pressed) {
                base_n = base_n | BASE_1;
                if (base_n == BASE_12) {
                    base_layer();
                }
            } else {
                base_n = base_n & ~BASE_1;
            }
            return false;
        case BASE2:
            if (record->event.pressed) {
                base_n = base_n | BASE_2;
                if (base_n == BASE_12) {
                    base_layer();
                }
            } else {
                base_n = base_n & ~BASE_2;
            }
            return false;
        case BLUE:
            if (record->event.pressed) {
                layer_on(_BLUE);
                update_tri_layer(_BLUE, _ORANGE, _GREEN);
            } else {
                layer_off(_BLUE);
                update_tri_layer(_BLUE, _ORANGE, _GREEN);
            }
            return false;
        case ORANGE:
            if (record->event.pressed) {
                layer_on(_ORANGE);
                update_tri_layer(_BLUE, _ORANGE, _GREEN);
            } else {
                layer_off(_ORANGE);
                update_tri_layer(_BLUE, _ORANGE, _GREEN);
            }
            return false;
        case PLOVER:
            plover(record);
            return false;
        case TXBOLT:
            if (record->event.pressed) {
                txbolt();
            }
            return false;
    }
    return true;
}

// Initialize the steno protocol
void eeconfig_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT);  // or STENO_MODE_BOLT
}
