#include "crkbd.h"
#include "bootloader.h"
#include "action_layer.h"
#include "action_util.h"
#include "eeconfig.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#include "LUFA/Drivers/Peripheral/TWI.h"
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "../lib/mode_icon_reader.c"
#include "../lib/layer_state_reader.c"
#include "../lib/host_led_state_reader.c"
#include "../lib/logo_reader.c"
#include "../lib/keylogger.c"
#include "../lib/timelogger.c"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
  M_BSP_DEL,
  TMUX_PRE,
  SW_NUM,
  NUMBER,
  SYMBOL,
  FUNCTION
};

#define _QWERTY 0
#define _NUMBER 1
#define _SYMBOL 2
#define _FUNCTION 3

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_SMOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

// custom keys
#define KC_LCTT LCTL_T(KC_TAB)
#define KC_LSTN LSFT_T(KC_NO)
#define KC_RATN RALT_T(KC_NO)
#define KC_LGL2 LGUI_T(KC_LANG2)
#define KC_RGL1 RGUI_T(KC_LANG1)
#define KC_SHSP LSFT_T(KC_SPC)
#define KC_SHEN RSFT_T(KC_ENT)
#define KC_TMUX TMUX_PRE
#define KC_SW_NUM SW_NUM

#define KC_MVOM KC__MUTE
#define KC_MVOD KC__VOLDOWN
#define KC_MVOU KC__VOLUP

// mac
#define KC_BRU KC_PAUSE // backlight up
#define KC_BRD KC_SCROLLLOCK // backlight down

// layer change
#define KC_NUM TT(_NUMBER)
#define KC_SYM TT(_SYMBOL)
#define KC_FUN TT(_FUNCTION)

// layer
#define KC_GQWE TO(_QWERTY)
#define KC_GNUM TO(_NUMBER)
#define KC_GSYM TO(_SYMBOL)
#define KC_GFUN TO(_FUNCTION)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      GESC,   Q,     W,     E,     R,     T,                   	   Y,    U,     I,     O,     P,    BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LCTT,   A,     S,     D,     F,     G,                       H,    J,     K,     L,    SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LSTN,   Z,     X,     C,     V,     B,                       N,    M,   COMM,   DOT,   SLSH,  RALT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  SYM,   LGL2,  SHSP,     SHEN,  RGL1,  NUM\
                              //`--------------------'  `-----------------------'
  ),

  [_NUMBER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TRNS,   1,     2,     3,     4,     5,                       6,     7,    8,     9,     0,    TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10,   FUN,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,  F11,   F12,   PEQL,  PSLS,  PAST,                    NO,   PMNS,  PLUS,  PEQL,   NO,  TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  FUN,   TRNS,  TRNS,     TRNS,   TRNS,  TRNS\
                              //`--------------------'  `-----------------------'
  ),

  [_SYMBOL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TRNS,  EXLM,   AT,   HASH,  DLR,   PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,  TMUX,   NO,    NO,   PAST,  PLUS,                   MINS,  EQL,   PIPE,  LBRC,  RBRC,  FUN,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   NO,    NO,    NO,   PSLS,  PMNS,                   UNDS,  GRV,   BSLS,  LABK,  RABK,  TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  TRNS,  TRNS,  TRNS,     TRNS,   TRNS,  FUN\
                              //`--------------------'  `-----------------------'
  ),

  [_FUNCTION] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RST,    NO,    NO,   MVOM,  MVOD,  MVOU,                    NO,   BRD,   BRU,    NO,    NO,   TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   NO,   MS_L,  MS_D,  MS_U,  MS_R,                   LEFT,  DOWN,   UP,   RGHT,   NO,   TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   NO,    NO,    NO,   HOME,  END,                     NO,  BTN1,   BTN2,   NO,    NO,   TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS\
                              //`--------------------'  `-----------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
    case TMUX_PRE:
      SEND_STRING(SS_LCTRL("z"));
      return false;
      break;
  }
  return true;
}
;

/**
 * Change ctrl+backspace into delete and do not register the ctrl modifier.
 */
static bool control_disabled = false;
static bool delete_pressed = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if(keycode == KC_BSPC) {
    if (record->event.pressed) {
      if(keyboard_report->mods & MOD_BIT(KC_LCTL)) {
        delete_pressed = true;
        control_disabled = true;
        unregister_code(KC_LCTL);
        register_code(KC_DEL);
        return false;
      }
    } else if(delete_pressed) {
      delete_pressed = false;
      unregister_code(KC_DEL);

      if(control_disabled) {
        control_disabled = false;
        register_code(KC_LCTL);
      }
      return false;
    }
  } else if(keycode == KC_LCTL && !record->event.pressed && delete_pressed) {
    delete_pressed = false;
    control_disabled = false;
    unregister_code(KC_DEL);
    register_code(KC_BSPC);
    return false;
  }
  return true;
}
;

#endif
