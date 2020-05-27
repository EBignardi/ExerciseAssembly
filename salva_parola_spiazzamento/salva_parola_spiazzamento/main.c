#include <stdio.h>

int salvaparolaspiazzamento(char *s, char *d, unsigned char* parola1);

main(void)
{
	int ret;
	char s[255] = "campa la campa la capra campa";
	char d[255];
	char parola1[50] = "campa";

	ret=salvaparolaspiazzamento(s, d, parola1);
	printf("%d\n",ret);
	printf("%s\n", s);
	printf("%s", d);
}