#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct{
	char board[3][3] , input;
	int selectRows , selectColums,GameOver,rows , colums,size;
	// int rows , colums;
}TTTGame;
//
// typedef enum{
//
// }player;

typedef struct{
	int x , y;
}Pos;
void printBoard(TTTGame g){
	system("cls");
	for(g.rows = 0 ; g.rows < 3 ; g.rows++) {
		for (g.colums = 0 ; g.colums < 3 ; g.colums++) {
			printf("%c|",g.board[g.rows][g.colums]);
		}
//		printf("%c",g.board[g.rows][2]);
		if(g.rows < 2)
			printf("\n------\n");
		else
			printf("\n");
	}
}

void initateBoard(TTTGame *g){
	for(g->rows = 0 ; g->rows < 3 ; g->rows++) {
		for (g->colums = 0 ; g->colums < 3 ; g->colums++) {
			g->board[g->rows][g->colums] = ' ';
		}
	}
}
void GameOver(TTTGame *g){

}
// Player move(TTTGame g, Position *lastMove, Player player){
// 	g.board[lastMove->y][lastMove->x] = player;
//   g.rowScores[lastMove->y] += player;
//   g.colScores[lastMove->x] += player;
//
//   if (lastMove->y == lastMove->x) {
//     g.topLeftBottomRightDiagonalScores += player;
//   }
//
//   if (lastMove->x == game->size - lastMove->x) {
//     g.topRightBottomLeftDiagonalScores += player;
//   }
//
//   return checkForWinner(g, lastMove);
// }

int choosePlace(char* sE){
	int input;
	//char desc[] = "";
	printf("\n\nChoose 1 - 3 for %s: ",sE);

	scanf("%d",&input);
	while(0 >= input || input > 3 ) {
		printf("\n Can't accessable." );
		printf("\n\nChoose 1 - 3 for %s: ",sE);
		scanf("%d",&input);
	}
	return input;
}

main (void){
	TTTGame g;
	initateBoard(&g);
	printBoard(g);
  do{
		printf("\nHit x or o or 'q' for quit. \n");
		scanf("%c",&g.input);

		if(g.input == 'x' || g.input == 'o'){

			g.selectRows = choosePlace("rows");
			g.selectColums = choosePlace("coloms");

			g.board[g.selectRows -1 ][g.selectColums -1] = g.input;
		}
		printBoard(g);
	}while(g.input != 'q');
getch();
}
