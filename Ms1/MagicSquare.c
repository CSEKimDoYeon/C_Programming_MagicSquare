#include "MagicSquare.h"
#include <stdio.h> // only for sprintf()
typedef struct { // ���� ��ġ�� ��� ���� ��ġ�� ��� �ִ� ��ü.
	int _row;
	int _col;
} CellLocation;
#define EMPTY_CELL -1

Boolean MagicSquare_orderIsValid(int anOrder) { 
	if (anOrder < 3) { // ������ 3���� ���� ��� ���� �޽��� ���.
		AppIO_out("[����] ������ �ʹ� �۽��ϴ�. 3 ���� ũ�ų� ���ƾ� �մϴ�.\n");
		return FALSE;
	}
	else if (anOrder > MAX_ORDER) { // ������ 99���� Ŭ ��� ���� �޽��� ���.
		char messageBuffer[255];
		sprintf(messageBuffer, "[����] ������ �ʹ� Ů�ϴ�. %d ���� �۰ų� ���ƾ� �մϴ�.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((anOrder % 2) == 0) { // ������ ¦�� �� ��� ���� �޽��� ���.
		AppIO_out("[����] ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { // ����ڰ� �Է��� ����, 99x99 ����

	int row, col;
	int currentLoc_row, currentLoc_col;
	int nextLoc_row, nextLoc_col;
	// ���� ��ġ, ���� ��ġ�� index�� �����ϴ� int �� ����.

	int cellValue = 1; // cellValue �� 1���� ����.
	int lastCellValue = anOrder * anOrder; // �ش� �������� �ִ� Value�� ����^2 �̴�.

	for (row = 0; row < anOrder; row++) { // ��� ��� ���� EMPTY_CELL(-1) �� �ʱ�ȭ�Ѵ�.
		for (col = 0; col < anOrder; col++) { 
			aBoard[row][col] = EMPTY_CELL; 
		}
	}

	currentLoc_row = 0;
	currentLoc_col = anOrder / 2; // ���� ������ ������ / 2 ��, �߾Ӻ��� �����Ѵ�.
	aBoard[currentLoc_row][currentLoc_col] = cellValue; // ������ ������ġ�� cellValue�� ä���.

	cellValue = 2; // �������� 1�� �־����Ƿ� cellValue�� 2�� �ʱ�ȭ�Ѵ�.

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		// cellValue��2����(anOrder * anOrder) ����1�������ϸ�����������ݺ�
		// <������ġ>�κ���<������ġ>������Ѵ�;
		nextLoc_row = currentLoc_row - 1;
		if (nextLoc_row < 0)
			nextLoc_row = anOrder - 1;
		nextLoc_col = currentLoc_col + 1;
		if (nextLoc_col >= anOrder)
			nextLoc_col = 0;



		if (aBoard[nextLoc_row][nextLoc_col] != EMPTY_CELL) {
			// <������ġ>��<������ġ>�ǹٷ����پƷ�ĭ��ġ�μ����Ѵ�;
			// <������ġ>�����ο�<������ġ>���Ѵ�;
			// �����ǻ��ο�<������ġ>��cellValue ���ִ´�;
			nextLoc_row = currentLoc_row + 1;
			nextLoc_col = currentLoc_col;
		}
		//currentLoc = nextLoc;
		currentLoc_row = nextLoc_row;
		currentLoc_col = nextLoc_col;
		aBoard[currentLoc_row][currentLoc_col] = cellValue;
	}
}