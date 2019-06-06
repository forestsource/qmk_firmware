/*
Copyright 2018 Sekigon

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
#include "app_ble_func.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    BSP_DEL,
    QWERTY,
    COLEMAK,
    DVORAK,
    LOWER,
    RAISE,
    ADJUST,
    BACKLIT,
    EISU,
    KANA,
    NUMBER,
    SYMBOL,
    FUNCTION,
    RGBRST
};


extern keymap_config_t keymap_config;

#if HELIX_ROWS == 5
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};
# else
enum layer_number {
    _QWERTY = 0,
    _NUMBER,
    _SYMBOL,
    _FUNCTION
};
#endif

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

// custom keys
#define KC_LCTT LCTL_T(KC_TAB)
#define KC_LSTN LSFT_T(KC_NO)
#define KC_RATN RALT_T(KC_NO)
#define KC_LGL2 LGUI_T(KC_LANG2)
#define KC_RGL1 RGUI_T(KC_LANG1)
#define KC_SHSP LSFT(KC_SPC)
#define KC_SHEN RSFT(KC_ENT)

#define KC_MVOM KC__MUTE
#define KC_MVOD KC__VOLDOWN
#define KC_MVOU KC__VOLUP

// ble
#define KC_BT_E BLE_EN
#define KC_BT_D BLE_DIS
#define KC_AD_B AD_WO_L
#define KC_AD0  ADV_ID0
#define KC_AD1  ADV_ID1
#define KC_AD2  ADV_ID2
#define KC_AD3  ADV_ID3
#define KC_AD4  ADV_ID4
#define KC_DFU  ENT_DFU

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


#if HELIX_ROWS == 4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      GESC,   Q,     W,     E,     R,     T,                   	   Y,    U,     I,     O,     P,    BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LCTT,   A,     S,     D,     F,     G,                       H,    J,     K,     L,    SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LSTN,   Z,     X,     C,     V,     B,                       N,    M,   COMM,   DOT,   SLSH,  RATN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  SYM,   LGL2,  SHSP,     SHEN,  RGL1,  NUM\
                              //`--------------------'  `-----------------------'
  ),

  [_NUMBER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TRNS,   1,     2,     3,     4,     5,                       6,     7,    8,     9,     0,    BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,   F9,    F10,   FUN,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,  F11,   F12,   F13,   F14,   F15,                     NO,    NO,    NO,    NO,   AD0,   TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  SYM,   TRNS,  TRNS,     TRNS,   TRNS,  TRNS\
                              //`--------------------'  `-----------------------'
  ),

  [_SYMBOL] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TRNS,  EXLM,   AT,   HASH,  DLR,   PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   NO,    NO,    NO,   PAST,  PLUS,                   MINS,  EQL,   PIPE,  LBRC,  RBRC,  FUN,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,  AD0,    NO,    NO,   PSLS,  PMNS,                   UNDS,  GRV,   BSLS,  LABK,  RABK,  NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  TRNS,  TRNS,  TRNS,     TRNS,   TRNS,  NUM\
                              //`--------------------'  `-----------------------'
  ),

  [_FUNCTION] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RST,    NO,    NO,   MVOM,  MVOD,  MVOU,                    NO,   BRD,   BRU,    NO,    NO,   BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LTOG,   NO,    MS_L, MS_D,  MS_U,  MS_R,                   LEFT,  DOWN,   UP,   RGHT,   NO,   TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      TRNS,   NO,    NO,    NO,   HOME,  END,                     NO,  BTN1,   BTN2,  NO,     NO,   NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GQWE,  TRNS,  TRNS,     TRNS,  TRNS,  GQWE\
                              //`--------------------'  `-----------------------'
  )
};

#else
#error "undefined keymaps"
#endif

#if HELIX_ROWS == 5
// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
  layer_state_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  uint8_t bdk;

  #if HELIX_ROWS == 5
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(16);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(15);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
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
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
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
  }
  #endif
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    case BSP_DEL:
      bdk = KC_BSPC;
      if (keyboard_report->mods) {
        bdk = KC_DEL;
      }
      if (record->event.pressed){
        register_code(bdk);
        return false;
      }else{
        unregister_code(bdk);
        return false;
      }
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }
  }
  return true;
}
;
