#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) { // char ������ ���� �����ø� ����ϴ� �Լ�.
	printf(aMessage);
}

int AppIO_in_order(void) {  // ����ڷκ��� �������� ������ �Է¹޴� �Լ�.
	int a;
	printf("\n? ������ ������ �Է��Ͻÿ�:");
	scanf("%d", &a);
	return a;
}