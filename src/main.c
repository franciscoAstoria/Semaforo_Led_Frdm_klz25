#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define LED_RED_NODE   DT_ALIAS(led0)   // PTB18 - vermelho
#define LED_GREEN_NODE DT_ALIAS(led2)   // PTB19 - verde
#define SLEEP_TIME_MS_RED  5000
#define SLEEP_TIME_MS_YEL  1000
#define SLEEP_TIME_MS_GRE  3000

static const struct gpio_dt_spec led_red   = GPIO_DT_SPEC_GET(LED_RED_NODE, gpios);
static const struct gpio_dt_spec led_green = GPIO_DT_SPEC_GET(LED_GREEN_NODE, gpios);

int main(void)
{

    gpio_pin_configure_dt(&led_red,   GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&led_green, GPIO_OUTPUT_ACTIVE);

    while (1) {

        gpio_pin_set_dt(&led_red,   0);
        gpio_pin_set_dt(&led_green, 1);
        k_msleep(SLEEP_TIME_MS_GRE);

        gpio_pin_set_dt(&led_red,   1);
        gpio_pin_set_dt(&led_green, 1);
        k_msleep(SLEEP_TIME_MS_YEL);

        gpio_pin_set_dt(&led_red,   1);
        gpio_pin_set_dt(&led_green, 0);
        k_msleep(SLEEP_TIME_MS_RED);
        
    }

    return 0;
}
