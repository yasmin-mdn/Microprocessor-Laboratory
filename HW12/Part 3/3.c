/* Az-12 MICLAB Part3
   Danial Bazmandeh
   97521135
*/

#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include "Includes/GLCD.h"

void main(void) {
    int i = 64;
    int j = 32;

    DATADDR = 0xff;
    DDRB = 0xFF;
    
    glcd_on();
    glcd_clear();

    while(1) {        
        while(i < 93) {
            circle(i, j, 3, 0, 1);
            i++;
            j++;
            delay_ms(100);
            glcd_clear(); 
        } 
        
        while(i < 125) {
            circle(i, j, 3, 0, 1);
            i++;
            j--;
            delay_ms(100);
            glcd_clear(); 
        } 
        
        while(i > 100) {
            circle(i, j, 3, 0, 1);
            i--;
            j--;
            delay_ms(100);
            glcd_clear(); 
        } 
        
        while(i > 70) {
            circle(i,j,3,0,1);
            i--;
            j++;
            delay_ms(100);
            glcd_clear(); 
        } 
        
        i = 64;
        j = 32;
    }
}
