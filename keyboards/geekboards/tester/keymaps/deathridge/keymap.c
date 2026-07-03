#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LAYER2,
    _LAYER3,
    _LAYER4
};

enum custom_keycodes {
    CS_I = SAFE_RANGE,  // Ctrl + Shift + I
    CS_E, // Ctrl + Shift + E
    CS_S, // Ctrl + Shift + S
    ALT_R, // Alt + R
    MPDW,
    MPDW_2,
    ALT_F4,
    WIN_S_RIGHT,
    WIN_C_L,
    CS_F11,
};

// Упрощенные псевдонимы для слоёв
#define MO_L2 MO(_LAYER2)
#define MO_L3 MO(_LAYER3)
#define MO_L4 MO(_LAYER4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
        CS_I, CS_S, CS_E, ALT_R, 
        LT(_LAYER2, KC_F13), KC_MUTE, KC_F14, LT(_LAYER3, KC_F21)
    ),
	[_LAYER2] = LAYOUT(
        MPDW, KC_F15, KC_CALC, KC_F16, 
        KC_TRNS, KC_F17, KC_F18, LALT(KC_F4)
    ),
    [_LAYER3] = LAYOUT(
        KC_MPLY, KC_MPRV, KC_MNXT, KC_F19,
        KC_F20, MO_L4, WIN_S_RIGHT, KC_TRNS
    ),
    [_LAYER4] = LAYOUT(
        MPDW_2, CS_F11, WIN_C_L, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
    )
};

void keyboard_post_init_user(void) {
    rgb_matrix_enable();  // включить RGB-подсветку
    rgb_matrix_mode(RGB_MATRIX_BREATHING);
    // rgb_matrix_sethsv(HSV_CYAN); // выбрать цвет (здесь циан, можно указать любой)
}

bool rgb_matrix_indicators_user(void) {

    // // Цвета задаются в HSV: (оттенок, насыщенность, яркость)
    // rgb_matrix_set_color(4, 255, 255, 0);  // 6 - Белый
    // rgb_matrix_set_color(5, 255, 255, 0);  // 6 - Белый
    // rgb_matrix_set_color(6, 25, 25, 255);    // 5 - Фиолетовый
    // rgb_matrix_set_color(7, 25, 25, 255);    // 5 - Фиолетовый

    switch (get_highest_layer(layer_state)) {

        case _BASE: // Подсветка базового слоя
            rgb_matrix_set_color(0, 51, 255, 25);     // Кнопка 1 - Красный
            rgb_matrix_set_color(1, 51, 255, 25);     // Кнопка 2 - Красный
            rgb_matrix_set_color(2, 51, 255, 25);     // Кнопка 3 - Красный
            rgb_matrix_set_color(3, 51, 255, 25);     // Кнопка 4 - Красный

            rgb_matrix_set_color(4, 51, 255, 25);  // Кнопка 5 - Синий

            rgb_matrix_set_color(5, 51, 255, 25);   // Кнопка 6 - Красный
            rgb_matrix_set_color(6, 51, 255, 25);   // Кнопка 7 - Красный

            rgb_matrix_set_color(7, 51, 255, 25);     // Кнопка 8 - Зеленый
            break;

        case _LAYER2: // слой 2 (сам настроишь)
            rgb_matrix_set_color(0, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(1, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(2, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(3, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(4, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(5, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(6, 51, 51, 255);  // Кнопка 5 - Синий
            rgb_matrix_set_color(7, 51, 51, 255);  // Кнопка 5 - Синий
            break;

        case _LAYER3: // слой 3 (сам настроишь)
            rgb_matrix_set_color(0, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(1, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(2, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(3, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(4, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(5, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(6, 0, 204, 0);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(7, 0, 204, 0);     // Кнопка 8 - Зеленый

            break;

        case _LAYER4: // слой 3 (сам настроишь)
            rgb_matrix_set_color(0, 51, 51, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(1, 51, 255, 25);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(2, 178, 102, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(3, 178, 102, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(4, 178, 102, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(5, 178, 102, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(6, 178, 102, 255);     // Кнопка 8 - Зеленый
            rgb_matrix_set_color(0, 51, 51, 255);     // Кнопка 8 - Зеленый

            break;

        
    }

    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_I:
            if (record->event.pressed) {
                tap_code16(C(S(KC_I)));
            }
            return false;
        case CS_E:
            if (record->event.pressed) {
                tap_code16(C(S(KC_E)));

            }
            return false;
        case CS_S:
            if (record->event.pressed) {
                tap_code16(C(S(KC_S)));
            }
            return false;
        case ALT_R:
            if (record->event.pressed) {
                tap_code16(A(KC_R));
            }
            return false;
        case MPDW:
            if (record->event.pressed) {
                SEND_STRING("portal1337");
            }
            return false;
        case MPDW_2:
            if (record->event.pressed) {
                SEND_STRING("eupheminty69#");
            }
            return false;
        case ALT_F4:
            if (record->event.pressed) {
                tap_code16(A(KC_F4));
            }
            return false;
        case WIN_S_RIGHT:
            if (record->event.pressed) {
                tap_code16(G(S(KC_RGHT)));
            }
            return false;
        case WIN_C_L:
            if (record->event.pressed) {
                tap_code16(G(C(KC_L)));
            }
            return false;
        case CS_F11:
            if (record->event.pressed) {
                tap_code16(C(S(KC_F11)));
            }
            return false;
 
 
    }
    return true;
}