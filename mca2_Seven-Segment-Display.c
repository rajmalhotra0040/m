#include <reg51.h>

void delay();

void main() {
    unsigned char i;
    unsigned char arr[] = {0x11, 0xD7, 0x82, 0xD4, 0x89, 0x18, 0xDB, 0x10, 0x90, 0x56};
    
    P1 = 0x00;
    P0 = 0x00;

    while (1) {
        for (i = 0; i < 10; i++) {
            P1 = 0xFF;
            P0 = arr[i];
            delay();
        }
    }
}

void delay() {
    unsigned int a, b;
    for (a = 0; a < 1000; a++)
        for (b = 0; b < 1000; b++);
}
