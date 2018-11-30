#include "MagicSquare.h"
#include <stdio.h> // only for sprintf()
typedef struct {
	int _row;
	int _col;
} CellLocation;
#define EMPTY_CELL -1

Boolean MagicSquare_orderIsValid(int anOrder) { 
	if (anOrder < 3) {
		AppIO_out("[����] ������ �ʹ� �۽��ϴ�. 3 ���� ũ�ų� ���ƾ� �մϴ�.\n");
		return FALSE;
	}
	else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[����] ������ �ʹ� Ů�ϴ�. %d ���� �۰ų� ���ƾ� �մϴ�.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((anOrder % 2) == 0) {
		AppIO_out("[����] ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { // ����ڰ� �Է��� ����, 99x99 ����
	CellLocation currentLoc; // ���� ��ġ�� �����ϴ� ��ü ����.
	CellLocation nextLoc; // ���� ��ġ�� �����ϴ� ��ü ����.

	int row, col; // ��� ���� index
	int cellValue = 1; // �ʱⰪ 1
	int lastCellValue = anOrder * anOrder; // ����� �ִ밪�� ����^2 �̴�.

	for (row = 0; row < anOrder; row++) { // ��� ����� Value�� EMPTY_CELL �� �ʱ�ȭ�Ѵ�.
		for (col = 0; col < anOrder; col++) { 
			aBoard[row][col] = EMPTY_CELL; 
		}
	}

	currentLoc._row = 0; // ���� 0 ���� ����.
	currentLoc._col = anOrder / 2; // ���� anOrder / 2 ��, �߾Ӻ��� �����Ѵ�.
	aBoard[currentLoc._row][currentLoc._col] = cellValue; // ������ ������ġ�� cellValue�� ä���.

	cellValue = 2; // 1�� ä������ cellValue�� 2�� �ʱ�ȭ�Ѵ�.

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		// cellValue��2����(anOrder * anOrder) ����1�������ϸ�����������ݺ�
		// <������ġ>�κ���<������ġ>������Ѵ�;
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0)
			nextLoc._row = anOrder - 1;
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= anOrder)
			nextLoc._col = 0;



		if (aBoard[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			// <������ġ>��<������ġ>�ǹٷ����پƷ�ĭ��ġ�μ����Ѵ�;
			// <������ġ>�����ο�<������ġ>���Ѵ�;
			// �����ǻ��ο�<������ġ>��cellValue ���ִ´�;
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		currentLoc = nextLoc;
		aBoard[currentLoc._row][currentLoc._col] = cellValue;
	}
}