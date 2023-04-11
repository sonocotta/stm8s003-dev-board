#include "ws2812_driver.h"


void ws2812_gpio_config()
{
    // PORT(WS2812_PORT, DDR) |= (1 << WS2812_PIN_POS); // WS2812_pin is output
    // PORT(WS2812_PORT, CR1) |= (1 << WS2812_PIN_POS); // Push-pull mode  
    // PORT(WS2812_PORT, CR2) |= (1 << WS2812_PIN_POS); // High speed (10MHz)
    // PORT(WS2812_PORT, ODR) &= ~(1 << WS2812_PIN_POS); // Low (as ws2812 looks for logic high)
    WS2812_LED_PORT.DDR.byte = WS2812_LED_PIN; // input(=0) or output(=1)
    WS2812_LED_PORT.CR1.byte = WS2812_LED_PIN; // input: 0=float, 1=pull-up; output: 0=open-drain, 1=push-pull
    WS2812_LED_PORT.CR2.byte = WS2812_LED_PIN; // input: 0=no exint, 1=exint; output: 0=2MHz slope, 1=10MHz slope
    WS2812_LED_PORT.ODR.byte &= ~(WS2812_LED_PIN);
}

#ifndef USE_INLINE_FUNC
void ws2812_send_8bits(uint8_t d)
{
    /*
    *  Note: It'll only work if clock is 16MHz
    *  Timing is NOT as per official ws2812 datasheet, rather from practical experiments:
    *  https://wp.josh.com/2014/05/13/ws2812-neopixels-are-not-so-finicky-once-you-get-to-know-them/
    *  https://gist.github.com/TG9541/1761fa86b425a0c909b7bd1cc8017c2b
    * 
    *  In a nutshell, 
    *  Symbol       Description             Min.    Typ.    Max     Unit
    *  ------------------------------------------------------------------
    *  T0H      0 code, high voltage time	200	    350	    500	    ns
    *  T1H      1 code, high voltage time	550	    700	    5,500	ns
    *  TLD      data, low voltage time	    450	    600	    5,000	ns
    *  TLL      latch, low voltage time	    6,000	--		--      ns
    * 
    *  Imp: Some new WS2812B and WS2813 chips require a minimum 250,000ns latch time
    */


   uint8_t mask = 0x80;
   uint8_t masked_val = d & mask;
    while (mask) 
    {
        if (masked_val) 
        {
            /*
            * Bit: 1
            * High time:  590ns
            * Low time:   670ns
            * Cycle time: 1260ns
            */

            // Set pin high
            __asm__("bset " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bset 0x5007, #5")

            // Delay for 590ns (due to nop time + mask calculation time)
            nop(); nop(); nop(); 
            mask >>= 1;
            masked_val = d & mask;


            // Set pin low
            __asm__("bres " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bres 0x5007, #5")

            // Delay 670ns due to while() and if() time

        } 
        else 
        {
            /*
            * Bit: 0
            * High time:  470ns
            * Low time:   730ns
            * Cycle time: 1250ns
            */

            // Set pin high
            __asm__("bset " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bset 0x5007, #5")

            // Delay for 470ns (due to nop time + mask calculation time)
            nop();// earlier 0 nops worked fine (390ns), addng one for testing
            mask >>= 1;
            masked_val = d & mask;

            // Set pin low
            __asm__("bres " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bres 0x5007, #5")

            // Delay for 730ns (while() and if() time) (weird! why not 670ns like above?)
        }
    }
}


void ws2812_send_pixel_24bits(uint8_t r, uint8_t g, uint8_t b)
{
    disableInterrupts();
    #ifdef COLOR_RGB
        ws2812_send_8bits(r);
        ws2812_send_8bits(g);
    #else
        ws2812_send_8bits(g);
        ws2812_send_8bits(r);
    #endif 
    ws2812_send_8bits(b);
    enableInterrupts();
}


#endif

void ws2812_send_latch()
{
    __asm__("bres " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS));

    // Delay approx 67.80us
    for(uint16_t wait = 0; wait < 130; wait++);
}

