#include <msp430.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR |= 0x40; //0x08;

    while (1) {
        volatile unsigned long i;
        P1OUT ^= 0x40; //0x08;
        i = 50000;
        do {
            i--;
        } while (i != 0);
    }

    return 0;
}
