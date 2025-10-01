#ifdef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT_2
#define RGB_MATRIX_EFFECT_GRADIENT_LEFT_RIGHT_2
RGB_MATRIX_EFFECT(GRADIENT_LEFT_RIGHT_2)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool GRADIENT_LEFT_RIGHT_2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    hsv_t base_hsv = rgb_matrix_config.hsv;
    uint8_t max_x = 224; // max x coordinate based on your comment
    uint8_t speed = rgb_matrix_config.speed;  // speed as midpoint control

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint8_t x = g_led_config.point[i].x;

        // Calculate how far along the x-axis this LED is
        // Normalize 0..max_x to 0..255 scale
        uint8_t position = scale8(x, 255 * max_x / max_x);  // effectively (x * 255 / max_x)

        // Calculate saturation based on position relative to speed (midpoint)
        // If position < speed => saturation scales from 0 to base_saturation * (position/speed)
        // If position > speed => saturation scales from base_saturation * ((max - position)/(max - speed))
        uint8_t sat;

        if (position <= speed) {
            sat = scale8(base_hsv.s, scale8(position, 255 * 255 / speed)); // proportion of saturation
        } else {
            sat = scale8(base_hsv.s, scale8((255 - position), 255 * 255 / (255 - speed)));
        }

        // value stays constant, or you could interpolate it similarly if you want

        hsv_t hsv;
        hsv.h = base_hsv.h;  // keep hue constant (or could do interpolation)
        hsv.s = sat;
        hsv.v = base_hsv.v;

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}


#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
