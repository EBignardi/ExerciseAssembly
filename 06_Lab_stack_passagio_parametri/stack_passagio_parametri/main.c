#include <stdio.h>

// Stack usage, PUSH, POP

int		a;
int		b;


main()
{
	a = 0x10;
	b = 0x20;

	__asm{
		mov eax,a
		mov ebx,b

		push	eax		// Swap registers eax,ebx (32 bits)
		push	ebx

		pop		eax
		pop		ebx

		push	ax		// Swap registers ax,bx (16 bits)
		push	bx

		pop		ax
		pop		bx

		push	a 		// Swap variables c, d (memory locations)
		push	b

		pop		a
		pop		b
	}
}