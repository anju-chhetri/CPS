// #include <stdio.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <driver/gpio.h>
// #define LED_PIN GPIO_NUM_32

// void app_main(void)
// {

// gpio_set_direction(LED_PIN, GPIO_MODE_INPUT);
// while(1){   
    
//     gpio_set_level(LED_PIN, 1);
//     printf("R");
//     gpio_set_level(LED_PIN, 0);
//     vTaskDelay(500);

// }
// }

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "driver/adc.h"
#include "esp_adc_cal.h"

// #include "esp_adc/adc_oneshot.h"
// #include "esp_adc/adc_cali.h"
// #include "esp_adc/adc_cali_scheme.h"

#define ADC_CHANNEL ADC1_CHANNEL_6 //GPIO25 

static const char *TAG = "Sharp ADC Data: ";

static esp_adc_cal_characteristics_t adc_characteristic;

void app_main(void) {
    int voltage;
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc_characteristic);
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ADC_CHANNEL, ADC_ATTEN_DB_11)); 

    while (1) {
        voltage = esp_adc_cal_raw_to_voltage(adc1_get_raw(ADC_CHANNEL), &adc_characteristic);
        ESP_LOGI(TAG, "ADC voltage : %d mV", voltage);
        vTaskDelay(pdMS_TO_TICKS(100));
    }

}