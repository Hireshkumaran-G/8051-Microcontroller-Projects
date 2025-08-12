#include <reg51.h>
#include <string.h>

#define LCD_PORT P2
sbit RS = P0^0;
sbit EN = P0^2;

sbit r1 = P3^0;
sbit r2 = P3^1;
sbit r3 = P3^2;
sbit r4 = P3^3;
sbit c1 = P3^4;
sbit c2 = P3^5;
sbit c3 = P3^6;

void delay(int a) {
    int i, j;
    for (i = 0; i < a; i++)
        for (j = 0; j < 250; j++);
}

void cmd(unsigned char cmd) {
    LCD_PORT = cmd;
    RS = 0;
    EN = 1;
    delay(2);
    EN = 0;
}

void dat(unsigned char dat) {
    LCD_PORT = dat;
    RS = 1;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_init() {
    cmd(0x38);
    cmd(0x0e);
    cmd(0x01);
    cmd(0x06);
    cmd(0x0c);
    cmd(0x80);
}

void show(unsigned char *str) {
    while (*str) {
        dat(*str++);
    }
}

char get_key() {
    r1 = r2 = r3 = r4 = 1;

    // Row 1
    r1 = 0; r2 = r3 = r4 = 1;
    if (c1 == 0) { delay(50); while(c1==0); return '1'; }
    if (c2 == 0) { delay(50); while(c2==0); return '2'; }
    if (c3 == 0) { delay(50); while(c3==0); return '3'; }

    // Row 2
    r2 = 0; r1 = r3 = r4 = 1;
    if (c1 == 0) { delay(50); while(c1==0); return '4'; }
    if (c2 == 0) { delay(50); while(c2==0); return '5'; }
    if (c3 == 0) { delay(50); while(c3==0); return '6'; }

    // Row 3
    r3 = 0; r1 = r2 = r4 = 1;
    if (c1 == 0) { delay(50); while(c1==0); return '7'; }
    if (c2 == 0) { delay(50); while(c2==0); return '8'; }
    if (c3 == 0) { delay(50); while(c3==0); return '9'; }

    // Row 4
    r4 = 0; r1 = r2 = r3 = 1;
    if (c2 == 0) { delay(50); while(c2==0); return '0'; }

    return 0;
}

void main() {
    char key;
    char pswd[] = "1234";   
    char input[5];          
    unsigned char i;

    lcd_init();
    show("Enter Code:");

    while (1) {
        for (i = 0; i < 4; ) {
            key = get_key();
            if (key) {  // Store only if a key is pressed
                input[i] = key;
                dat('*'); // print star instead of key
                i++;
            }
        }

        input[4] = '\0'; // Null-terminate string

        cmd(0x01); // Clear display
        if (strcmp(input, pswd) == 0) {
            show("HELLO");
        } else {
            show("WRONG CODE");
        }

        delay(200);
        cmd(0x01);
        show("Enter Code:");
    }
}
