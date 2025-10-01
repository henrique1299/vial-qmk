#ifdef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN_2
#define RGB_MATRIX_EFFECT_GRADIENT_UP_DOWN_2
RGB_MATRIX_EFFECT(GRADIENT_UP_DOWN_2)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool GRADIENT_UP_DOWN_2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    hsv_t base_hsv = rgb_matrix_config.hsv;
    uint8_t max_y = 64;  // based on your comment (y range 0..64)
    uint8_t speed = rgb_matrix_config.speed;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint8_t y = g_led_config.point[i].y;

        // Normalize y to 0..255
        uint8_t position = scale8(y, 255 * max_y / max_y);  // effectively (y * 255 / max_y)

        // Interpolate saturation with speed controlling the midpoint
        uint8_t sat;
        if (position <= speed) {
            sat = scale8(base_hsv.s, scale8(position, 255 * 255 / speed));
        } else {
            sat = scale8(base_hsv.s, scale8((255 - position), 255 * 255 / (255 - speed)));
        }

        hsv_t hsv;
        hsv.h = base_hsv.h;
        hsv.s = sat;
        hsv.v = base_hsv.v;

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}


#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
