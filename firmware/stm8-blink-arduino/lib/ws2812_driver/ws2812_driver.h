#ifndef _WS2812_DRIVER_H
#define _WS2812_DRIVER_H

#include <stdint.h>
#include <stm8s.h>

/**the inline send() functions have better timing and both 1 and 0 has cycle time of 1250ns
 * but they take a lot of space. Comment out unless perfect timing is required
 */
//#define USE_INLINE_FUNC

// To use GRB color (for ws2812), comment it out. Uncomment it for RGB color (ws2811)
//#define COLOR_RGB

// #define CONCAT(a, b)    a##_##b
// #define PORT(a, b)      CONCAT(a , b)

#define STR(x) #x
#define XSTR(s) STR(s)

#define WS2812_LED_PORT sfr_PORTB
#define WS2812_LED_PIN  PIN5

// #define WS2812_PORT                 PB
// #define WS2812_PIN_POS              5
// #define WS2812_ODR_ADDR             sfr_PORTB

void ws2812_gpio_config();
void ws2812_send_latch();
#ifndef USE_INLINE_FUNC
void ws2812_send_8bits(uint8_t d);
void ws2812_send_pixel_24bits(uint8_t r, uint8_t g, uint8_t b);
#endif


#ifdef USE_INLINE_FUNC
void static inline ws2812_send_8bits(uint8_t d)
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
            * High time:  585ns
            * Low time:   665ns
            * Cycle time: 1250ns
            */

            // Set pin high
            __asm__("bset " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bset 0x5007, #5")

            // Delay for 585ns (due to nop time + mask calculation time)
            nop(); nop(); nop(); nop(); nop();nop();nop();
            mask >>= 1;
            masked_val = d & mask;


            // Set pin low
            __asm__("bres " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bres 0x5007, #5")
            
            // Delay 665ns due to nop time + while() and if() time
            nop();
            

        } 
        else 
        {
            /*
            * Bit: 0
            * High time:  335ns
            * Low time:   915ns
            * Cycle time: 1250ns
            */

            // Set pin high
            __asm__("bset " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bset 0x5007, #5")

            // Delay for 335 (due to nop time + mask calculation time)
            nop(); nop(); nop();
            mask >>= 1;
            masked_val = d & mask;

            // Set pin low
            __asm__("bres " XSTR(WS2812_ODR_ADDR) ", #" XSTR(WS2812_PIN_POS)); // __asm__("bres 0x5007, #5")
            
            // Delay for 915ns (nop time + while() and if() time)
            nop(); nop(); nop(); nop(); nop();
            
        }
    }
}

void static inline ws2812_send_pixel_24bits(uint8_t r, uint8_t g, uint8_t b)
{
    #ifdef COLOR_RGB
        ws2812_send_8bits(r);
        ws2812_send_8bits(g);
    #else
        ws2812_send_8bits(g);
        ws2812_send_8bits(r);
    #endif
    ws2812_send_8bits(b);
}

#endif


#endif