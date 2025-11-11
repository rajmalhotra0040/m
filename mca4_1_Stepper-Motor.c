// Half Drive Clockwise and Anticlockwise
#include <reg51.h>

void MsDelay(int);

void main() {
    while (1) {
        // Clockwise rotation
        P2 = 0x01;
        MsDelay(5000);
        P2 = 0x03;
        MsDelay(5000);
        P2 = 0x02;
        MsDelay(5000);
        P2 = 0x06;
        MsDelay(5000);
        P2 = 0x04;
        MsDelay(5000);
        P2 = 0x0C;
        MsDelay(5000);
        P2 = 0x08;
        MsDelay(5000);
        P2 = 0x09;
        MsDelay(5000);

        // Anticlockwise rotation
        P2 = 0x09;
        MsDelay(5000);
        P2 = 0x08;
        MsDelay(5000);
        P2 = 0x0C;
        MsDelay(5000);
        P2 = 0x04;
        MsDelay(5000);
        P2 = 0x06;
        MsDelay(5000);
        P2 = 0x02;
        MsDelay(5000);
        P2 = 0x03;
        MsDelay(5000);
        P2 = 0x01;
        MsDelay(5000);
    }
}

void MsDelay(int k) {
    int x, y;
    for (x = 0; x < k; x++)
        for (y = 0; y < 200; y++);
}
