#include QMK_KEYBOARD_H

bool has_layer_changed = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(TG(1), LALT(KC_2), KC_PSCR, KC_F13, KC_MUTE, KC_F14, KC_MPLY, KC_MNXT),
	[1] = LAYOUT(KC_TRNS, KC_MUTE, KC_F15, RGB_TOG, KC_A, KC_S, KC_SCLN, KC_QUOT)
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
        rgblight_sethsv(127,255,255);
      break;
      case 1:
        rgblight_sethsv(198,255,255);
      break;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
