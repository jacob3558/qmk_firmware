#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_korean.h"

#define CK_LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
                            k53, \
                        k50, k51, k52, \
    \
                                                k60, k61, k62, k63, k64, k65, k66, \
                                                k70, k71, k72, k73, k74, k75, k76, \
                                                k80, k81, k82, k83, k84, k85, k86, \
                                                k91, k92, k93, k94, k95, k96, \
                                                ka2, ka3, ka4, ka5, ka6, \
                                            kb3,\
                                        kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

//Custom Aliases
#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_MUTE KC_AUDIO_MUTE
#define BRIGHTER KC_BRIGHTNESS_UP
#define DIMMER KC_BRIGHTNESS_DOWN

#define M_SCRSHT LCTL(LGUI(LSFT(KC_4)))
#define M_PRV_TAB LGUI(LSFT(KC_LBRC))
#define M_NXT_TAB LGUI(LSFT(KC_RBRC))

#define W_SCRSHT LGUI(LSFT(KC_S))
#define W_PRV_TAB LCTL(LSFT(KC_TAB))
#define W_NXT_TAB LCTL(KC_TAB)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

enum layers {
    MacbookLayer,
    WindowsLayer,
    GameLayer,
    SymbolLayer,
    MouseLayer,
    NumpadLayer,
    FuncLayer,
    ArrowsLayer,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MacbookLayer] = CK_LAYOUT(
    KC_ESC        , KC_1         , KC_2          , KC_3    , KC_4    , KC_5 , KC_6      ,
    KC_TAB        , KC_Q         , KC_W          , KC_E    , KC_R    , KC_T , KC_Y      ,
    KC_LCTL       , KC_A         , KC_S          , KC_D    , KC_F    , KC_G , M_PRV_TAB ,
    KC_LSFT       , KC_Z         , KC_X          , KC_C    , KC_V    , KC_B ,
    LSFT(KC_LCTL) , XXXXXXX      , LALT(KC_LGUI) , KC_LALT , KC_LGUI ,
    TG(GameLayer) ,
    KC_SPC        , LGUI(KC_SPC) , MO(FuncLayer) ,

    KC_5             , KC_6           , KC_7            , KC_8   , KC_9    , KC_0    , KC_BSPC  ,
    M_SCRSHT         , KC_Y           , KC_U            , KC_I   , KC_O    , KC_P    , KC_EQL   ,
    M_NXT_TAB        , KC_H           , KC_J            , KC_K   , KC_L    , KC_SCLN , KC_ENTER ,
    KC_N             , KC_M           , KC_COMM         , KC_DOT , KC_SLSH , KC_RSFT ,
    KC_QUOT          , KC_LEFT        , KC_DOWN         , KC_UP  , KC_RGHT ,
    TG(WindowsLayer) ,
    MO(FuncLayer)    , MO(MouseLayer) , MO(SymbolLayer)
  )                              ,
  [WindowsLayer] = CK_LAYOUT(
    _______ , _______ , _______       , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______       , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______       , _______ , _______ , _______ , W_PRV_TAB ,
    _______ , _______ , _______       , _______ , _______ , _______ ,
    _______ , XXXXXXX , LALT(KC_LGUI) , KC_LGUI , KC_LALT ,
    _______ ,
    _______ , KR_HAEN , _______       ,

    _______   , _______ , _______ , _______ , _______ , _______ , KC_BSPC ,
    W_SCRSHT  , _______ , _______ , _______ , _______ , _______ , _______ ,
    W_NXT_TAB , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______   , _______ , _______ , _______ , _______ , _______ ,
    _______   , _______ , _______ , _______ , _______ ,
    _______   ,
    _______   , _______ , _______
  ),
  [GameLayer] = CK_LAYOUT(
    KC_ESC  , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , KC_GRV  ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_LCTL , XXXXXXX , XXXXXXX , KC_LGUI , KC_LALT ,
    _______ ,
    KC_SPC  , _______ , _______ ,

    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , KC_UP   , _______ , _______ ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX ,
    _______ ,
    _______ , _______ , _______
  ),
  [SymbolLayer] = CK_LAYOUT(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC ,
    _______ , XXXXXXX , KC_PIPE , KC_TILD , KC_AMPR , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , KC_LALT , KC_LGUI ,
    _______ ,
    _______ , _______ , _______ ,

    KC_DELETE , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_BSPC ,
    XXXXXXX   , XXXXXXX         , KC_PLUS , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC ,
    XXXXXXX   , KC_MINS         , KC_LCBR , KC_LABK , KC_RABK , KC_EQL  , XXXXXXX ,
    KC_UNDS   , KC_RCBR         , KC_ASTR , KC_BSLS , KC_QUES , _______ ,
    KC_GRV    , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______   ,
    XXXXXXX   , MO(NumpadLayer) , _______
  ),
  [MouseLayer] = CK_LAYOUT(
    XXXXXXX         , KC_MS_ACCEL0 , KC_MS_ACCEL1    , KC_MS_ACCEL2 , XXXXXXX        , XXXXXXX    , XXXXXXX ,
    XXXXXXX         , XXXXXXX      , XXXXXXX         , XXXXXXX      , XXXXXXX        , XXXXXXX    , XXXXXXX ,
    KC_LCTL         , XXXXXXX      , XXXXXXX         , XXXXXXX      , XXXXXXX        , XXXXXXX    , XXXXXXX ,
    KC_LSFT         , XXXXXXX      , XXXXXXX         , XXXXXXX      , XXXXXXX        , XXXXXXX    ,
    XXXXXXX         , XXXXXXX      , KC_LALT         , KC_LGUI      , XXXXXXX        ,
    LSFT(KC_LCTL)   ,
    XXXXXXX         , XXXXXXX      , XXXXXXX         ,

    XXXXXXX         , XXXXXXX      , XXXXXXX         , XXXXXXX      , XXXXXXX        , XXXXXXX    , XXXXXXX ,
    XXXXXXX         , XXXXXXX      , KC_MS_WH_LEFT   , KC_MS_UP     , KC_MS_WH_RIGHT , XXXXXXX    , XXXXXXX ,
    XXXXXXX         , KC_MS_BTN1   , KC_MS_LEFT      , KC_MS_DOWN   , KC_MS_RIGHT    , KC_MS_BTN2 , XXXXXXX ,
    KC_MS_BTN3      , KC_MS_WH_UP  , KC_MS_WH_DOWN   , XXXXXXX      , XXXXXXX        , XXXXXXX    ,
    XXXXXXX         , XXXXXXX      , XXXXXXX         , XXXXXXX      , XXXXXXX        ,
    XXXXXXX         ,
    MO(ArrowsLayer) , _______      , MO(NumpadLayer)
  ),
  [NumpadLayer] = CK_LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,
    _______ ,
    _______ , _______ , _______ ,

    XXXXXXX , XXXXXXX , KC_NLCK , KC_PSLS , KC_PAST , KC_PMNS , KC_BSPC ,
    XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , KC_PPLS , XXXXXXX ,
    XXXXXXX , XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PENT , XXXXXXX ,
    XXXXXXX , KC_P1   , KC_P2   , KC_P3   , XXXXXXX , XXXXXXX ,
    KC_P0   , KC_PDOT , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ ,
    XXXXXXX , _______ , _______
  ),
  [FuncLayer] = CK_LAYOUT(
    XXXXXXX , KC_F1       , KC_F2       , KC_F3      , KC_F4       , KC_F5    , KC_F6       ,
    XXXXXXX , LALT(KC_F4) , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX  , XXXXXXX     ,
    XXXXXXX , XXXXXXX     , VOL_DOWN    , VOL_MUTE   , VOL_UP      , BRIGHTER , WEBUSB_PAIR ,
    XXXXXXX , XXXXXXX     , TD(DANCE_0) , PLAY_PAUSE , TD(DANCE_1) , DIMMER   ,
    RESET   , XXXXXXX     , XXXXXXX     , XXXXXXX    , XXXXXXX     ,
    XXXXXXX ,
    XXXXXXX , KR_HANJ     , _______     ,

    KC_F5              , KC_F6           , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    XXXXXXX            , XXXXXXX         , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12  ,
    MU_TOG             , RGB_VAI         , RGB_HUI , RGB_HUD , RGB_SAI , XXXXXXX , XXXXXXX ,
    RGB_VAD            , RGB_SPI         , RGB_SPD , RGB_SAD , XXXXXXX , XXXXXXX ,
    TOGGLE_LAYER_COLOR , RGB_MOD         , RGB_SLD , XXXXXXX , RGB_TOG ,
    XXXXXXX            ,
    _______            , MO(ArrowsLayer) , XXXXXXX
  ),
  [ArrowsLayer] = CK_LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , KC_END  , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LALT ,
    _______ ,
    _______ , _______ , _______ ,

    _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , KC_HOME , XXXXXXX  , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX ,
    _______ , XXXXXXX , _______ , _______ , _______  ,
    _______ ,
    _______ , _______ , XXXXXXX
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [MacbookLayer] = { 
        {14,255,255}, {146,224,255}, {146,224,255}, {146,224,255}, {14,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {146,224,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {146,224,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255},
        {105,255,255}, {105,255,255}, {14,255,255},
        {105,255,255}, {35,255,255}, {205,255,255},
        {141,255,233},

        {146,224,255}, {105,255,255}, {146,224,255}, {146,224,255}, {35,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {35,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {35,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {35,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255},
        {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255},
        {105,255,255}, {14,255,255}, {14,255,255},
        {0,0,255}, {154,255,255}, {205,255,255},
        {141,255,233} },

    [WindowsLayer] = {
        {12,225,241}, {93,250,249}, {93,250,249}, {93,250,249}, {12,225,241},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {0,0,255},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {12,225,241}, 
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {93,250,249},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {93,250,249},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
        {146,224,255}, {146,224,255}, {12,225,241},
        {146,224,255}, {32,255,234}, {141,255,233},
        {0,204,255},

        {93,250,249}, {146,224,255}, {93,250,249}, {93,250,249}, {32,255,234},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {32,255,234},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {32,255,234},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {32,255,234},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
        {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
        {146,224,255}, {12,225,241}, {12,225,241},
        {0,0,255}, {33,255,255}, {141,255,233},
        {0,204,255} },

    [GameLayer] = {
        {14,255,255}, {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255},
        {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {33,255,255}, {33,255,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {141,255,233},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {30,96,255},
        {0,0,255}, {0,0,0}, {0,0,0},
        {141,255,233},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0} },

    [SymbolLayer] = {
        {250,159,255}, {205,255,255}, {205,255,255}, {205,255,255}, {233,218,217},
        {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {146,224,255}, {33,255,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {146,224,255}, {33,255,255}, {0,0,0}, {205,255,255},
        {0,0,0}, {146,224,255}, {33,255,255}, {0,0,0}, {205,255,255},
        {0,0,0}, {146,224,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {146,224,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},

        {14,255,255}, {12,225,241}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {12,225,241}, {146,224,255}, {146,224,255}, {0,0,0},
        {0,0,0}, {32,255,234}, {146,224,255}, {146,224,255}, {0,0,0},
        {0,0,0}, {32,255,234}, {146,224,255}, {146,224,255}, {0,0,0},
        {0,0,0}, {14,255,255}, {85,203,158}, {85,203,158}, {146,224,255},
        {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255},
        {14,255,255}, {0,0,0}, {0,0,0},
        {105,255,255}, {105,255,255}, {0,0,0},
        {0,0,0} },

    [MouseLayer] = {
        {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {169,120,255},
        {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {154,86,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {252,119,255}, {20,177,225}, {0,0,0}, {0,0,0},
        {0,0,0}, {20,177,225}, {20,177,225}, {252,119,255}, {0,0,0},
        {0,0,0}, {252,119,255}, {20,177,225}, {252,119,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {154,86,255}, {154,86,255},
        {0,0,0}, {0,0,0}, {0,0,0},
        {205,255,255}, {233,218,217}, {205,255,255},
        {0,0,0}
    },

    [NumpadLayer] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {255,220,201}, {255,220,201}, {14,222,242}, {0,0,0}, {0,0,0},
        {255,220,201}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0},
        {255,220,201}, {134,255,213}, {134,255,213}, {134,255,213}, {31,255,255},
        {31,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {134,255,213}, {134,255,213}, {0,0,0},
        {0,0,0}
    },

    [FuncLayer] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
        {32,176,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0},
        {35,255,255}, {0,0,0}, {10,225,255}, {134,255,213}, {0,0,0},
        {32,176,255}, {0,0,0}, {10,225,255}, {134,255,213}, {0,0,0},
        {32,176,255}, {0,0,0}, {10,225,255}, {134,255,213}, {0,0,0},
        {32,176,255}, {0,0,0}, {32,176,255}, {32,176,255},
        {32,176,255}, {0,0,0}, {205,255,255},
        {0,0,0}, {33,255,255}, {14,255,255},
        {0,0,0},

        {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {243,222,234},
        {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {32,176,255}, {0,0,0}, {10,225,255}, {10,225,255}, {243,222,234},
        {32,176,255}, {0,0,0}, {14,222,242}, {134,255,213}, {85,203,158},
        {32,176,255}, {0,0,0}, {10,225,255}, {134,255,213}, {180,255,233},
        {32,176,255}, {0,0,0}, {32,176,255}, {32,176,255},
        {32,176,255}, {0,0,0}, {30,96,255},
        {0,0,0}, {205,255,255}, {14,255,255},
        {0,0,0}
    },

    [ArrowsLayer] = {
        {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0},
        {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,183,238}, {32,176,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {205,255,255}, {205,255,255},
        {0,0,0}
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case MacbookLayer:
      set_layer_color(MacbookLayer);
      break;
    case WindowsLayer:
      set_layer_color(WindowsLayer);
      break;
    case GameLayer:
      set_layer_color(GameLayer);
      break;
    case SymbolLayer:
      set_layer_color(SymbolLayer);
      break;
    case MouseLayer:
      set_layer_color(MouseLayer);
      break;
    case NumpadLayer:
      set_layer_color(NumpadLayer);
      break;
    case FuncLayer:
      set_layer_color(FuncLayer);
      break;
    case ArrowsLayer:
      set_layer_color(ArrowsLayer);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);
void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_REWIND);
        tap_code16(KC_MEDIA_REWIND);
        tap_code16(KC_MEDIA_REWIND);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_REWIND);
    }
}

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_REWIND); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_REWIND); register_code16(KC_MEDIA_REWIND);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_REWIND); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_REWIND); break;
    }
    dance_state[0].step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_FAST_FORWARD);
        tap_code16(KC_MEDIA_FAST_FORWARD);
        tap_code16(KC_MEDIA_FAST_FORWARD);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_FAST_FORWARD);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_FAST_FORWARD); register_code16(KC_MEDIA_FAST_FORWARD);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
    }
    dance_state[1].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

