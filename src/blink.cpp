#ifdef __cplusplus
extern "C" {
#endif
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#ifdef __cplusplus
}
#endif

#define LED_PORT GPIOC
#define RCC_LED_PORT RCC_GPIOC
#define LED_PIN GPIO13

int main() {
  rcc_periph_clock_enable(RCC_LED_PORT);
  gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);

  gpio_set(LED_PORT, LED_PIN);

  while(1) {
    /* wait a little bit */
    for (int i = 0; i < 800000; i++) {
      __asm__("nop");
    }
    gpio_toggle(LED_PORT, LED_PIN);
  
  }
}
