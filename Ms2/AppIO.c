#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) { 
	printf(aMessage);
}

int AppIO_in_order(void) { 
	int a;
	printf("\n? 마방진 차수를 입력하시오:");
	scanf("%d", &a);
	return a;
}