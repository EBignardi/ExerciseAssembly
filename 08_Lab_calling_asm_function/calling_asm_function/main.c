#include <stdio.h>

	//
	// c = a + b
	//
	// situazione dello stack
	//
	// --------------
	// |	  C		| <- esp
	// --------------
	// |     ebp	| <- ebp
	// --------------
	// |     EIP	|
	// --------------
	// |      a		|
	// --------------
	// |      b		|
	// --------------
	// |			|
	// --------------
	//
int somma(int a, int b){
	int c;
	__asm{
		mov eax,	[ebp + 8]	//	eax <-- a, Get parameter a;
		add eax,	[ebp + 12]	//	eax <-- eax + b, eax <-- a + b;
		mov [ebp-4],eax			//	c <-- eax 
	}
	return c;
}
void main(){
	int a, b, c;
	a = 10;
	b = 13;
	c = somma(a, b);
	printf("%d \n", c);
}