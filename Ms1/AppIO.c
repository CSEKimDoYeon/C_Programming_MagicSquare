#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) { // char 형으로 받은 메지시를 출력하는 함수.
	printf(aMessage);
}

int AppIO_in_order(void) {  // 사용자로부터 마방진의 차수를 입력받는 함수.
	int a;
	printf("\n? 마방진 차수를 입력하시오:");
	scanf("%d", &a);
	return a;
}