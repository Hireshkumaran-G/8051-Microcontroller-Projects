#include <reg51.h>
sbit BUZZER = P1^0;  
void delay(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<1275;j++);
}

void beep(unsigned int count)
{
    unsigned int i;
    for(i=0;i<count;i++)
    {
        BUZZER = 1;
        delay(5);
        BUZZER = 0;
        delay(5);
    }
}

void main()
{
    while(1)
    {
        beep(50);  
        delay(500);
        beep(100); 
        delay(500); 
    }
}
