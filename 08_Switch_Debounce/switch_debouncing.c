#include <reg51.h>

sbit LED = P1^1;   
sbit SW  = P1^0;

void delay(unsigned int ms)
{
    unsigned int i, j;
    for(i=0;i<ms;i++)
        for(j=0;j<1275;j++);
}

void main()
{
    LED = 0;
    while(1)
    {
        if(SW == 0) 
        {
            delay(20);  
            if(SW == 0) 
            {
                LED = ~LED;  
                while(SW == 0);  
            }
        }
    }
}
