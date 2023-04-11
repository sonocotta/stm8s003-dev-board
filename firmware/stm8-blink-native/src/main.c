#ifdef STM8S103F3
#include "STM8S103F3.h"
#endif

#ifdef STM8S003F3
#include "STM8S003F3.h"
#endif

#define LED_PORT sfr_PORTB
#define LED_PIN PIN5

#ifdef LED_TYPE_RGB
// #include "ws2812b_fx.h"
#endif

#define BLINK_DELAY_MS 250

#ifdef LED_TYPE_PLAIN
void toggle_pin()
{
  LED_PORT.ODR.byte ^= LED_PIN;
}
#endif

#ifdef LED_TYPE_RGB
uint8_t isOn = 0;

void toggle_pin()
{
  // isOn = !isOn;
  // ws2812_send_pixel_24bits(0x0f, 0x00, 0x00);
  // ws2812_send_latch();
}
#endif

void main(void)
{
  uint32_t i = 0;

  // switch to 16MHz (default is 2MHz)
  sfr_CLK.CKDIVR.byte = 0x00;

#ifdef LED_TYPE_PLAIN
  // configure LED pin as output
  LED_PORT.DDR.byte = LED_PIN; // input(=0) or output(=1)
  LED_PORT.CR1.byte = LED_PIN; // input: 0=float, 1=pull-up; output: 0=open-drain, 1=push-pull
  LED_PORT.CR2.byte = LED_PIN; // input: 0=no exint, 1=exint; output: 0=2MHz slope, 1=10MHz slope
#endif

#ifdef LED_TYPE_RGB
// ws2812_gpio_config();
#endif

  // UART1_DeInit();
  /* UART1 configuration ------------------------------------------------------*/
  /* UART1 configured as follow:
        - BaudRate = SERIAL_BAUD baud
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Receive and transmit enabled
        - UART1 Clock disabled
  */
  // UART1_Init((uint32_t)SERIAL_BAUD, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
  //            UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

  // /* Output a message on Hyperterminal using printf function */
  // printf("\n\rUART1 Example :retarget the C library printf()/getchar() functions to the UART\n\r");
  // printf("\n\rEnter Text\n\r");

  while (1)
  {
    // printf(".");
    // toggle LED. Pass port struct as pointer
    toggle_pin();

    // simple wait ~500ms @ 16MHz
    for (i = 0; i < 300000L; i++)
      NOP();
  }
}