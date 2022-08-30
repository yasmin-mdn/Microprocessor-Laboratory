;Yasmin Madani
;Student Number : 97532265
;sunday class 3 - 4.30
;///////////////////////////////////////////////////////
.include "m32def.inc"
.ORG	0
		RJMP	Here
.ORG	OC1Aaddr
		RJMP	OC1_Routine

Here:	
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0xFF
		OUT		DDRC,R16		;PORTC output
		OUT		DDRD,R16		;PORTD output
		OUT		DDRB, R16		;PORTB output
		OUT		PORTA,R16		;Enabling Pullup Resistor on PORTA 


		LDI		R16,0x00
		OUT		DDRA,R16		;PORTA input		
	

; R23=the leftmost number  R22=second numer from left  R21=third number from left  R20=the rightmost number
Start:	
		IN		R16,PINA
		CPI 	R16,0
		BREQ 	CountDecreasing
		
		LDI		R20,0			
		LDI		R21,0			
		LDI		R22,0			
		LDI     R23,0			
		LDI     R24,0

		LDI		R26,1			
		LDI		R27,0x0A
		LDI		R28,0
		
		RJMP	TIMER


CountDecreasing:
		LDI		R20,9			
		LDI		R21,9			
		LDI		R22,9			
		LDI     R23,9			
		
		LDI		R26,-1
		LDI		R27,-1
		LDI		R28,9
		
		RJMP	TIMER

TIMER:	;initial Timer	
		LDI		R25, 0X00
		OUT		TCCR1A, R25
		
		LDI		R25, 0X0C
		OUT		TCCR1B, R25
		LDI		R25, HIGH(31250)
		OUT		OCR1AH, R25
		
		LDI		R25, LOW(31250)
		OUT		OCR1AL, R25
		
		LDI		R25, 0X12
		OUT		TIMSK, R25
		
		SEI


DISPLAY1 : 	;Display Number
		LDI		R16,0b1110	
		OUT		PORTD,R16
		MOV		R16,R23
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b1101	
		OUT		PORTD,R16
		MOV		R16,R22
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		

		LDI		R16,0b1011	
		OUT		PORTD,R16
		MOV		R16,R21
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b0111	
		OUT		PORTD,R16
		MOV		R16,R20
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		
		IN		R16,PINA	
		CPI 	R16,0
		BREQ 	SETVAL
		
		LDI		R26,1			
		LDI		R27,0x0A
		LDI		R28,0
		
		RJMP	DISPLAY1


SETVAL :
		LDI		R26,-1
		LDI		R27,-1
		LDI		R28,9
		RJMP	DISPLAY1


OC1_Routine:
		
		Add  R20, R26
		CP   R20 ,R27
		BRNE DISPLAY2
		
		MOV  R20,R28
		Add  R21, R26
		CP   R21 ,R27
		BRNE DISPLAY2
		
		MOV  R21,R28
		Add  R22, R26
		CP   R22 ,R27
		BRNE DISPLAY2
		
		MOV  R22,R28
		Add  R23, R26
		CP   R23 ,R27
		BRNE DISPLAY2
		
		MOV  R23,R28


DISPLAY2 :  
		RETI


CONVERT:				
		CPI		R16,0
		BRNE	C1
		LDI		R16,0x3F
		RET
C1:		CPI		R16,1
		BRNE	C2
		LDI		R16,0x06
		RET
C2:		CPI		R16,2
		BRNE	C3
		LDI		R16,0x5B
		RET
C3:		CPI		R16,3
		BRNE	C4
		LDI		R16,0x4F
		RET
C4:		CPI		R16,4
		BRNE	C5
		LDI		R16,0x66
		RET
C5:		CPI		R16,5
		BRNE	C6
		LDI		R16,0x6D
		RET
C6:		CPI		R16,6
		BRNE	C7
		LDI		R16,0x7D
		RET
C7:		CPI		R16,7
		BRNE	C8
		LDI		R16,0x07
		RET
C8:		CPI		R16,8
		BRNE	C9
		LDI		R16,0x7F
		RET
C9:		CPI		R16,9
		BRNE	C10
		LDI		R16,0x6F
C10:	RET
					


DELAY:	LDI		R17,0x01
Loop1:	LDI		R18,0xFF
Loop2:	LDI		R19,0xA0
Loop3:	DEC		R19
		BRNE	Loop3
		DEC		R18
		BRNE	Loop2
		DEC		R17
		BRNE	Loop1
		RET

