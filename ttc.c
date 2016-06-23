#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
	char board[3][3] , input , player1 , player2;
	int selectRows , selectColums,GameOver;
	int rows , colums;
}TTTGame;

void printBoard(TTTGame g){
	system("cls");
	for(g.rows = 0 ; g.rows < 3 ; g.rows++) {
		for (g.colums = 0 ; g.colums < 2 ; g.colums++) {
			printf("%c|",g.board[g.rows][g.colums]);
		}
		printf("%c",g.board[g.rows][2]);
		printf("\n------\n");
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
main (void){
	TTTGame g;

	initateBoard(&g);
	printBoard(g);
  do{
		printf("\nHit x or o or 'q' for quit. \n");
	//	printf("\nHello Sir.");

		scanf("%c",&g.input);

		if(g.input == 'x' || g.input == 'o'){
			printf("\n\nChoose 1 - 3 for rows: ");
			scanf("%d",&g.selectRows);

			printf("\n\nChoose 1 - 3 for colums:  ");

			scanf("%d",&g.selectColums);
			g.board[g.selectRows -1 ][g.selectColums -1] = g.input;
		}
		printBoard(g);
	}while(g.input != 'q');
getch();
}
