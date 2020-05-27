/*
- Unsigned multiply mul -

mul r/m8	;	16bit =  8bit X  8bit,		AX	<-- Al  * r/m8
mul r/m16	;	32bit = 16bit X 16bit,	 DX:AX	<-- AX  * r/m16
mul r/m32	;	64bit = 32bit X 32bit, EDX:EAX	<-- EAX * r/m32

Flags Affected
The OF and CF flags are set to 0 if the upper half of the result is 0; otherwise, they
are set to 1. The SF, ZF, AF, and PF flags are undefined.


- Signed multiply imul -

imul r/m8	;	16bit =  8bit X  8bit,		AX <-- Al  * r/m8
imul r/m16	;	32bit = 16bit X 16bit,	 DX:AX <-- AX  * r/m16
imul r/m32	;	64bit = 32bit X 32bit, EDX:EAX <-- EAX * r/m32

Flags Affected
The CF and OF flags are set when significant bits are carried into the upper half of the
result and cleared when the result fits exactly in the lower half of the result.


- Unsigned divide div -

div r/m8	;	 8bit = 16bit/ 8bit,	AL	<-- AX Div r/m8,			AH	<-- Resto
div r/m16	;	16bit = 32bit/16bit,	AX	<-- DX:AX Div r/m16,		DX	<-- Resto
div r/m32	;	32bit = 64bit/32bit,	EAX	<-- EDX:EAX Div r/m32,		EDX	<-- Resto


Overflow is indicated with the #DE (divide error) exception (divided by zero cause similar results).



- Signed divide idiv -

Signed integers must be sign-extended before division takes place:
fill high byte/word/doubleword with a copy of the low byte/word/doubleword's sign bit.

- CBW (convert byte to word) extends AL into AH
– CWD (convert word to doubleword) extends AX into DX
– CDQ (convert doubleword to quadword) extends EAX into EDX

idiv r/m8	;	 8bit = 16bit/ 8bit,	AL	<-- AX Div r/m8,			AH	<-- Resto
idiv r/m16	;	16bit = 32bit/16bit,	AX	<-- DX:AX Div r/m16,		DX	<-- Resto
idiv r/m32	;	32bit = 64bit/32bit,	EAX	<-- EDX:EAX Div r/m32,		EDX	<-- Resto


Overflow is indicated with the #DE (divide error) exception rather than with the CF flag.
*/

/* ********************************************************
	scrivere le seguenti funzioni

		int fatt(int num);
			Calcola e ritorna il fattoriale di num.

		int media(int * dati, int dim); 
			Calcola la media degli elementi di un vettore di interi.
			int * dati: puntatore all'area di memoria contenente i dati;
			int dim:	dimensione del vettore


* ********************************************************/



__declspec(naked) int media(int * dati, int dim)
{
	__asm{
						// Prolog	
			ret			// Epilog
	}
}

__declspec(naked) int fatt(int num)
{
	__asm{
									// Prolog
									// Epilog
			ret
	}
}





main()
{


}