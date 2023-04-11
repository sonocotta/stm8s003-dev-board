#include <Arduino.h>

#ifdef LED_TYPE_RGB
// #include "ws2812_driver.h"
#endif

#define BLINK_DELAY_MS 250

void setup()
{
  Serial_begin(SERIAL_BAUD);
  delay(1000);
  Serial_print_s("Started at ");
  Serial_print_u(F_CPU);
  Serial_print_s(" Hz\n");

  #ifdef LED_TYPE_PLAIN
  pinMode(LED_BUILTIN, OUTPUT);
  #endif

  #ifdef LED_TYPE_RGB
  // ws2812_gpio_config();
  #endif
}

void loop()
{
  Serial_print_s(".");

  #ifdef LED_TYPE_PLAIN
  digitalWrite(LED_BUILTIN, HIGH);
  #endif

  delay(BLINK_DELAY_MS);

  #ifdef LED_TYPE_PLAIN
  digitalWrite(LED_BUILTIN, LOW);
  #endif

  delay(BLINK_DELAY_MS);
}