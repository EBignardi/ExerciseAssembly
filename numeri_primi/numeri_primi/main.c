#include <stdio.h>
int numeri_primi(unsigned char * src, unsigned char* dst, int size);
int main()
{
	unsigned char src[3] = { 1,2, 255 };
	unsigned char dst[3];
	int ret;
	ret = numeri_primi(src, dst, 3);
	printf("risultato = %d\n", ret);
}