#include <reg51.h>

sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay();

void main() {
    P2 = 0x00;
    
    while (1) {
        lcdcmd(0x38);
        delay();
        lcdcmd(0x14);
        delay();
        lcdcmd(0x0E);
        delay();
        lcdcmd(0x01);
        delay();
        lcdcmd(0x06);
        delay();
        lcdcmd(0x81);
        delay();

        lcddata('A');
        delay();
        lcddata('V');
        delay();
        lcddata('C');
        delay();
        lcddata('O');
        delay();
        lcddata('E');
        delay();
    }
}

void lcdcmd(unsigned char val) {
    P2 = val;
    rs = 0;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void lcddata(unsigned char val) {
    P2 = val;
    rs = 1;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void delay() {
    unsigned int i;
    for (i = 0; i < 6000; i++);
}
