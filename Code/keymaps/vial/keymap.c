#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_4x12(
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_E,
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_X,    RGB_MOD,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    MO(1),
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    MO(2)
    ),
    [1] = LAYOUT_ortho_4x12(
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    QK_BOOT,
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_L,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L
    ),
    [2] = LAYOUT_ortho_4x12(
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
                 KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    QK_BOOT, KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_A, KC_B),           ENCODER_CCW_CW(KC_C, KC_D)  },
    [1] =   { ENCODER_CCW_CW(KC_D, KC_E),           ENCODER_CCW_CW(KC_F, KC_G)  },
    [2] =   { ENCODER_CCW_CW(KC_J, KC_H),           ENCODER_CCW_CW(KC_M, KC_N)  },
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        for (uint8_t i = led_min; i < led_max; i++) {
            switch(get_highest_layer(layer_state|default_layer_state)) {
                case 0:
                    if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW)
                        rgb_matrix_set_color(i, 153 , 0 , 76);
                        //rgb_matrix_set_color(i, RGB_MAGNETA);
                    if (host_keyboard_led_state().caps_lock)
                        {
                        RGB_MATRIX_INDICATOR_SET_COLOR(80, 255, 0, 0);
                        RGB_MATRIX_INDICATOR_SET_COLOR(81, 255, 0, 0);
                        }
                        break;
                case 1:
                    if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW)
                        rgb_matrix_set_color(i, 204 , 204 , 0);
                    if (host_keyboard_led_state().caps_lock)
                        {
                        RGB_MATRIX_INDICATOR_SET_COLOR(80, 255, 0, 0);
                        RGB_MATRIX_INDICATOR_SET_COLOR(81, 255, 0, 0);
                        }
                        break;
                case 2:
                    if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW)
                        rgb_matrix_set_color(i, 0 , 206 , 209);
                    if (host_keyboard_led_state().caps_lock)
                        {
                        RGB_MATRIX_INDICATOR_SET_COLOR(80, 255, 0, 0);
                        RGB_MATRIX_INDICATOR_SET_COLOR(81, 255, 0, 0);
                        }
                        break;
                    }
                    }

    return false;
}

