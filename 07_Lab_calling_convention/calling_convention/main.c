#include <stdio.h>

//	Calling convention cdecl: 
//		In cdecl, subroutine arguments are passed on the stack. Integer values and memory addresses are returned 
//		in the EAX register

//		Compile and debug the code
//
int ret;

int func(int a){	
					// One parameter function

	return a;		// Return parameter
}

int addition(int a, int b)
{					// Two parameters function
	return a + b;	// return parameters addition
}

int addition_localvar(int a, int b){
	int c;			// Dinamic local variable
	c = a + b;
	return c;
}

main(){

	ret = func(0x20);

	ret = addition(0x20, 0x10);

	ret = addition(0x20, 0x10);

	ret = addition_localvar(0x20, 0x10);

}