#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) { //inputOrder, board
	char messageBuffer[255];
	sprintf(messageBuffer, "> Magic Square Board: Order %2d\n", anOrder); // �Է¹��� ���� ���.
	AppIO_out(messageBuffer);
	AppIO_out("    "); // ��ĭ4 ��
	for (int col = 0; col < anOrder; col++) { // �Է¹��� �������� 0���� ���.
		sprintf(messageBuffer, "[%2d] ", col);
		AppIO_out(messageBuffer);
	}
	AppIO_out("\n");
	for (int row = 0; row < anOrder; row++) { // ���带 �ʱ�ȭ �ϴ� ����.
		printf("[%2d] ", row); // ������ ���� ���
		for (int col = 0; col < anOrder; col++) {
			printf("%4d", aBoard[row][col]); // �ش� ��� ���� �ִ� ���� ���.
		}
		AppIO_out("\n");
	}
}

int main(void) {
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppIO_out("<<< ������Ǯ�̸������մϴ�>>>\n");
	inputOrder = AppIO_in_order(); // �������������Է¹޾�inputOrder ������
	while (inputOrder != END_OF_RUN) { // ������-1 �̸����α׷�����
		if (MagicSquare_orderIsValid(inputOrder)) { // ��������ȿ�����˻�
			MagicSquare_solve(inputOrder, board); // ����ڰ� �Է��� ����, 99x99 ����
			// �־��������Ǹ���������´�
			Main_showBoard(inputOrder, board); // ��������ȭ�鿡�����ش�
		}
		inputOrder = AppIO_in_order(); // �������������Է¹޾�inputOrder ������
	}
	AppIO_out("\n<<< ������Ǯ�̸������մϴ�>>>\n");
	system("pause");
	return 0;
} // end of main()