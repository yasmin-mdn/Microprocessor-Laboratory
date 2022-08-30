/* Az-12 MICLAB Part1
   Danial Bazmandeh
   97521135
*/

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include "Includes/GLCD.h"

void main(void) {
    unsigned char name[] = "Yasmin Madani";  
    unsigned char stuNumber[] = "97532265";  
    
    DATADDR = 0xff;
    DDRB = 0xFF;
    
    glcd_on();
    glcd_clear();

    while(1) {   
        glcd_puts(name, 0, 0, 0, 1, 0);
        glcd_puts(stuNumber, 0, 1, 0, 1, 0);
        delay_ms(1000);
        glcd_clear(); 
    }
}
