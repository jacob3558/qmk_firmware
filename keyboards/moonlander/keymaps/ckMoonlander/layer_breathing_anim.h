RGB_MATRIX_EFFECT(layer_breathing)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "layers.c"
extern PROGMEM uint8_t ledmap[][DRIVER_LED_TOTAL][3];

static HSV FILTER_BREATH(HSV hsv, bool isBreathing){
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);

    if(isBreathing){
        hsv.v = scale8(abs8(sin8(time) - 128) * 2, rgb_matrix_config.hsv.v);
    } else {
        hsv.v = rgb_matrix_config.hsv.v;
    }
    return hsv;
}

bool layer_breathing(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    int currentLayer = get_highest_layer(layer_state);
    for(uint8_t m = 0; m < DRIVER_LED_TOTAL; m++){
        HSV hsv = {
            .h   = pgm_read_byte(&ledmap[currentLayer][m][0]),
            .s   = pgm_read_byte(&ledmap[currentLayer][m][1]),
            .v   = pgm_read_byte(&ledmap[currentLayer][m][2]),
        };
        bool isSpringGreen = hsv.h == 106 && hsv.s == 255 && hsv.v == 255;
        bool isCyan = hsv.h == 128 && hsv.s == 255 && hsv.v == 255;
        bool isGold = hsv.h == 36 && hsv.s == 255 && hsv.v == 255;
        bool isAzure = hsv.h == 132 && hsv.s == 102 && hsv.v == 255;
        bool isChartReuse = hsv.h == 64 && hsv.s == 255 && hsv.v == 255;

        switch(currentLayer){
            case MacbookLayer:
                hsv = FILTER_BREATH(hsv, isSpringGreen);
                break;
            case WindowsLayer:
                hsv = FILTER_BREATH(hsv, isCyan);
                break;
            case GameLayer:
            case MouseLayer:
            case ArrowsLayer:
                hsv = FILTER_BREATH(hsv, isGold);
                break;
            case NumpadLayer:
                hsv = FILTER_BREATH(hsv, isAzure);
                break;
            case FuncLayer:
                hsv = FILTER_BREATH(hsv, isChartReuse);
                break;
            default:
                break;
        }

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

        for (uint8_t i = led_min; i < led_max; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(m, rgb.r, rgb.g, rgb.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
