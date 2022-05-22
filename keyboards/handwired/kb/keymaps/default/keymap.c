#include "kb.h"

enum custom_layer {
  _NUMBERS,
  _LETTERS_1,
  _LETTERS_2,
  _RGB
};

enum encoder {
  _LOWER_ENCODER = 0,
  _UPPER_ENCODER = 1,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NUMBERS] = KEYMAP(
		KC_7, KC_8, KC_9, KC_AUDIO_MUTE, 
		KC_4, KC_5, KC_6, TO(_LETTERS_1), 
		KC_1, KC_2, KC_3, KC_MPLY),

	[_LETTERS_1] = KEYMAP(
		KC_H, KC_I, KC_J, KC_AUDIO_MUTE, 
		KC_E, KC_G, KC_F, TO(_LETTERS_2), 
		KC_A, KC_B, KC_C, KC_D),

	[_LETTERS_2] = KEYMAP(
		KC_R, KC_S, KC_T, RGB_TOG, 
		KC_O, KC_P, KC_Q, TO(_NUMBERS), 
		KC_K, KC_L, KC_M, KC_N),

	[_RGB] = KEYMAP(
		KC_TRNS, KC_TRNS, RGB_MODE_BREATHE, KC_TRNS, 
		KC_TRNS, KC_TRNS, RGB_MODE_PLAIN, KC_TRNS, 
		KC_TRNS, KC_TRNS, RGB_TOG, TO(0)),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
// 	keyevent_t event = record->event;

// 	switch (id) {

// 	}
// 	return MACRO_NONE;
// }

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == _UPPER_ENCODER) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	}

	if (index == _LOWER_ENCODER) {
		if (layer_state_is(_NUMBERS)){
			if (clockwise) {
				tap_code(KC_MS_WH_DOWN);
			} else {
				tap_code(KC_MS_WH_UP);
			}
		}
		else{
			if (clockwise) {
				tap_code(KC_UP);
			} else {
				tap_code(KC_DOWN);
			}
		}
	}
	
}

layer_state_t layer_state_set_user(layer_state_t state) {
	// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#lighting-layer-blink-id-lighting-layer-blink
    switch (get_highest_layer(state)) {
    case _NUMBERS:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _LETTERS_1:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _LETTERS_2:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    // case _RGB:
    //     rgblight_setrgb (0x00,  0xFF, 0x00);
    //     break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0xFF, 0xFF);
        break;
    }
  return state;
}