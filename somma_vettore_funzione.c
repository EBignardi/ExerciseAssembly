#include <stdio.h>

__declspec(naked) int sommavettore(int* a, int lunghezza)
{
	__asm {
		push ebp
		mov ebp, esp
		push ebx
		push edi
		push esi


		mov ebx, dword ptr [ebp+8] //indirizzo primo elemento vettore a
		mov esi,0
		mov eax,0

	ciclo:
		cmp esi,dword ptr[ebp+12]
		je fine_ciclo

		add eax, dword ptr [ebx+esi*4]
		
		
		inc esi
		jmp ciclo

	fine_ciclo:




		pop esi
		pop edi
		pop ebx
		mov esp,ebp
		pop ebp
		ret

	}
}

__declspec(naked) int somma(int a, int b)
{
	__asm {
	push ebp //salvo EBP del chiamante
	mov ebp,esp // setto barriera
	sub esp,4 //alloco una variabile locale che trovero' in [ebp-4]
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
	int a, b, c,d;
	int vett[5] = { 1,2,3,4,5 };
	c = 0;
	d = 0;
	a = 10;
	b = 20;
	c = somma(a, b);
	d = sommavettore(vett, 5);
	printf("somma elementi = %d e somma vettore = %d", c,d);


}