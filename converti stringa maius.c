#include <stdio.h>

int main()
{
	char str[255] = "";
	char * c;
	c = &str[0];
	
	__asm
	{
	mov ebx,c
	mov esi,0
	mov al, byte ptr [ebx+esi]
	sub al,32
	mov byte ptr[ebx+esi],al
	
	
	
	
	}
	printf("%s");

}