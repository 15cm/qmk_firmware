/* #include "keymap.h" */
/* #include "password.h" */

#include QMK_KEYBOARD_H

#define F_TAB LT(1, KC_TAB)
#define F_CTL MO(2)
#define F_SPC LT(1, KC_SPC)
// #define F_SPC MT((MOD_LSFT | MOD_LGUI | MOD_LALT), KC_SPC)
#define F_ESC MT(MOD_RCTL, KC_ESC)
#define F_LGUI MT(MOD_LGUI, KC_F7)

#define F_LCAG_A LCAG(KC_A)
#define F_LCAG_S LCAG(KC_S)
#define F_LCAG_D LCAG(KC_D)
#define F_LCAG_F LCAG(KC_F)
#define F_LCAG_Z LCAG(KC_Z)
#define F_LCAG_X LCAG(KC_X)
#define F_LCAG_C LCAG(KC_C)
#define F_LCAG_N LCAG(KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        1 char = 0.25u
        ,--------------------------------------------------------------------------
        |  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  BSPC  |
        |--------------------------------------------------------------------------
        |TAB   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |
        |--------------------------------------------------------------------------
        |LCT/ESC|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |    ENT   |
        |--------------------------------------------------------------------------
        |   LST   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |      RST    |
        |--------------------------------------------------------------------------
        |LCTL| LALT| LGUI|               SPC           | RGUI|LEFT|DOWN| UP | RGHT|
        `--------------------------------------------------------------------------
    */

    LAYOUT_all (
                KC_GRV  , KC_1   , KC_2   , KC_3, KC_4, KC_5, KC_6, KC_7, KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC, \
        KC_TAB  , KC_Q   , KC_W   , KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
        F_ESC   , KC_A   , KC_S   , KC_D, KC_F, KC_G, KC_H, KC_J, KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_NO, KC_ENT , \
                KC_LSFT , KC_NO, KC_Z   , KC_X   , KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_RSFT, KC_RSFT, \
        F_CTL   , KC_LALT, F_LGUI,                F_SPC              ,    KC_RGUI, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT),

    /*
        1 char = 0.25u
        ,--------------------------------------------------------------------------
        |  ` | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|        |
        |--------------------------------------------------------------------------
        |      |MUTE|SVLD|SVLU|    |    |    |    |    |    |    |    |    |      |
        |--------------------------------------------------------------------------
        |       |IPRV|IPLY|INXT|    |    |    |    |    |    |    |    |          |
        |--------------------------------------------------------------------------
        |           |    |IVLD|IVLU|  |    |    |    |    |    |    |             |
        |--------------------------------------------------------------------------
        | L2  |     |     |                                        |    |F17 |RSET|
        `--------------------------------------------------------------------------
    */

    LAYOUT_all (
                _______ , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10   , KC_F11   , KC_F12, _______, _______, \
        _______         , KC_MUTE , KC_VOLD , KC_VOLU ,   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MPLY, KC_MPRV, KC_MNXT, _______,  \
                _______ , F_LCAG_A, F_LCAG_S, F_LCAG_D, F_LCAG_F, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL(KC_LEFT), LCTL(KC_RGHT), _______, _______,  \
                _______ , KC_NO, F_LCAG_Z, F_LCAG_X, F_LCAG_C,   _______, _______, _______, _______, LCTL(KC_BSPC), LCTL(KC_DELETE), _______, _______, _______, _______, \
        _______         , _______  , _______  ,                        _______                         ,   _______ , _______ , _______ , _______, _______),

    /*
      1 char = 0.25u
      ,--------------------------------------------------------------------------
      |  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  BSPC  |
      |--------------------------------------------------------------------------
      |TAB   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |
      |--------------------------------------------------------------------------
      |LCT/ESC|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |    ENT   |
      |--------------------------------------------------------------------------
      |   LST   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |      RST    |
      |--------------------------------------------------------------------------
      |L0| LALT| LGUI|          SPC                | RGUI|LEFT|DOWN| UP | RGHT|
      `--------------------------------------------------------------------------
    */

    /* [2] = KEYMAP_15CM ( */
    /*     KC_GRV  , KC_1   , KC_2   , KC_3, KC_4, KC_5, KC_6, KC_7, KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \ */
    /*     KC_TAB   , KC_Q   , KC_W   , KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \ */
    /*     F_ESC   , KC_A   , KC_S   , KC_D, KC_F, KC_G, KC_H, KC_J, KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \ */
    /*     KC_LSFT , KC_Z   , KC_X   , KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \ */
    /*     TO(0)  , KC_LALT, KC_LGUI,                KC_SPC              ,    KC_RGUI, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT), */
    LAYOUT_all (
                _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______, \
                       _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
                       _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, KC_NO, _______, \
                       TO(0), KC_NO, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______, _______, \
                       _______,_______,_______,_______,_______,_______,_______,KC_PSCR,RESET),
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
