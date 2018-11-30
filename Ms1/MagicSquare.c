#include "MagicSquare.h"
#include <stdio.h> // only for sprintf()
typedef struct { // 현재 위치의 행과 열의 위치를 담고 있는 객체.
	int _row;
	int _col;
} CellLocation;
#define EMPTY_CELL -1

Boolean MagicSquare_orderIsValid(int anOrder) { 
	if (anOrder < 3) { // 차수가 3보다 작을 경우 에러 메시지 출력.
		AppIO_out("[오류] 차수가 너무 작습니다. 3 보다 크거나 같아야 합니다.\n");
		return FALSE;
	}
	else if (anOrder > MAX_ORDER) { // 차수가 99보다 클 경우 에러 메시지 출력.
		char messageBuffer[255];
		sprintf(messageBuffer, "[오류] 차수가 너무 큽니다. %d 보다 작거나 같아야 합니다.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((anOrder % 2) == 0) { // 차수가 짝수 일 경우 에러 메시지 출력.
		AppIO_out("[오류] 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { // 사용자가 입력한 차수, 99x99 보드

	int row, col;
	int currentLoc_row, currentLoc_col;
	int nextLoc_row, nextLoc_col;
	// 현재 위치, 다음 위치의 index를 저장하는 int 형 변수.

	int cellValue = 1; // cellValue 는 1부터 시작.
	int lastCellValue = anOrder * anOrder; // 해당 마방진의 최대 Value는 차수^2 이다.

	for (row = 0; row < anOrder; row++) { // 모든 행과 열을 EMPTY_CELL(-1) 로 초기화한다.
		for (col = 0; col < anOrder; col++) { 
			aBoard[row][col] = EMPTY_CELL; 
		}
	}

	currentLoc_row = 0;
	currentLoc_col = anOrder / 2; // 열의 시작은 차수의 / 2 즉, 중앙부터 시작한다.
	aBoard[currentLoc_row][currentLoc_col] = cellValue; // 보드의 현재위치에 cellValue를 채운다.

	cellValue = 2; // 시작점에 1을 넣었으므로 cellValue를 2로 초기화한다.

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		// cellValue가2부터(anOrder * anOrder) 까지1씩증가하며다음내용을반복
		// <현재위치>로부터<다음위치>를계산한다;
		nextLoc_row = currentLoc_row - 1;
		if (nextLoc_row < 0)
			nextLoc_row = anOrder - 1;
		nextLoc_col = currentLoc_col + 1;
		if (nextLoc_col >= anOrder)
			nextLoc_col = 0;



		if (aBoard[nextLoc_row][nextLoc_col] != EMPTY_CELL) {
			// <다음위치>를<현재위치>의바로한줄아래칸위치로수정한다;
			// <다음위치>를새로운<현재위치>로한다;
			// 보드의새로운<현재위치>에cellValue 를넣는다;
			nextLoc_row = currentLoc_row + 1;
			nextLoc_col = currentLoc_col;
		}
		//currentLoc = nextLoc;
		currentLoc_row = nextLoc_row;
		currentLoc_col = nextLoc_col;
		aBoard[currentLoc_row][currentLoc_col] = cellValue;
	}
}