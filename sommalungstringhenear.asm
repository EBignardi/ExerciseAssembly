.586
.model flat
.code

_sommalungstringhe proc
push ebp ; registro che contiene i parametri passati dalla funzione 
mov ebp,esp ; serve per inizializzare il base pointer e fissarlo
push esi
push edi
push ebx



mov ebx, dword ptr [ebp+8] ; ebp+8 perchè a ebp+4 ci sta il registro EIP
call strlung ; chiamo la funzione che mi conta la lunghezza della stringa, input prima stringa 
mov ecx,eax
mov ebx, dword ptr [ebp+12] ; in teoria questa è la seconda stringa, ovvero la seconda ad essere inserita nel registro ebx
call strlung ; chiamo la stessa funzione che mi conta la lunghezza della stringa, con input la seconda stringa
add eax,ecx

pop ebx
pop edi
pop esi
mov esp,ebp
pop ebp
ret



_sommalungstringhe endp ; fine procedura somma lunghezza stringhe


strlung proc
;in ebx c'e' l'indirizzo della stringa
;la lunghezza la metto in eax
;a parte ebx tutti i registri fanno quel cacchio che gli pare
push ebx
mov esi,0
ciclo:
mov al, byte ptr [ebx+esi]
cmp al,0
je fineciclo ;se al=0 sono arrivato alla fine della stringa

inc esi  ;incrementa il registro esi +1
jmp ciclo ;salto allínizio del ciclo e continuo a contare le lettere

fineciclo:

mov eax,esi


pop ebx
ret
strlung endp ; fine procedura lunghezza stringhe

end ; fine del programma