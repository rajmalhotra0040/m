#include <msp430.h>
int a[5] = {0, 32, 64, 128, 255};
int i = 0;
void main(void) {
WDTCTL = WDTPW | WDTHOLD;
P1DIR |= BIT6;
P2SEL |= BIT6;
TA0CCR0 = 512;
TA0CCR1 = a[0];
TA0CCTL1 = OUTMOD_7;
TA0CTL = TASSEL_2 + MC_1 + TAIE + ID_3;
_bis_SR_register(LPM0_bits + GIE);
while(1);
}
#pragma vector = TIMER0_A1_VECTOR
__interrupt void timer(void) {
TA0CTL &= ~TAIFG;
TA0CCR1 = a[++i];
if(i > 4)
i = 0;
}
