/*
Copyright 2024 @keenah1

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// VS Code Shortcuts
#define VSC_FLD_REGION      (C(S(KC_LBRC)))
#define VSC_UNFLD_REGION    (C(S(KC_RBRC)))
#define VSC_INS_LINE_ABV    (C(KC_ENT))
#define VSC_INS_LINE_BLW    (C(S(KC_ENT)))
#define VSC_CMNT_LINE       (C(KC_SLSH))
#define VSC_CMNT_BLK        (S(A(KC_A)))

enum layouts {
  LAYER_0,
  LAYER_1,
  LAYER_SPCL,
  LAYER_VSC,
  NUM_LAYERS
};

const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_0] =
    /*
     *              ┌─────┬─────┬─────┬─────┬─────────┐         ┌─────┬─────┬──────┬─────┬─────┐
     *              │ 1/! │ 2/@ │ 3/# │ 4/$ │   5/%   │         │ 6/^ │ 7/& │ 8\*  │ 9/( │ 0/) │
     *       ┌──────┼─────┼─────┼─────┼─────┼─────────┤         ├─────┼─────┼──────┼─────┼─────┼──────┐
     *       │ TAB  │  Q  │  W  │  E  │  R  │    T    │         │  Y  │  U  │  I   │  O  │  P  │ BSPC │
     * ┌─────┼──────┼─────┼─────┼─────┼─────┼─────────┤         ├─────┼─────┼──────┼─────┼─────┼──────┼─────┐
     * │ ESC │ BSPC │  A  │  S  │  D  │  F  │    G    │         │  H  │  J  │  K   │  L  │ ;/: │ '/"  │ ENT │
     * ├─────┼──────┼─────┼─────┼─────┼─────┼─────────┤         ├─────┼─────┼──────┼─────┼─────┼──────┼─────┤
     * │ WIN │ SFT  │  Z  │  X  │  C  │  V  │    B    │         │  N  │  M  │ ,/<  │ ./> │ //? │ \/|  │ DEL │
     * └─────┴──────┴─────┼─────┼─────┼─────┼─────────┤         ├─────┼─────┼──────┼─────┼─────┴──────┴─────┘
     *                    │ VSC │ L1  │ SPC │ ENT/CTL │         │     │ SPC │ SPCL │     │
     *                    └─────┴─────┴─────┴─────────┘         └─────┴─────┴──────┴─────┘
     */
    LAYOUT(
                        KC_1,    KC_2,          KC_3,        KC_4,   KC_5,               KC_6,  KC_7,   KC_8,           KC_9,   KC_0,
               KC_TAB,  KC_Q,    KC_W,          KC_E,        KC_R,   KC_T,               KC_Y,  KC_U,   KC_I,           KC_O,   KC_P,     KC_BSPC,
      KC_ESC,  KC_BSPC, KC_A,    KC_S,          KC_D,        KC_F,   KC_G,               KC_H,  KC_J,   KC_K,           KC_L,   KC_SCLN,  KC_QUOT,  KC_ENT,
      KC_LWIN, KC_LSFT, KC_Z,    KC_X,          KC_C,        KC_V,   KC_B,               KC_N,  KC_M,   KC_COMM,        KC_DOT, KC_SLSH,  KC_BSLS,  KC_DEL,
                                 MO(LAYER_VSC), MO(LAYER_1), KC_SPC, CTL_T(KC_ENT),      KC_NO, KC_SPC, MO(LAYER_SPCL), KC_NO
    ),

  [LAYER_1] =
    /*
     *                 ┌─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┐
     *                 │     │     │     │ PUP │ HME │         │ F1  │ F2  │ F3  │     │     │
     *       ┌─────────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┐
     *       │ ALT+TAB │     │     │ UP  │ PDN │ END │         │ F4  │ F5  │ F6  │     │     │     │
     * ┌─────┼─────────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐
     * │     │   DEL   │     │ LFT │ DN  │ RGT │     │         │ F7  │ F8  │ F9  │     │     │     │     │
     * ├─────┼─────────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │         │     │     │     │     │     │         │ F10 │ F11 │ F12 │     │     │     │     │
     * └─────┴─────────┴─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┴─────┴─────┘
     *                       │     │ L1  │     │     │         │     │     │     │     │
     *                       └─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┘
     */
    LAYOUT(
                          KC_NO, KC_NO,   KC_NO,   KC_PGUP, KC_HOME,      KC_F1,   KC_F2,   KC_F3,   KC_NO,  KC_NO,
              A(KC_TAB),  KC_NO, KC_NO,   KC_UP,   KC_PGDN, KC_END,       KC_F4,   KC_F5,   KC_F6,   KC_NO,  KC_NO,   KC_NO,
      KC_NO,  KC_DEL,     KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,        KC_F7,   KC_F8,   KC_F9,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
      KC_NO,  KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_F10,  KC_F11,  KC_F12,  KC_NO,  KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_TRNS, KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

  [LAYER_SPCL] =
    /*
     *             ┌─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬──────┬─────┬─────┐
     *             │     │     │     │     │     │         │     │     │      │     │     │
     *       ┌─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼──────┼─────┼─────┼─────┐
     *       │     │     │     │     │     │     │         │     │     │      │     │     │     │
     * ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼──────┼─────┼─────┼─────┼─────┐
     * │  `  │ SFT │     │     │     │     │     │         │     │     │      │     │ -/_ │ =/+ │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼──────┼─────┼─────┼─────┼─────┤
     * │  ~  │     │     │     │     │     │     │         │     │     │      │     │ [/{ │ ]/} │     │
     * └─────┴─────┴─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼──────┼─────┼─────┴─────┴─────┘
     *                   │     │     │     │     │         │     │     │ SPCL │     │
     *                   └─────┴─────┴─────┴─────┘         └─────┴─────┴──────┴─────┘
     */
    LAYOUT(
                         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
      KC_GRV,   KC_LSFT, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_MINS, KC_EQL,  KC_NO,
      KC_TILD,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_LBRC, KC_RBRC, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_TRNS, KC_NO
    ),

  [LAYER_VSC] =
    LAYOUT(
                        KC_NO,         KC_NO,   KC_NO,   KC_NO,            KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
               KC_NO,   VSC_CMNT_LINE, KC_NO,   KC_NO,   VSC_INS_LINE_ABV, VSC_UNFLD_REGION,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO,   KC_NO,   VSC_CMNT_BLK,  KC_NO,   KC_NO,   VSC_INS_LINE_BLW, VSC_FLD_REGION,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,            KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                       KC_TRNS, KC_NO,   KC_NO,            KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO
    )
};
