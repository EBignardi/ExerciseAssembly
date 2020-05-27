#include <stdio.h>


__declspec(naked) int somma(int a, int b)
{
	__asm {
	push ebp //salvo EBP del chiamante
	mov ebp,esp // setto barriera
	sub esp,4 //alloco unavariabile locale che trovero' in [ebp-4]
	//salvo i registri da ripristinare sullo stack
	push ebx
	push esi
	push edi


	//inizia codice
	mov eax, dword ptr [ebp+8] //primo parametro
	add eax, dword ptr [ebp+12]



	//ripristino i registri
	pop edi
	pop esi
	pop ebx
	mov esp,ebp //pulisco lo stack
	pop ebp //recupero EBP del chiamante 

	ret

	
	}

}


int main()
{
	int a, b, c;
	c = 0;
	a = 10;
	b = 20;
	c = somma(a, b);
	printf("%d", c);


}