.386									; This is the assembler directive which tells the assembler to use the 386 instruction set
.model flat								; This specifies the memory model of your program. flat is the model for Windows programs, there is no distinction between 'far' 
										; and 'near' pointers.


.code									; This is the starting point for the program code. 


; int find_max(int data*, int dim);

_find_max proc
;
	push	ebp
	mov		ebp,esp

	push	ebx							; save registers
	push	edx
	push	esi

	mov		edi, dword ptr[ebp+8]		; int* data, edi = data array start address
	mov		ebx, dword ptr[ebp+12]		; int  dim,	 ebx = array lenght

	mov		esi,1						; esi = index
	mov		eax,dword ptr[edi]			; eax = maxval = data[0]
cont:									; do{
	cmp		dword ptr[edi+esi*4],eax	;		if(data[index] <= maxval) goto skip 
	jle		skip						;
	mov		eax,dword ptr[edi+esi*4]	;		maxval = data[index]
skip:									;	skip:
	inc		esi							;		index++
	cmp		esi,ebx						; }while(index < N);
	jl		cont						;
										; largest element left in to eax
;
	pop		esi							; restore registers
	pop		edx
	pop		ebx

	pop		ebp
	ret
;
_find_max endp


end
