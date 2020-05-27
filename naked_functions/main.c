/*

Naked functions

Microsoft Specific:
For functions declared with the naked attribute, the compiler generates code without prolog and epilog code. 
You can use this feature to write your own prolog/epilog code sequences using inline assembler code.

__declspec( naked ) int func( formal_parameters )
	{
		// Function body
	}

*/


__declspec(naked) void swap(int* a, int* b)
{
	__asm{
		push	ebp							// Prolog
		mov		ebp, esp

		push	ebx							// Save ebx value

		mov		eax, dword ptr[ebp + 8]		// Get first parameter, a, (int *) 
		mov		ebx, dword ptr[ebp + 12]	// Get second parameter, b, (int *)

		push	dword ptr[eax]				// swap M[a], M[b]
		push	dword ptr[ebx]
		pop		dword ptr[eax]
		pop		dword ptr[ebx]

		pop		ebx							// restore ebx

		pop		ebp							// Epilog
		ret
	}
}

int op1, op2;


 main()
{
	op1 = 0x10;
	op2 = 0x20;

	swap(&op1, &op2);

}