#include <msp430.h> 
#include "colors.h"
#include "timers.h"
#include "leds.h"

void setup(unsigned timer0_interval, unsigned timer1_interval);
void setup_board(void);

static const unsigned red_interval =  50000;
static const unsigned green_interval = 5000;

int main(void)
{
    setup(red_interval, green_interval);

	while(1) {
	    if(is_timer_expired(red)) {
	        toggle_led(red);
	        reset_timer(red);
	    }
	    if(is_timer_expired(green)) {
	        toggle_led(green);
	        reset_timer(green);
	    }
	}

}

void setup(unsigned red_interval, unsigned green_interval) {
        setup_board();
        initialize_timer(red, red_interval);
        initialize_timer(green, green_interval);
        initialize_leds();
}

void setup_board(void) {
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 = 0xFFFE;  //enable pin io
}



