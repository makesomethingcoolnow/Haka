#include QMK_KEYBOARD_H

enum layers {
_RHINO,
_RHINOPLUS,
_VW,
_SPOTIFY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_RHINO] = LAYOUT(
  KC_A,    KC_S,    KC_D,    KC_F,
  KC_1,    KC_1,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
),

[_RHINOPLUS] = LAYOUT(
  KC_A,    KC_S,    KC_D,    KC_F,
  KC_1,    KC_1,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
),


[_VW] = LAYOUT(
  KC_A,    KC_S,    KC_D,    KC_F,
  KC_1,    KC_1,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
),


[_SPOTIFY] = LAYOUT(
  KC_A,    KC_S,    KC_D,    KC_F,
  KC_1,    KC_1,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
),


};


/* Encoder Stuff */

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } 
    return false;
};



/* Led Stuff */


const rgblight_segment_t PROGMEM my_RHINO_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_PURPLE}
);

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_RHINOPLUS_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_RED}
);

// Light LEDs 9 & 10 in cyan when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_VW_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_BLUE}
);

// Light LEDs 9 & 10 in cyan when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_SPOTIFY_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_WHITE}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_RHINO_layer,
    my_RHINOPLUS_layer,
    my_VW_layer,
    my_SPOTIFY_layer

);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};



layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _RHINO));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RHINOPLUS));
    rgblight_set_layer_state(2, layer_state_cmp(state, _VW));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SPOTIFY));
    return state;
};

