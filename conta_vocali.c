#include <stdio.h>

int main()
{
	char v[255] = "la nonna di tua nonna e un pokemon";
	char* pv;
	int vocali = 0;
	pv = &v[0];
	__asm {
	mov ebx,pv

	mov esi,0
	mov ecx,0

	condizione:
	mov al, byte ptr [ebx+esi*1]
	cmp al,0 
	je finestringa

	cmp al,'a'
		je incremento
	cmp al, 'e'
		je incremento
	cmp al, 'i'
		je incremento
	cmp al, 'o'
		je incremento
	cmp al, 'u'
		je incremento

	jmp non_incremento
	
	incremento:
	inc ecx

	non_incremento 
	inc esi
	jmp condizione
	finestringa:


	mov vocali,ecx
	}



	printf("il numero di vocali è %d", vocali);

}