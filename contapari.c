#include <stdio.h>

__declspec(naked) int contapari(int * vett, int lunghezza)
{
	__asm
	{
	push ebp
	mov ebp,esp

	push esi
	push edi
	push ebx

	mov ebx, dword ptr [ebp+8]

	mov esi,0

	mov edi,0

	mov ecx,2

	iniziociclo:
	cmp esi, dword ptr [ebp+12]
	je fineciclo

	mov eax,dword ptr [ebx+esi*4]
	cdq
	idiv ecx
	
	cmp edx,0
	jne non_conto
	inc edi

	non_conto:

	inc esi
	jmp iniziociclo
	fineciclo:

	mov eax,edi


	pop ebx
	pop edi
	pop esi

	mov esp,ebp

	pop ebp
	ret
	
	}


}


main()
{
	int a[10] = { 1,2,3,4,-1,-2,-3,-4,-5,5 };
	

	printf("numero di numeri pari è %d", contapari(a, 10));


}