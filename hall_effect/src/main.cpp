//  ___           _____    _
// / _ \ ___ _   |_   _|__| | ___  __ _ _ __ __ _ _ __ ___
//| | | / __| | | || |/ _ \ |/ _ \/ _` | '__/ _` | '_ ` _ \
//| |_| \__ \ |_| || |  __/ |  __/ (_| | | | (_| | | | | | |
// \___/|___/\__,_||_|\___|_|\___|\__, |_|  \__,_|_| |_| |_|
//

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define LED_PIN 25
#define ADC0 26
#define ADC1 27

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN,true);

    adc_init();
    adc_gpio_init(ADC0);
    adc_select_input(0);

    uint16_t min_hall = 65535;
    uint16_t max_hall = 0;
    for (int i = 0; i<100000; i++) {
        uint16_t result = adc_read();
        if (result > max_hall) {
            max_hall = result;
        }
        if (result < min_hall) {
            min_hall = result;
        }
        sleep_us(100);
    }
    gpio_put(LED_PIN,false);

    printf("vals between %i and %i", min_hall, max_hall);
    sleep_ms(5000);
    while (true) {
        uint16_t result = adc_read();
        sleep_ms(33);
        printf("\nresult: %i",result);
    }
}

int websocket() {
    int port;
    int
}

// int main() {
//     stdio_init_all();
//     printf("ADC Example, measuring GPIO26\n");

//     adc_init();

//     // Make sure GPIO is high-impedance, no pullups etc
//     adc_gpio_init(26);
//     // Select ADC input 0 (GPIO26)
//     adc_select_input(0);

//     while (1) {
//         // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
//         const float conversion_factor = 3.3f / (1 << 12);
//         uint16_t result = adc_read();
//         printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
//         sleep_ms(1);
//     }
// }
