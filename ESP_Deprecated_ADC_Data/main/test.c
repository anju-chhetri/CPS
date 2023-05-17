
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "driver/adc.h"
#include "esp_adc_cal.h"

#define ADC_CHANNEL ADC1_CHANNEL_6 // GPIO34

#define BUZZER_PIN GPIO_NUM_32

static const char *TAG = "Sharp ADC Measured Distance: ";

static esp_adc_cal_characteristics_t adc_characteristic;

void app_main(void)
{
    float voltage;
    float distance;
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc_characteristic);
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ADC_CHANNEL, ADC_ATTEN_DB_11));

    // Configure buzzer pin
    esp_rom_gpio_pad_select_gpio(BUZZER_PIN);
    gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        voltage = esp_adc_cal_raw_to_voltage(adc1_get_raw(ADC_CHANNEL), &adc_characteristic);
        distance = (0.0023 * ((float)voltage / 100) - 0.007);
        // ESP_LOGI(TAG, "Distance : %f cm", (distance));
        ESP_LOGI(TAG, "ADC voltage : %f mV", voltage);
        // ESP_LOGI(TAG, "Distance : %f cm", (1 / distance));

        // Check if distance reaches a certain threshold
        // if (1 / distance < 30.0)
        if (voltage > 2000)
        {
            // Turn on the buzzer
            gpio_set_level(BUZZER_PIN, 1);
        }
        else
        {
            // Turn off the buzzer
            gpio_set_level(BUZZER_PIN, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
