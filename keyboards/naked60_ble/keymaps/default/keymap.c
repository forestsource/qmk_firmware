/* Copyright 2018 Salicylic_Acid
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "app_ble_func.h"
/*#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

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
*/

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST,
  AD_WO_L,              /* Start advertising without whitelist  */
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
};

//extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define KC_MLAD  MO(_ADJUST)

#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJUST ADJUST

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

// #define KC_RST   RESET
// #define KC_LRST  RGBRST
// #define KC_LTOG  RGB_TOG
// #define KC_LHUI  RGB_HUI
// #define KC_LHUD  RGB_HUD
// #define KC_LSAI  RGB_SAI
// #define KC_LSAD  RGB_SAD
// #define KC_LVAI  RGB_VAI
// #define KC_LVAD  RGB_VAD
// #define KC_LMOD  RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP
#define KC_DEBUG DEBUG

#define KC_RST   ENT_DFU
#define KC_BATT  BATT_LV
#define KC_BTON  BLE_EN
#define KC_BTOF  BLE_DIS
#define KC_USBON USB_EN
#define KC_USBOF USB_DIS
#define KC_BTNEW AD_WO_L
#define KC_BTID0 ADV_ID0
#define KC_BTID1 ADV_ID1
#define KC_BTID2 ADV_ID2
#define KC_BTID3 ADV_ID3
#define KC_BTID4 ADV_ID4

#define KC_SNUBS S(KC_NUBS)
#define KC_SNUHS S(KC_NUHS)

#define KC_CAD LCA(KC_DEL)
#define KC_APSCR LALT(KC_PSCR)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------|             |-----------------------------------------.
        ESC,     1,     2,     3,     4,     5,                   6,     7,     8,     9,     0,  BSPC,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
        TAB,     Q,     W,     E,     R,     T,                   Y,     U,     I,     O,     P,  BSLS,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
       LSFT,     A,     S,     D,     F,     G,                   H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      LCTRL,     Z,     X,     C,     V,     B,                   N,     M,  COMM,   DOT,  SLSH,   ENT,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------+------|
            ADJUST, LCTRL,  LALT,  LGUI, LOWER,   SPC,   SPC, RAISE,  LEFT,  DOWN,    UP, RIGHT \
          //`----------------------------------------------------------------------------------'
  ),


  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------|             |-----------------------------------------.
        F11,    F1,    F2,    F3,    F4,    F5,                  F6,    F7,    F8,    F9,   F10,   F12,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                CIRC,  AMPR,  ASTR,  LPRN,  RPRN,   DEL,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,    F1,    F2,    F3,    F4,    F5,                  F6,  UNDS,  PLUS,  LCBR,  RCBR,  PIPE,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,    F7,    F8,    F9,   F10,   F11,                 F12, SNUHS, SNUBS, _____, _____, _____,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------+------|
             _____, _____, _____, _____, LOWER, _____, _____,  MLAD,  MNXT,  VOLD,  VOLU,  MPLY \
          //`----------------------------------------------------------------------------------'
  ),


  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------|             |-----------------------------------------.
        F11,    F1,    F2,    F3,    F4,    F5,                  F6,    F7,    F8,    F9,   F10,   F12,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
       TILD,     1,     2,     3,     4,     5,                   6,     7,     8,     9,     0,   DEL,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,    F1,    F2,    F3,    F4,    F5,                  F6,  MINS,   EQL,  LBRC,  RBRC,  BSLS,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,    F7,    F8,    F9,   F10,   F11,                 F12,  NUHS,  NUBS, _____, _____, _____,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------+------|
             _____, _____, _____, _____,  MLAD, _____, _____, RAISE,  MNXT,  VOLD,  VOLU,  MPLY \
          //`----------------------------------------------------------------------------------'
  ),


  [_ADJUST] = LAYOUT_kc( /* Base */
  //,-----------------------------------------|             |-----------------------------------------.
        F11,    F1,    F2,    F3,    F4,    F5,                  F6,    F7,    F8,    F9,   F10,   F12,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,  BATT,  KNRM,  KSWP, XXXXX, XXXXX,               XXXXX,  BTN1,  MS_U,  BTN2, XXXXX,   CAD,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,  BTON, USBON, BTID0, BTID2, BTID4,               XXXXX,  MS_L,  MS_D,  MS_R, XXXXX,  PSCR,\
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _____,  BTOF, USBOF, BTID1, BTID3, BTNEW,               XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, APSCR,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------+------|
             _____, _____, _____, _____, _____,   RST,   RST, _____, _____, _____, _____, _____ \
          //`----------------------------------------------------------------------------------'
  )
};


static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];

  bool result = true;

  switch (keycode) {
  case LOWER:
    update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
    result = false;
    break;
  case RAISE:
    update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
    result = false;
    break;
  case KANJI:
    if (record->event.pressed) {
      if (keymap_config.swap_lalt_lgui == false) {
        register_code(KC_LANG2);
      } else {
        SEND_STRING(SS_LALT("`"));
      }
    } else {
      unregister_code(KC_LANG2);
    }
    result = false;
    break;
  #ifdef RGBLIGHT_ENABLE
    case RGB_MOD:
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      result = false;
      break;
    case RGBRST:
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      result = false;
      break;
#endif
  }

  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      result = false;
      break;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      result = false;
      break;
    case USB_EN:
      set_usb_enabled(true);
      result = false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      result = false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      result = false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      result = false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      result = false;
      break;
    case ADV_ID1:
      restart_advertising_id(1);
      result = false;
      break;
    case ADV_ID2:
      restart_advertising_id(2);
      result = false;
      break;
    case ADV_ID3:
      restart_advertising_id(3);
      result = false;
      break;
    case ADV_ID4:
      restart_advertising_id(4);
      result = false;
      break;
    case DEL_ID0:
      delete_bond_id(0);
      result = false;
      break;
    case DEL_ID1:
      delete_bond_id(1);
      result = false;
      break;
    case DEL_ID2:
      delete_bond_id(2);
      result = false;
      break;
    case DEL_ID3:
      delete_bond_id(3);
      result = false;
      break;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      result = false;
      break;
    case ENT_DFU:
      bootloader_jump();
      result = false;
      break;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      result = false;
      break;
    }
  }

  return result;
}
