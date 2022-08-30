/*
Yasmin Madani
97532265
*/
#include <mega32.h>
#include <stdlib.h>
#include <string.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
unsigned int milisecond = 0;
char str_ms[];
unsigned int second = 0;
char str_s[];
unsigned int minute = 58;
char str_m[];
unsigned int hour = 23;
char str_h[];


interrupt [TIM1_COMPA] void timer1_compa_isr(void) {
    milisecond += 1;
    
      
    if(hour == 24) {
        lcd_gotoxy(3,1);
        lcd_puts("  ");
        hour=0;
    }   
    
    if (minute == 60) {
        lcd_gotoxy(6,1);
        lcd_puts("  ");
        minute=0;  
        hour++;
    }
    
    if (second == 60) {
        lcd_gotoxy(9,1);
        lcd_puts("  ");
        second = 0; 
        minute++;
    }
    
    if (milisecond == 10) {
        milisecond = 0;   
        second++;
    }   

    itoa(milisecond, str_ms);
    lcd_gotoxy(12,1);
    lcd_puts(str_ms);

    itoa(second, str_s);
    lcd_gotoxy(9,1);
    lcd_puts(str_s);

    itoa(minute, str_m);
    lcd_gotoxy(6,1);
    lcd_puts(str_m);
       
    itoa(hour, str_h);
    lcd_gotoxy(3,1);
    lcd_puts(str_h); 
}
// Declare your global variables here

void main(void)
{
// Declare your local variables here
    DDRC=0xFF; 
    PORTC=0x00;

    TCCR1A=0x00;
    TCCR1B=0x0C;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x0C;
    OCR1AL=0x35;
    OCR1BH=0x00;
    OCR1BL=0x00;

    TIMSK=0x10;  

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

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
    #asm("sei")
    lcd_init(16);
    lcd_clear();

    lcd_gotoxy(3,0);
    lcd_puts("LCD CLOCK");

    lcd_gotoxy(11,1);
    lcd_puts(":");
    lcd_gotoxy(5,1);
    lcd_puts(":");
    lcd_gotoxy(8,1);
    lcd_puts(":");

while (1)
      {
      // Place your code here

      }
}
