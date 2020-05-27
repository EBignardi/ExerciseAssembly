#include <stdio.h>

int main()
{
	int a = 0;
	int b[5] = { 1,2,3,4,5 };
	int *c;

	c = &b[0];

	__asm {
	mov ebx,c // in ebx c'e' l'indirizzo del b
	mov eax, dword ptr [ebx]
	mov esi,3
	add eax, dword ptr [ebx+esi*4]
	mov ecx,eax





	mov a,ecx //ecx ci sara' la somma
	}




	printf("la somma del primo e quarto elemento del vettore è %d", a);



}