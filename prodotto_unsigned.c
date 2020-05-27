int main()
{

	unsigned int a, b, c;
	a = 5;
	b = 10;

	__asm
	{
		mov eax,a
		mov ebx,b
		mov esi,0
		mov ecx,0 //prodotto
	condizione:
		cmp esi,ebx
		je fineciclo
		add ecx,eax


		inc esi
		jmp condizione
	fineciclo:
		mov c,ecx

	}


	printf("il prodotto di a con b e' %d", c);
}