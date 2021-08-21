RGB_MATRIX_EFFECT(macbook_layer_anim)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

    extern PROGMEM uint8_t ledmap[][DRIVER_LED_TOTAL][3];

    bool macbook_layer_anim(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);

        for(uint8_t m = 0; m < DRIVER_LED_TOTAL; m++){
            HSV      hsv  = rgb_matrix_config.hsv;
            uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
            hsv.h = pgm_read_byte(&ledmap[0][m][0]);
            hsv.s = pgm_read_byte(&ledmap[0][m][1]);
            hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);

            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_TEST_LED_FLAGS();
                rgb_matrix_set_color(m, rgb.r, rgb.g, rgb.b);
            }
        }
        return led_max < DRIVER_LED_TOTAL;
    }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

