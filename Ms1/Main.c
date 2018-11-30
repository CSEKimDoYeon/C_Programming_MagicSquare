#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { //inputOrder, board
	char messageBuffer[255];
	sprintf(messageBuffer, "> Magic Square Board: Order %2d\n", anOrder); // 입력받은 차수 출력.
	AppIO_out(messageBuffer);
	AppIO_out("    "); // 빈칸4 개
	for (int col = 0; col < anOrder; col++) { // 입력받은 차수까지 0부터 출력.
		sprintf(messageBuffer, "[%2d] ", col);
		AppIO_out(messageBuffer);
	}
	AppIO_out("\n");
	for (int row = 0; row < anOrder; row++) { // 보드를 초기화 하는 과정.
		printf("[%2d] ", row); // 보드의 열을 출력
		for (int col = 0; col < anOrder; col++) {
			printf("%4d", aBoard[row][col]); // 해당 행과 열에 있는 수를 출력.
		}
		AppIO_out("\n");
	}
}

int main(void) {
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppIO_out("<<< 마방진풀이를시작합니다>>>\n");
	inputOrder = AppIO_in_order(); // 마방진차수를입력받아inputOrder 에저장
	while (inputOrder != END_OF_RUN) { // 차수가-1 이면프로그램종료
		if (MagicSquare_orderIsValid(inputOrder)) { // 차수가유효한지검사
			MagicSquare_solve(inputOrder, board); // 사용자가 입력한 차수, 99x99 보드
			// 주어진차수의마방진을얻는다
			Main_showBoard(inputOrder, board); // 마방진을화면에보여준다
		}
		inputOrder = AppIO_in_order(); // 마방진차수를입력받아inputOrder 에저장
	}
	AppIO_out("\n<<< 마방진풀이를종료합니다>>>\n");
	system("pause");
	return 0;
} // end of main()