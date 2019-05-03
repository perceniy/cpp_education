/*
 *  Homework 4
 *
 *  Created on: Mar 3, 2019
 *  Author: arseniy
 */


/*
 * Требуется обойти конём шахматную доску размером NxM,
 * пройдя через все поля доски по одному разу.
 * Здесь алгоритм решения такой же как и в задаче о 8 ферзях.
 * Разница только в проверке положения коня.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* board
 *   M ► ► ► ►
 * N
 * ▼
 * ▼
 * ▼
 * ▼
 */

#define N 15
#define M 15

struct stBoard {
	short cells[N][M];
	short maxStep;
};

struct stMove {
	short dN;
	short dM;
};

struct stOrder {
	short Capacity;
	short moveNum;
};

typedef struct stBoard myBoard;
typedef struct stMove myMove;
typedef struct stOrder myOrder;

/*Функция печати массива*/
void printBoard(myBoard board) {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%4d ", board.cells[i][j]);
		}
		printf("\n");
	}
}

/*Проверка того, что можем ходить на данную ячейку
 * 1 - можем ходить
 * 0 - уже были, или выход за границу */

int checkCell(myBoard board, int xN, int xM){
	if ((xN < N)&(xM < M)&(xN >= 0)&(xM >= 0)) {
		if (board.cells[xN][xM] == 0){return 1;} else {return 0;}
	} else {return 0;}
}

void bubbleSort(myOrder a[8])
{
int array_size = 8;
int i, j;
myOrder temp;
for (i = 0; i < (array_size - 1); ++i)
{
     for (j = 0; j < array_size - 1 - i; ++j )
     {
          if (a[j].Capacity > a[j+1].Capacity)
          {
               temp = a[j+1];
               a[j+1] = a[j];
               a[j] = temp;
          }
     }
}
}

int VarnsdorfRule(myBoard board, int n, int  m) {
/*передаем вайнсдорфу текущие координаты
 *для каждого возможного хода считаем число доступных ходов с нового поля*/
	myMove movies[8];
	movies[0].dN =  1; movies[0].dM =  2;
	movies[1].dN =  1; movies[1].dM = -2;
	movies[2].dN = -1; movies[2].dM =  2;
	movies[3].dN = -1; movies[3].dM = -2;
	movies[4].dN =  2; movies[4].dM =  1;
	movies[5].dN =  2; movies[5].dM = -1;
	movies[6].dN = -2; movies[6].dM =  1;
	movies[7].dN = -2; movies[7].dM = -1;

	board.cells[n][m] = 1;

	short mv = 0;

	for (int j = 0; j < 8; j++) {
		if (checkCell(board, n + movies[j].dN  , m + movies[j].dM)) {
			mv++;
			}
		}
	 return mv;
}

myBoard stepFigure(myBoard board, int step, int n, int  m, long* p) {

	myBoard nextBoard;
	int counter = -1;
	int Max = step;

	myMove movies[8];
	movies[0].dN =  1; movies[0].dM =  2;
	movies[1].dN =  1; movies[1].dM = -2;
	movies[2].dN = -1; movies[2].dM =  2;
	movies[3].dN = -1; movies[3].dM = -2;
	movies[4].dN =  2; movies[4].dM =  1;
	movies[5].dN =  2; movies[5].dM = -1;
	movies[6].dN = -2; movies[6].dM =  1;
	movies[7].dN = -2; movies[7].dM = -1;

	*p = *p+1;
	step++;
	board.cells[n][m] = step;
	board.maxStep = step;

	if (*p%10000000 == 0) {
		printf("\nIterations: %ld\n", *p);
		printf("\nCurrent board:\n");
		printBoard(board);
	}
	/*Проверяем ходы коня по одному*/


	for (int i = 0; i < 8; i++) {
		if (checkCell(board, n + movies[i].dN, m + movies[i].dM)) {
				 nextBoard = stepFigure(board,step, n + movies[i].dN, m + movies[i].dM, p);
				 if (nextBoard.maxStep == N*M) return nextBoard;
				 /*Для экспериментов и полей меньших 5*5 */
				 if (nextBoard.maxStep > Max) {
					 counter = i;
					 Max = nextBoard.maxStep;
			 }
		}

	}


	if (counter >= 0) {
		return stepFigure(board, step, n + movies[counter].dN,  m + movies[counter].dM, p );

	} else {
		return board;
	}

}

myBoard stepFigureAdv(myBoard board, int step, int n, int  m, long* p) {

	myBoard nextBoard;
	int counter = -1;
	int Max = step;
	int mv = 0;

	myMove movies[8];
	movies[0].dN =  1; movies[0].dM =  2;
	movies[1].dN =  1; movies[1].dM = -2;
	movies[2].dN = -1; movies[2].dM =  2;
	movies[3].dN = -1; movies[3].dM = -2;
	movies[4].dN =  2; movies[4].dM =  1;
	movies[5].dN =  2; movies[5].dM = -1;
	movies[6].dN = -2; movies[6].dM =  1;
	movies[7].dN = -2; movies[7].dM = -1;

	*p = *p+1;
	step++;
	board.cells[n][m] = step;
	board.maxStep = step;

	if (*p % 10000000 ==0 ) {
		printf("\nIterations: %ld\n", *p);
		printf("\nCurrent board:\n");
		printBoard(board);
	}
	/*Применим правило Вайнсдорфа при выборе хода*/
	myOrder movesOrder[8];

	for  (int k = 0; k < 8; k++) {
	   movesOrder[k].moveNum = k;
	   if (checkCell(board, n + movies[k].dN, m + movies[k].dM)) {
		   movesOrder[k].Capacity = VarnsdorfRule(board, n + movies[k].dN, m + movies[k].dM);
	   } else {
		   movesOrder[k].Capacity = 9;
	   }
	}

	bubbleSort(movesOrder);

/*	for (int k = 0; k < 8; k++) printf("%d ",movesOrder[k].moveNum);
	printf("\n");
*/

	for (int i = 0; i < 8; i++) {
		mv = movesOrder[i].moveNum;
		if (checkCell(board, n + movies[mv].dN, m + movies[mv].dM)) {
				 nextBoard = stepFigureAdv(board,step, n + movies[mv].dN, m + movies[mv].dM, p);
				 if (nextBoard.maxStep == N*M) return nextBoard;

				if (nextBoard.maxStep > Max) {
					 counter = mv;
					 Max = nextBoard.maxStep;
			 	 }

		}

	}

	if (counter >= 0) {
		return stepFigure(board, step, n + movies[counter].dN,  m + movies[counter].dM, p );

	} else {
	  return board;
	}
}



int main (void) {

	long int p = 0;

	myBoard board;

	for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board.cells[i][j] = 0;
			}
	}

	board.maxStep = 0;

//	board = stepFigure(board, 0, 0, 0, &p);

    board = stepFigureAdv(board, 0, 3, 3, &p);

    printf("\nResult:\n");
	printBoard(board);

	printf("\n iterations %ld", p);

	return 0;
}
