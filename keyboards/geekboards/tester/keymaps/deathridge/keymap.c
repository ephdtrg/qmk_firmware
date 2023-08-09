#include QMK_KEYBOARD_H

bool has_layer_changed = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(MO(1), LT(2,KC_F10), KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_F13, KC_F14, KC_F17, KC_CALC, RCTL(KC_F5), LGUI(KC_L)),
  [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_PGUP, KC_PGDN)
};

void matrix_init_user(void) {
  //user initialization
  rgblight_enable(); // enables Rgb, without saving settings
  rgblight_sethsv(100, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode(RGB_MATRIX_BREATHING); // sets mode to Fast breathing without saving
}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  static uint8_t old_layer = 0;

  if (old_layer != layer) {
    has_layer_changed = true;
    old_layer = layer;
  }

  if (has_layer_changed) {
    has_layer_changed = false;

    switch (layer) {
      case 0:
        rgblight_sethsv(100,255,255);
      break;
      case 1:
        rgblight_sethsv(198,255,255);
      break;
      case 2:
        rgblight_sethsv(164,255,255);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
