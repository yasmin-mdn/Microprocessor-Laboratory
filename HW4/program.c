/*
Yasmin Madani
97532265
*/
#include <mega32.h>
#include <delay.h>

// Declare your global variables here
unsigned int hour_1   = 3;
unsigned int hour_2   = 2;
unsigned int minute_1 = 8;
unsigned int minute_2 = 5;
unsigned int second_1 = 0;
unsigned int second_2 = 0;

char dot = 0x80;

unsigned int counter = 0; 

char number[] = { 0x3F, 0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F };

// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
   counter++;
    if (counter == 6) 
        counter=0;
}


// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    dot = 0x00;
    second_1+=1;
    if (second_1%2 == 0)
        dot = 0x80;
            
    if(second_1==10){     
        second_2+=1;
        second_1=0;
        if(second_2==6){   
            minute_1+=1;
            second_2=0;
            if (minute_1==10){
                minute_2+=1;  
                minute_1=0;      
                if (minute_2==6){   
                    hour_1+=1;
                    minute_2=0;      
                    if (hour_1==10 && hour_2 == 0 ){        
                        hour_2+=1;
                        hour_1=0;
                    }
                    if (hour_1==4 && hour_2 == 2 ){
                        hour_1=0;      
                        hour_2=0;
                    }
                }
            }
       } 
    }
}


void main(void){
    // Declare your local variables here
    // Input/Output Ports initialization
    // Port A initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
    PORTA=0x00;
    DDRA=0x00;

    // Port B initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
    PORTB=0x00;
    DDRB=0x00;

    // Port C initialization
    // Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
    // State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
    PORTC=0x00;
    DDRC=0xFF;

    // Port D initialization
    // Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
    // State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
    PORTD=0x00;
    DDRD=0xFF;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: 7.813 kHz
    // Mode: CTC top=OCR0
    // OC0 output: Disconnected
    TCCR0=0x0C;
    TCNT0=0x00;
    OCR0=0x63;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 31.250 kHz
    // Mode: CTC top=OCR1A
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: On
    // Compare B Match Interrupt: Off
    TCCR1A=0x00;
    TCCR1B=0x0C;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x7A;
    OCR1AL=0x12;
    OCR1BH=0x00;
    OCR1BL=0x00;

    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: Timer2 Stopped
    // Mode: Normal top=FFh
    // OC2 output: Disconnected
    ASSR=0x00;
    TCCR2=0x00;
    TCNT2=0x00;
    OCR2=0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: Off
    // INT2: Off
    MCUCR=0x00;
    MCUCSR=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=0x12;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // Global enable interrupts
    #asm("sei")

    while (1){
          if(counter == 0){ 
            PORTD = 0b11111110;
            PORTC = number[hour_2];  
          }
            
          else if(counter == 1){  
            PORTD = 0b11111101;
            PORTC = number[hour_1]| dot;   
          } 
          
          else if(counter == 2) {   
            PORTD = 0b11111011;
            PORTC = number[minute_2];    
          } 
          
          else if(counter == 3){ 
            PORTD = 0b11110111;
            PORTC = number[minute_1]| dot; 
          }  
          
          else if(counter == 4) {
            PORTD = 0b11101111;
            PORTC = number[second_2];     
          }    
          
          else if(counter == 5){  
            PORTD = 0b11011111;
            PORTC = number[second_1] | dot;     
          }
    }
}