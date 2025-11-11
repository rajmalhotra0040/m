#include <msp430g2553.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer
    ADC10CTL0 = ADC10ON + SREF_0 + ADC10SHT_2; // Turn on ADC, use V+ and V-, 16x sample time
    ADC10CTL1 = INCH_3;                       // Input channel A3
    ADC10AE0 |= 0x08;                         // Enable analog input on P1.3
    P1DIR |= BIT6;                            // P1.6 output
    P1SEL |= BIT6;                            // P1.6 TA0.1 option
    TA0CTL = TASSEL_2 + ID_3 + MC_1 + TAIE;   // SMCLK/8, Up mode, interrupt enabled
    TA0CCTL1 = OUTMOD_7;                      // Reset/Set output mode
    TA0CCR0 = 1024;                           // PWM period
    TA0CCR1 = 1;                              // Initial duty cycle
    _bis_SR_register(GIE);                    // Enable interrupts
    while (1);
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void timer(void)
{
    ADC10CTL0 |= ENC + ADC10SC;               // Start ADC conversion
    TA0CCR1 = ADC10MEM;                       // Set PWM duty according to ADC value
}
