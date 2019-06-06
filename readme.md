## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are hosted on [Gitbook](https://www.gitbook.com/book/qmk/firmware/details) and [GitHub](/docs/) (they are synced). You can request changes by making a fork and [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "suggest an edit" link on any page of the docs.

## Key

```
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      GESC,   Q,     W,     E,     R,     T,                       Y,    U,     I,     O,     P,    BSPC,\
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
```

### custom key code

```
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

```
