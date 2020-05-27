.586
.model flat
.code

; *** External declarations ***

extern _puts:proc
extern _printf:proc

extern _x:dword
extern _y:word
extern _z:byte

; void funzione (const char *s, int i);
_funzione proc
	push	ebp
	mov		ebp,esp

	; Chiamo la funzione puts passandogli la stringa 
	mov		eax,dword ptr [ebp+8]
	push	eax
	call	_puts
	add		esp,4

	; Chiamo la funzione printf passandogli una stringa con il formato e l'intero 
	; (in ordine inverso, come richiesto dalla convenzione cdecl)
	mov		eax,dword ptr [ebp+12]
	push	eax
	mov		eax, offset szFormat	; Notate l'uso di offset per ottenere
									; l'indirizzo di szFormat (come l'operatore
									; & in C). 
									;"The "offset" operator returns the distance of a variable from the beginning of its enclosing segment"
	push	eax
	call	_printf
	add		esp,8

	; Chiamo la funzione printf passandogli le variabili globali
	mov		al,_z
	push	eax
	movsx	eax,_y
	push	eax
	mov		eax,_x
	push	eax
	mov		eax,offset szFormat2
	push	eax
	call	_printf
	add		esp,16
	
	pop		ebp
	ret
_funzione endp

.data
	szFormat	db	'%d',10,0		; Notate che le stringhe in assembly 
									; non hanno il terminatore automatico 
									; e quindi va inserito a mano il 
									; valore 0 alla fine

	szFormat2	db	'%d %d %c',10,0

end