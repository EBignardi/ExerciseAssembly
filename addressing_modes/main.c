#include <stdio.h>

char c;
char *ptr_ch;

int a;
int  *ptr_int_a;

int b;
int *ptr_int_b;

__int64 d;
__int64 *ptr_int64;

char buff[] = { 1, 2, 3, 4 };
char *bpt;

int  buff1[] = { 0x11111111, 0x22222222, 0x33333333, 0x44444444 };
int *bpt1;
int i;

main()
{	
	c = 0x10;				// dst direct, src immediate
	ptr_ch = &c;			// dst direct, src immediate

	a = 0x12345678;			// dst direct, src immediate
	ptr_int_a = &a;			// dst direct, src immediate

	b = 0xabcdef01;			// dst direct, src immediate
	ptr_int_b = &b;

	d = 0x12345678abcdef01;	// dst direct, src immediate
	ptr_int64 = &d;			// dst direct, src immediate

	bpt = buff;
	bpt1 = buff1;
	__asm
	{				// Read variable and their addresses
		mov al, c						// dst: register, src direct
		mov	ebx, ptr_ch					// dst: register, src direct

		mov ecx, a						// dst register, src direct
		mov edx, ptr_int_a				// dst register, src direct

		mov edi, b						//
		mov esi, ptr_int_b				//
										// c = 0x20;
		mov byte ptr[ebx], 0x20			// dst indirect, src immadiate

										// a = 0xaa55aa55;
		mov dword ptr[edx],0xaa55aa55	// dst indirect, src immadiate

										// b = a;
		mov eax, dword ptr[edx]			// dst register, src indirect
		mov dword ptr[esi], eax			// dst indirect, src register

		mov edi, bpt					// dst register, src direct
		mov eax, bpt1					// dst register, src direct
		mov esi, 0						// dst register, src immediate

										// buff[0]=0; 
		mov byte ptr[edi+esi*1], 0		// dst based scaled indexed, src immediate

										// buff1[0]=0
		mov dword ptr[eax+esi*4], 0		// dst based scaled indexed, src immediate

		inc esi							// dst register

										// buff[1]=0
		mov byte ptr[edi+esi*1], 0		// dst based scaled indexed, src immediate

										// buff1[1]=0
		mov dword ptr[eax+esi*4], 0		// dst based scaled indexed, src immediate

	
	}
	printf("\n\nch = %x", c);
	printf("\n\n a = %x", a);
	printf("\n\n a = %x", b);
	for (i = 0; i < 4; i++) printf("\nbuff[%d] = %x", i, buff[i]);
	printf("\n");
	for (i = 0; i < 4; i++) printf("\nbuff1[%d]= %x", i, buff1[i]);

}