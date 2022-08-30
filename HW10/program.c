/* 
Yasmin Madani
97532265
*/

#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

signed char a = 0;
int i = 1;

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void) {
    a+=i;
    delay_ms(10);
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void) {
    a-=i;
    delay_ms(10);
}

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void) {
   
    PORTC.3=!PORTC.3;
        
    if(i == 1)
        i = 10;
    else
        i = 1; 
}

// Declare your global variables here

void main(void) {
    char *str;
    PORTC=0x00;
    DDRC=0xFF;

    // External Interrupt(s) initialization
    // INT0: On
    // INT0 Mode: Falling Edge
    // INT1: On
    // INT1 Mode: Falling Edge
    // INT2: On
    // INT2 Mode: Falling Edge
    GICR|=0xE0;
    MCUCR=0x0A;
    MCUCSR=0x00;
    GIFR=0xE0;

    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTC Bit 0
    // RD - PORTC Bit 1
    // EN - PORTC Bit 2
    // D4 - PORTC Bit 4
    // D5 - PORTC Bit 5
    // D6 - PORTC Bit 6
    // D7 - PORTC Bit 7
    // Characters/line: 16

    lcd_init(16);

    // Global enable interrupts
    #asm("sei")

    while (1) {
        lcd_gotoxy(0,0);
        itoa(a,str);                                                                                      
        lcd_puts(str);
        lcd_putchar(' ');
        lcd_putchar(' ');
        delay_ms(50);
    }
}
