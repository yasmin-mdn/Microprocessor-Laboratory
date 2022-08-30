 /*
 Yasmin Madani
 97532265
 */
#include <mega32.h>
#include <delay.h>

    unsigned char CODE[]= {       
    0xFC,    //    0001        # # # # # # . . 
    0x92,    //    0002        # . . # . . # . 
    0x92,    //    0003        # . . # . . # . 
    0x92,    //    0004        # . . # . . # . 
    0xFC ,    //    0005        # # # # # # . . 
    0x80,     //    0005        # . . . . . . . 
    0x80,     //    0005        # . . . . . . .  
    0x80,     //    0005        # . . . . . . .  
    0x80,    //    0001        # . . . . . . . 
    0x80,    //    0002        # . . . . . . .  
    0xFE,    //    0001        # # # # # # # . 
    0xC0,    //    0002        # # . . . . . . 
    0xC0,    //    0003        # # . . . . . . 
    0xC0,    //    0004        # # . . . . . . 
    0x80,     //    0005        # . . . . . . . 
    0x80,     //    0005        # . . . . . . .  
    0x80,     //    0005        # . . . . . . .  
    0x80,    //    0001        # . . . . . . . 
    0x80,    //    0002        # . . . . . . . 
    0xFE,    //    0003        # # # # # # # . 
    0x80 ,    //    0005        # . . . . . . . 
    0x80,     //    0005        # . . . . . . .  
    0x80, 	 //	0005		   # . . . . . . .  
    0x80,	//	0001		   # . . . . . . . 
	0x80,	//	0002		   # . . . . . . .  
    };
   


void main(){	 

unsigned char PORT[16] = {1, 2, 4, 8, 16, 32, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int s, col, timer;

unsigned char Col,Scan,Refresh,Index,S;
DDRC=0xFF;
DDRD=0xFF;

while (1)
      {
      // Place your code here
      for (S=0; S<10; S++)
      {
        for (Refresh=1; Refresh<11; Refresh++)
        {
            Scan = 0b00000001;
            for (Col=0; Col<5; Col++)
            {
                Index = S + Col;
                PORTD = CODE[Index];
                PORTC = Scan;
                delay_ms(4);
                Scan = Scan << 1;
                PORTC = 0x00;
            }
        }
      }
      }
}
