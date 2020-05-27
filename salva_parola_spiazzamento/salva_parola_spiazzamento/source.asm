.386
.model flat
.code
;
; 
;
; Algoritmo in pseudocodice
;
; int salvaparolaspiazzamento (char *s, char *d, unsigned char* parola1)
;
; *** USED subroutines (at the end of this file): SEARCH, STRLEN, STRCPY ***
; ------------------------------------------------------------------------------
; src = s
; dst = d
;
; riempire d con blank;
;
; len = strlen(parola1);
; if(len < 4) return(-2);		// parola1's length is less than 4 characters
;
; while(1){
;	pos = search(src,parola1);	
;	if(pos == -1){
;		if(src==s)	return(-1); //  parola1 doesn't occur in s
;		else		return(0);	//  parola1 occurs one or more times in s
;	}
;	else{
;		src += len + pos;
;		dst += pos;
;		strcpy(parola1, dst)
;		dst += len;
;	}
; }
;
; ------------------------------------------------------------------------------


;int salvaparolaspiazzamento (char *s, char *d, unsigned char* parola1)

_salvaparolaspiazzamento proc
	push	ebp
	mov		ebp,esp
									; save regs
	push	ebx						;
	push	ecx						;
	push	edi						;
	push	esi						;
;
	mov		esi, dword ptr[ebp+8]	; src = s
	mov		edi, dword ptr[ebp+12]	; dst = d
;
									; fill d string with spaces:
	mov		ebx,esi					;   eax = strlen(ebx=d)
	call	strlen					;	
									;   build string d
	mov		byte ptr[edi+eax],0		;   add NULL at the end of the d string, termination
	dec		eax						;
blfill:								;
	mov		byte ptr[edi+eax],' '	;   fill with blank
	dec		eax						;
	jge		blfill					;
									; if(strlen(parola1) < 4) return(-2)
	mov		ebx, dword ptr[ebp+16]	;   *parola1
	call	strlen					;
	mov		ecx,eax					;	save strlen in to ecx							
	cmp		eax,4					;
	jge		cerca					;
	mov		eax,-2					;
	jmp		fine					;
									;
cerca:								; while(1){
	call	search					;	pos (stored in to eax) = search(src,parola1);
	cmp		eax, -1					;	if(pos == -1){
	jne		trovata					;	
	cmp		esi,dword ptr[ebp+8]	;		if(src==s)	return(-1);
	je		fine					;	
	mov		eax,0					;		else		return(0);
	jmp		fine					;	}
trovata:							;	else{
	add		esi,eax					;		src += len + pos;
	add		esi,ecx					;
	add		edi,eax					;		dst += len + pos;
	call	strcpy					;		strcpy(parola1, dst);
	add		edi,ecx					;		dst += len;
	jmp		cerca					;	}
									; }
fine:
	pop		esi						;	restore regs
	pop		edi						;
	pop		ecx						;
	pop		ebx						;

	mov		esp,ebp					;
	pop		ebp						;
	ret								;
_salvaparolaspiazzamento endp



search proc
; *********************************
; 
; 	search
; 		Search for dst string in to src string,
; 		returns the position of the first match. 
; 
; 		input	esi, src string pointer; string to search in;
; 				ebx, dst string pointer; string to look for;
; 		output	eax, position of the first occurrence of dst in src; -1 if no match is found;
; 					 
; *********************************
; ---------------------------------
;
; i = 0, j = 0
; while(1){
;	if (src[j] == NULL)		return(-1);	 // No match is found
;	if (dst[i] == NULL)		return(j-i); // Match found, return match position of dst string in to src string
;	if (src[j] == dst[i])	i++;
;	else					i = 0;
;	j++;
; }		
;
; --------------------------------
	push	ecx					;
	push	edx					;
;
	mov		eax,0				; j = 0, index of source string
	mov		edx,0				; i = 0, index of destination string
;
ripeti:							; while(1) {
	mov	ch, byte ptr[ebx+edx]	;	if (dst[i] == NULL) return(i-j);
	cmp ch,0					;
	jne	riparti					; 
;
	sub	eax,edx	; j <-(j-i)		;
	pop	edx						;
	pop	ecx						;
	ret							;
;
riparti:
	mov	cl, byte ptr[esi+eax]	;	if (src[j] == NULL) return(-1);
	cmp cl,0					;
	jne	compare					;
	mov eax,-1		;return(-1)	; 
	pop	edx						;
	pop	ecx						;
	ret							;
;
compare:
;
	cmp cl,ch					;	if (src[j] == dst[i])	i++;
	jne	notrov					;	else					i = 0;
								;	j++
	inc edx			; i++		;
	inc eax			; j++		; 
	jmp	ripeti					; }
;
notrov:
	inc eax			; j++		; 
	cmp	edx,0					;
	je riparti					;
	mov edx,0		; i = 0		;
	jmp	ripeti					;
;
search endp


strcpy proc
; *********************************
; 
; 	strcpy: copy src string to dst 
;			(Null is not copyed)
; 	input  ebx = *src, edi = *dst 
; 
; *********************************
	push	ecx						;
	push	eax						;
;
	mov		eax,0					;
inizio:
	mov		cl,byte ptr[ebx+eax]	;
	cmp		cl,0					;
	je		fine					;
	mov		byte ptr[edi+eax], cl	;
	inc		eax						;
	jmp		inizio					;
fine:
	pop		eax						;
	pop		ecx						;
	ret								;
;
strcpy endp
;----------------------------------



strlen proc
; *********************************
; 	strlen 
; 		input ebx = string pointer
; 		output eax str length
; *********************************
	mov	eax,0
inizio:
	cmp	byte ptr[ebx+eax],0
	je	fine
	inc	eax
	jmp	inizio
fine:
	ret
;
strlen endp


end