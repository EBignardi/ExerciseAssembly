int main()
{

	int a, b, c;
	a = -5;
	b = -10;

	__asm
	{
		mov eax,a
		mov ebx,b
		mov edx,1 //segno

		cmp eax,0
		jg controlla_ebx
		neg eax
		cmp ebx,0
		jl finito_1
		mov edx,-1
		jmp finito

	controlla_ebx:
		cmp ebx,0
		jg finito
		neg ebx
		mov edx, -1
		jmp finito

	finito_1:
			neg ebx

	finito:

		mov esi,0
		mov ecx,0 //prodotto
	condizione:
		cmp esi,ebx
		je fineciclo
		add ecx,eax
		inc esi
		jmp condizione
	fineciclo:

		cmp edx,0
		jg fine
		neg ecx

		fine:
		mov c,ecx

	}


	printf("il prodotto di a con b e' %d", c);
}