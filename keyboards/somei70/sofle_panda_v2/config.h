// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define TAPPING_TERM 100
#define DEBOUNCE 5

/* encoder support */
// #define ENCODERS_PAD_A { GP28 }
// #define ENCODERS_PAD_B { GP29 }
#define ENCODERS_PAD_A_RIGHT { GP29 }
#define ENCODERS_PAD_B_RIGHT { GP28 }

#define ENCODER_RESOLUTION 4

//#define MASTER_LEFT
#define SPLIT_HAND_PIN GP4
#define	SPLIT_HAND_PIN_LOW_IS_LEFT
#define USB_VBUS_PIN 19
#define USE_SERIAL
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TX_PIN   GP1

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#ifdef OLED_ENABLE
// settings for the oled keyboard demo with Adafruit 0.91" OLED display on the Stemma QT port
    #define OLED_DISPLAY_128X32
    #define I2C_DRIVER I2CD1
    #define I2C1_SDA_PIN GP2
    #define I2C1_SCL_PIN GP3
    #define OLED_BRIGHTNESS 12
    #define OLED_TIMEOUT 16000
    #define OLED_FONT_H "lib/glcdfont.c"
    #define WPM_ESTIMATED_WORD_SIZE 5
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_WPM_ENABLE
    #define SPLIT_OLED_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_LED_COUNT       66 //72 // Number of LEDs
    #define RGBLED_NUM RGB_MATRIX_LED_COUNT
    #define DRIVER_LED_TOTAL RGB_MATRIX_LED_COUNT
    #define RGB_MATRIX_SPLIT { 30, 36 } //{ 36, 36 }
    #define WS2812_DI_PIN            GP0
    #define WS2812_PIO_USE_PIO1

    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_SLEEP
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 164

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

    #define ENABLE_RGB_MATRIX_BREATHING // Single hue brightness cycling animation
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right

    #define ENABLE_RGB_MATRIX_ALPHAS_MODS         // Static dual hue speed is hue for secondary hue
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT   // Static gradient left to right, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
    //#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
    //#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
    #define ENABLE_RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
    //#define ENABLE_RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE      // Static single hue pulses keys hit to shifted hue then fades to current hue
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    #define ENABLE_RGB_MATRIX_RIVERFLOW           // Modification to breathing animation offset's animation depending on key location to simulate a river flowing

#endif
