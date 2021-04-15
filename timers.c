#include <msp430.h>
#include "timers.h"

static const unsigned aux_clock =            0x0100;
static const unsigned up_mode =              0x0010;
static const unsigned timer_interrupt_flag = 0x0001;

void initialize_timer(enum Color color, unsigned interval) {
    switch(color) {
        case red:
            TA0CCR0 = interval;
            TA0CTL = aux_clock | up_mode;
            break;
        case green:
            TA1CCR0 = interval;
            TA1CTL = aux_clock | up_mode;
            break;
    }
}

unsigned is_timer_expired(enum Color color) {
    unsigned int retval = 0;
    switch(color) {
    case red:
        retval = TA0CTL & timer_interrupt_flag != 0;
        break;
    case green:
        retval = TA1CTL & timer_interrupt_flag != 0;
        break;
    }
    return retval;
}

void reset_timer(enum Color color)  {
    switch(color) {
    case red:
        TA0CTL &= ~timer_interrupt_flag;
        break;
    case green:
        TA1CTL &= ~timer_interrupt_flag;
        break;
    }

}
