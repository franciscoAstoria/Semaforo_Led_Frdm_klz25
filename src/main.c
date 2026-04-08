#include <zephyr.h>             // Funções básicas do Zephyr (ex: k_msleep)
#include <device.h>             // API para obter e usar dispositivos
#include <drivers/gpio.h>       // API para controle de GPIO
#define LED_PORT       "GPIO_1" // Nome do controlador GPIO (label no .pio\build\frdm_kl25z\zephyr\zephyr.dts)
#define LED_PIN_RED        18   // Pino PTB18 onde está o LED vermelho
#define LED_PIN_GRE        19    // Pino PTB18 onde está o LED verde
#define SLEEP_TIME_MS_RED  5000
#define SLEEP_TIME_MS_YEL  1000 
#define SLEEP_TIME_MS_GRE  3000   // Intervalo de piscar (milissegundos)

void main(void)
{    struct device *port = device_get_binding(LED_PORT);
    // Obtém ponteiro para o controlador GPIO “GPIO_1”
    // (não é feito a cada iteração para economizar chamadas)
    gpio_pin_configure(port, LED_PIN_RED , GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure(port, LED_PIN_GRE, GPIO_OUTPUT_ACTIVE);
    // Configura o pino como saída ativa (LED apagado ou aceso depende de pull)
    gpio_pin_toggle(port, LED_PIN_RED);
    while (1) {
        k_msleep(SLEEP_TIME_MS_RED);

        gpio_pin_toggle(port, LED_PIN_RED);
        gpio_pin_toggle(port, LED_PIN_GRE);
        k_msleep(SLEEP_TIME_MS_GRE);

        gpio_pin_toggle(port, LED_PIN_RED);
        k_msleep(SLEEP_TIME_MS_YEL);
        gpio_pin_toggle(port, LED_PIN_GRE);
    }
}