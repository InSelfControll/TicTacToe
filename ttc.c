#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct{
	char board[3][3] , player;
	int selectRows , selectColums,GameOver,rows , colums,size;
}TTTGame;
typedef struct{
	int x , y;
}Pos;
void printBoard(TTTGame g){
	system("cls");
	for(g.rows = 0 ; g.rows < 3 ; g.rows++) {
		for (g.colums = 0 ; g.colums < 3 ; g.colums++) {
			printf("%c|",g.board[g.rows][g.colums]);
		}
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
		for(g->rows = 0 ; g->rows < 3 ; g->rows++) {
			for (g->colums = 0 ; g->colums < 3 ; g->colums++) {
				g->board[g->rows][g->colums] = ' ';
			}
		}
	}
int choosePlace(char* sE){
	int input;
	printf("\n\nChoose 1 - 3 for %s: ",sE);

	scanf("%d",&input);
	while(0 >= input || input > 3 ) {
		printf("\n The operation is not permitable." );
		printf("\n\nChoose 1 - 3 for %s: ",sE);
		scanf("%d",&input);
	}
	return input;
}

main (void){
	TTTGame g;
	initateBoard(&g);
	printBoard(g);
	// GameOver(&g);
	int input;
	g.player = 'x';
  do{
		printf("\n%c turn. \n",g.player);

		g.selectRows = choosePlace("rows");
		g.selectColums = choosePlace("coloms");

//if place taken, goto "here!"
		while(g.board[g.selectRows - 1][g.selectColums - 1] != ' '){
			printf("\nPlease choose a different place.");
			g.selectRows = choosePlace("rows");
			g.selectColums = choosePlace("coloms");
		}

		g.board[g.selectRows -1 ][g.selectColums -1] = g.player;

		if(g.player == 'x'){
				g.player = 'o';
		}else{
			g.player = 'x';
		}
		printBoard(g);
	}while(1);
getch();
}
