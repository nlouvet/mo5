* Divide A by B, unsigned; return quotient in B, remainder in A.
* Does not preserve X.
* Stack before the call (top to bottom):
* 0,S = 16-bit return value
* 2,S = 8-bit divisor
* 3,S = 8-bit dividend
* Stack after the call (top to bottom):
* 0,S = quotient
* 1,S = remainder
DIV8	PULS Y			; save the return value in Y
		LDA #8			; loop counter
		CLRB            ; remainder will be computed in B
		PSHS B			; reserve a location for the quotient
* Current stack state (top to bottom):
* 0,S = 8-bit quotient
* 1,S = 8-bit divisor
* 2,S = 8-bit dividend
DV8010	LSL	2,S			; shift dividend into carry
		ROLB			; new bit of dividend now in bit 0 of B
		CMPB 1,S		; does the divisor "fit" into B?
		BLO	DV8020		; if not, no subtraction
		SUBB 1,S		; subtract from the remainder
		ORCC #1			; and set carry
		BRA	DV8030		; 
DV8020	ANDCC #$FE		; reset carry
DV8030	ROL ,S			; shift carry into quotient
		DECA			; another bit of the dividend to process?
		BNE	DV8010		; if yes
		; remainder is in B
		; quotient is on top of the stack
		LDA 0,S			; load the quotient
		LEAS 3,S		; restore the stack
		PSHS B
		PSHS A
		PSHS Y			; push the return value
		RTS



