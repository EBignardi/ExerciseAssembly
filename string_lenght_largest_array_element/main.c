#include <stdio.h>

char string[] = "Stringa";
char *pt_str;
int str_lenght;

#define N 7
int data[] = { 10, 20, 1, 0, -1, 100, 20 };
int *pt_data;
int maxval;

main()
{

	// *** String lenght ***

	pt_str = string;

	__asm{
		mov esi, 0					// esi = array index / string lenght
		mov edi, pt_str				// edi = String start address

	ck_next :
		cmp byte ptr[edi][esi*1], 0	// look for string terminator character (Null terminated string)
		je	end_loop				// 
		inc esi						// increment character index 
		jmp ck_next					// check next character

	end_loop:
		mov str_lenght,esi			// store string length
	}

	printf("\nLunghezza stringa \"%s\" : %d caratteri", string, str_lenght);

	// **********************************************************************************


	// *** Find the largest value in a 10 element data array

	pt_data = data;
	/*
	index = 1;
	maxval = data[0];
	do{
		if(data[index] > maxval) maxval=data[index];
		index++;
	}while(index<N);
	*/

	__asm{
		mov esi,1						// esi = index
		mov edi, pt_data				// edi = data array start address
		mov eax,dword ptr[edi]			// eax = maxval = data[0]
	cont:								// do{
		cmp dword ptr[edi+esi*4],eax	//		if(data[index] <= maxval) goto skip 
		jle skip						//
		mov eax,dword ptr[edi+esi*4]	//		maxval = data[index]
	skip:								//	  skip:
		inc esi							//		index++
		cmp esi,N						// }while(index < N);
		jl	cont						//
		mov maxval, eax					// Store largest element in to maxval
	}

	printf("\n\nValore massino: %d ", maxval);

	// **********************************************************************************
}