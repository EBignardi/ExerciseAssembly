#include<stdio.h>


int sommalungstringhe(char*, char*);

int main() {
	char str1[255] = "mi vuooi sposare?";
	char str2[255] = "NO grazie";

	printf("la somma delle lunghezze e' %d", sommalungstringhe(str1, str2));

}