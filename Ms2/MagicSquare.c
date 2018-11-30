#include "MagicSquare.h"
#include <stdio.h> // only for sprintf()
typedef struct {
	int _row;
	int _col;
} CellLocation;
#define EMPTY_CELL -1

Boolean MagicSquare_orderIsValid(int anOrder) { 
	if (anOrder < 3) {
		AppIO_out("[오류] 차수가 너무 작습니다. 3 보다 크거나 같아야 합니다.\n");
		return FALSE;
	}
	else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf(messageBuffer, "[오류] 차수가 너무 큽니다. %d 보다 작거나 같아야 합니다.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((anOrder % 2) == 0) {
		AppIO_out("[오류] 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { // 사용자가 입력한 차수, 99x99 보드
	CellLocation currentLoc; // 현재 위치를 저장하는 객체 선언.
	CellLocation nextLoc; // 다음 위치를 저장하는 객체 선언.

	int row, col; // 행과 열의 index
	int cellValue = 1; // 초기값 1
	int lastCellValue = anOrder * anOrder; // 행렬의 최대값은 차수^2 이다.

	for (row = 0; row < anOrder; row++) { // 모든 행렬의 Value를 EMPTY_CELL 로 초기화한다.
		for (col = 0; col < anOrder; col++) { 
			aBoard[row][col] = EMPTY_CELL; 
		}
	}

	currentLoc._row = 0; // 행은 0 부터 시작.
	currentLoc._col = anOrder / 2; // 열은 anOrder / 2 즉, 중앙부터 시작한다.
	aBoard[currentLoc._row][currentLoc._col] = cellValue; // 보드의 현재위치에 cellValue를 채운다.

	cellValue = 2; // 1을 채웠으니 cellValue를 2로 초기화한다.

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		// cellValue가2부터(anOrder * anOrder) 까지1씩증가하며다음내용을반복
		// <현재위치>로부터<다음위치>를계산한다;
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0)
			nextLoc._row = anOrder - 1;
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= anOrder)
			nextLoc._col = 0;



		if (aBoard[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			// <다음위치>를<현재위치>의바로한줄아래칸위치로수정한다;
			// <다음위치>를새로운<현재위치>로한다;
			// 보드의새로운<현재위치>에cellValue 를넣는다;
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		currentLoc = nextLoc;
		aBoard[currentLoc._row][currentLoc._col] = cellValue;
	}
}