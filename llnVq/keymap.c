#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_74_255_206,
  HSV_152_255_255,
  HSV_0_255_255,
  SE_LSPO,
  SE_RSPC,
};



#define DUAL_FUNC_0 LT(15, KC_Z)
#define DUAL_FUNC_1 LT(12, KC_N)
#define DUAL_FUNC_2 LT(4, KC_F14)
#define DUAL_FUNC_3 LT(14, KC_F14)
#define DUAL_FUNC_4 LT(3, KC_E)
#define DUAL_FUNC_5 LT(3, KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    SE_SECT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_HOME,                                        KC_END,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DUAL_FUNC_1,    
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TG(1),                                          TG(1),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           DUAL_FUNC_2,    
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           LSFT(KC_LEFT_CTRL),                                                                KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           LT(2, SE_OSLH), DUAL_FUNC_3,    
    SE_LSPO,        DUAL_FUNC_0,    KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, SE_MINS),SE_RSPC,        
    KC_LEFT_CTRL,   MO(1),          KC_LEFT_ALT,    KC_LEFT,        KC_RIGHT,       KC_ESCAPE,                                                                                                      MT(MOD_LCTL, KC_ESCAPE),KC_UP,          KC_DOWN,        DUAL_FUNC_4,    DUAL_FUNC_5,    MO(1),          
    KC_SPACE,       KC_BSPC,        KC_LEFT_GUI,                    KC_LEFT_ALT,    KC_RIGHT_SHIFT, KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_PSCR,                                        KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_INSERT,      KC_EXLM,        SE_AT,          SE_PND,         SE_DLR,         SE_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_F12,         
    KC_DELETE,      KC_HASH,        KC_DLR,         SE_LPRN,        SE_RPRN,        SE_GRV,         SE_APOS,                                                                        HSV_0_255_255,  KC_PGDN,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_MINUS,    
    KC_TRANSPARENT, SE_LESS,        KC_CIRC,        DUAL_FUNC_4,    DUAL_FUNC_5,    SE_TILD,                                        SE_BSLS,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_74_255_206, HSV_152_255_255,RGB_MODE_FORWARD,                                                                                                RGB_TOG,        KC_KP_0,        KC_KP_DOT,      KC_KP_0,        KC_RIGHT_ALT,   KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [2] = LAYOUT_moonlander(
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    MU_TOGG,        KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_NEXT,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SE_LSPO:
            return TAPPING_TERM -120;
        case SE_RSPC:
            return TAPPING_TERM -120;
        default:
            return TAPPING_TERM;
    }
}






bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case SE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case SE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Z);
        } else {
          unregister_code16(KC_Z);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_LESS);
        } else {
          unregister_code16(SE_LESS);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(SE_PLUS);
        } else {
          unregister_code16(SE_PLUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_ACUT);
        } else {
          unregister_code16(SE_ACUT);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(SE_AA);
        } else {
          unregister_code16(SE_AA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_DIAE);
        } else {
          unregister_code16(SE_DIAE);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(SE_ADIA);
        } else {
          unregister_code16(SE_ADIA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_APOS);
        } else {
          unregister_code16(SE_APOS);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(SE_LCBR);
        } else {
          unregister_code16(SE_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_LBRC);
        } else {
          unregister_code16(SE_LBRC);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(SE_RCBR);
        } else {
          unregister_code16(SE_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(SE_RBRC);
        } else {
          unregister_code16(SE_RBRC);
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_74_255_206:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(74,255,206);
        }
        return false;
    case HSV_152_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(152,255,255);
        }
        return false;
    case HSV_0_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,255,255);
        }
        return false;
  }
  return true;
}






bool hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSPO:
        case KC_RSPC:
            return true;
        default:
            return false;
    }
}
