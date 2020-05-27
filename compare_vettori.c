#include <stdio.h>

int main()
{

	unsigned int v1[5] = { 1,2,3,4,5 };
	unsigned int v2[5] = { 0,0,0,0,0 };
	int i;
	unsigned int *pv1;
	unsigned int *pv2;

	pv1 = &v1[0];
	pv2 = &v2[0];
	__asm {
	mov ebx,pv1
	mov ecx, pv2
	mov esi,0

	condizione:
	cmp esi,5
	je fine_ciclo
	
	mov eax, dword ptr [ebx+esi*4]
	cmp eax,3
	jbe non_fare_niente
	mov edx,1
	mov dword ptr [ecx+esi*4], edx
	non_fare_niente:

	inc esi
	jmp condizione

	fine_ciclo:

	
	}




	for (i = 0; i < 5; i++)
	{
		printf("%d ", v2[i]);
	}
	getchar();

}