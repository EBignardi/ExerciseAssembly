.586
.model flat
.code

_primo proc
push ebp
mov ebp,esp
push ebx
push esi
push edi

mov eax, dword ptr [ebp+8]
mov esi,eax
dec esi
ciclo:
cmp esi,1
je fineciclo
mov eax, dword ptr [ebp+8]
mov edx,0 ;
div esi ;
cmp edx,0
jne prosegui
mov eax,0
jmp finetutto
prosegui:
dec esi
jmp ciclo

fineciclo:
mov eax,1

finetutto:

pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp
ret

_primo endp

end