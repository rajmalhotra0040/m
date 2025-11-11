#include <reg51.h>

void TODelay();

void main(void) {
    while (1) {
        P1 = 0x55;
        TODelay();
        P2 = 0xAA;
        TODelay();
    }
}

void TODelay() {
    TMOD = 0x01;   // Timer0 mode 1 (16-bit timer)
    TH0 = 0x35;    // Load higher byte
    TL0 = 0x00;    // Load lower byte
    TR0 = 1;       // Start timer

    while (TF0 == 0);  // Wait until overflow flag is set

    TR0 = 0;       // Stop timer
    TF0 = 0;       // Clear overflow flag
}

