.586
.model flat
.code


; int numeri_primi (unsigned char * src, unsigned char* dst, int size);

_numeri_primi proc
;
	push	ebp
	mov		ebp,esp
;
	push	ecx						; Save used regisers
	push	ebx
	push	esi
	push	edi
	push	edx
;
	mov		esi,dword ptr[ebp+8]	; *src
	mov		edi,dword ptr[ebp+12]	; *dst
;				dword ptr[ebp+16]	; size
	mov		ecx,0					; ecx (nprimi) is used as prime numbers'counter		
	mov		edx,0					; edx (i) is used to index the src array
;
continua:
	cmp		edx,dword ptr[ebp+16]	; while(i<size) {
	jge		fine					;		dst[i] = 0
	mov		bl, byte ptr[esi+edx]	;		if(src[i] == primo) {
	call	numero_primo			;			nprimi++
	mov		byte ptr[edi+edx],0		;			dst[i] = 1
	cmp		eax,0					;		}
	je		skip					;		else
	inc		ecx						;			dst[i] = 0
	mov		byte ptr[edi+edx],1		;		i++
skip:								;
	inc		edx						;
	jmp		continua				; }
fine:
;
	mov		eax,ecx					; eax = nprimi
	cmp		ecx,0					;
	jne		some_primi				; if (nprimi == 0)
	mov		eax,-2					;		eax = -2
some_primi:
	cmp		ecx,dword ptr[ebp+16]	; if (nprimi == size)
	jne		some_primi1				;		eax = -3
	mov		eax,-3					; 
some_primi1:
;
	pop		edx						; Restore registers
	pop		edi						;
	pop		esi						;
	pop		ebx						;
	pop		ecx						;
;
	mov		esp,ebp
	pop		ebp
	ret
;
_numeri_primi endp




; ***********************************************
;	numero_primo
;		check whether num is prime
;	input:
;		bl = num
;	output:
;		eax  = 0 when num is not prime
;		eax != 0 when num is prime
;
; ***********************************************
;
numero_primo proc
;
	push	ebp
	mov		ebp,esp
	push	ecx		; Save ecx
					; bl = num
					; ecx = 2 .. ebx-1
	mov		ecx,2	; cl = divisor =2
	mov		eax,100h; set bh != 0
	 
nuovo:				;	divisor = 2;
	cmp		cl,bl	;	while(divisor < num){
	jae		exit	;	
	mov		al,bl	;		reminder = num % divisor;	// al = dividend low byte, num
	mov		ah,0	;		if (reminder == 0) break;	// ah = 0 dividend high byte
	div		cl		;		reminder ++;				// al = quotient, ah = remainder
	cmp		ah,0	;	}								// remainder == 0 --> not prime
	je		exit	; 
	inc		cl		;
	jmp		nuovo	;
;
exit:
	mov		al,0	;
;					 num is prime	--> eax != 0
;				     num not prime	--> eax  = 0
;
	pop		ecx		; Restore ecx
	mov		esp,ebp
	pop		ebp
	ret
;
numero_primo endp




end