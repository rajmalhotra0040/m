#include <msp430.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR |= 0x01;
    P2DIR &= ~0x01;

    while (1) {
        if (P2IN & BIT0) {
            P1OUT &= ~0x01;
            __delay_cycles(1000);
        } else {
            P1OUT |= 0x01;
            __delay_cycles(1000);
        }
    }

    return 0;
}
