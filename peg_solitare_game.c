#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printBoard(const int board[7][7]); 

int parseMove(char *input, int *x1, int *y1, int *x2, int *y2);
int isValidMove(const int board[7][7], char *input);
void effectMove(int board[7][7], char *input);
int isWon(const int board[7][7]);

/* char board[7][7] = {{'q', 'q', 'a', 'b', 'c', 'q', 'q'}
					  , {'q', 'q', 'd', 'e', 'f', 'q', 'q'}
					  , {'g', 'h', 'i', 'j', 'k', 'l', 'm'}
					  , {'n', 'o', 'p', 'x', 'P', 'O', 'N'}
					  , {'M', 'L', 'K', 'J', 'I', 'H', 'G'}
					  , {'q', 'q', 'F', 'E', 'D', 'q', 'q'}
					  , {'q', 'q', 'C', 'B', 'A', 'q', 'q'}
					  }; */


int main () {
	char buffer[50];
	int board[7][7] = {	{2, 2, 1, 1, 1, 2, 2}
					  , {2, 2, 1, 1, 1, 2, 2}
					  , {1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 0, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1}
					  , {2, 2, 1, 1, 1, 2, 2}
					  , {2, 2, 1, 1, 1, 2, 2}
					  };

// */ // Winning board 
/*					{	{2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {0, 0, 0, 1, 0, 0, 0}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  }; // */


	printf("><><><><><><><><><><><><\n");
	printf("  Welcome to Solitaire!\n");
	printf("><><><><><><><><><><><><\n");
	printf("Enter your moves by typing the character corresponding\nto the piece you wish to move, then typing the character\nof the place you wish to move it to.\nEnter 'q' to quit at any time.\n\n");

	int won = isWon(board);
	printf("won = %d\n", won);
	while (won != 1 && won != -1) {
		printBoard(board);
		printf("S >> ");
		scanf("%s", buffer);
		if (strcmp(buffer, "q") == 0) {
			break;
		}
		if (isValidMove(board, buffer)) {
			effectMove(board, buffer);
		} else {
			printf("Move Invalid\n");
		}
		won = isWon(board);
	}
	if (won == 1) {
		printf("A winner is you!\n");
	} else if (won == -1) {
		printf("Ya Done Son! No Moves Remaining!\n");
	} else {
		printf("Game Over, Yeah!\n");
	}
	printf("Solitaire Terminated!\n");
}

void printBoard(const int board[7][7]){ 
	char temp[5];
	char buf[150]; 
	char moveKey[15][100]  =
{ "    ╔═╤═╤═╗     │     ╔═╤═╤═╗    "
, " ☻  ║a│b│c║  ☻  │     ║"
, "    ╟─┼─┼─╢     │     ╟─┼─┼─╢    "
, "    ║d│e│f║     │     ║"
, "╔═╤═╃─┼─┼─╄═╤═╗ │ ╔═╤═╃─┼─┼─╄═╤═╗"
, "║g│h│i│j│k│l│m║ │ ║"
, "╟─┼─┼─┼─┼─┼─┼─╢ │ ╟─┼─┼─┼─┼─┼─┼─╢"
, "║n│o│p│x│P│O│N║ │ ║"
, "╟─┼─┼─┼─┼─┼─┼─╢ │ ╟─┼─┼─┼─┼─┼─┼─╢"
, "║M│L│K│J│I│H│G║ │ ║"
, "╚═╧═╅─┼─┼─╆═╧═╝ │ ╚═╧═╅─┼─┼─╆═╧═╝"
, "    ║F│E│D║     │     ║"
, "    ╟─┼─┼─╢     │     ╟─┼─┼─╢"
, " ☻  ║C│B│A║  ☻  │     ║"
, "    ╚═╧═╧═╝     │     ╚═╧═╧═╝"
};
	for (int i = 0; i < 15; i++) {
		strcpy(buf, moveKey[i]);
		if (i == 1 || i == 3 || i == 11 || i == 13) {
			for (int j = 2; j <= 4; j++) {
				if (board[i>>1][j] == 1) {
					strcpy(temp,"●");
				} else {
					strcpy(temp," ");
				}
				strcat(buf, temp);
				if (j < 4) {
					strcat(buf, "│");
				} else {
					strcat(buf, "║");
				}
			}
		} else if (i == 5 || i == 7 || i == 9) {
			for (int j = 0; j < 7; j++) {
				if (board[i>>1][j] == 1) {
					strcpy(temp,"●");
				} else {
					strcpy(temp," ");
				}
				strcat(buf, temp);
				if (j < 6) {
					strcat(buf, "│");
				} else {
					strcat(buf, "║");
				}
			}
		}
		printf("%s\n", buf);
	}
}

int parseMove(char *input, int *x1, int *y1, int *x2, int *y2){ 
	char board[7][7] = {{'q', 'q', 'a', 'b', 'c', 'q', 'q'}
					  , {'q', 'q', 'd', 'e', 'f', 'q', 'q'}
					  , {'g', 'h', 'i', 'j', 'k', 'l', 'm'}
					  , {'n', 'o', 'p', 'x', 'P', 'O', 'N'}
					  , {'M', 'L', 'K', 'J', 'I', 'H', 'G'}
					  , {'q', 'q', 'F', 'E', 'D', 'q', 'q'}
					  , {'q', 'q', 'C', 'B', 'A', 'q', 'q'}
					  };
	char ok[]="abcdefghijklmnopxPONMLKJIHGFEDCBA"; //Check for any letters in this string
	char letter1 = input[0];
	char letter2 = input[1];
	if (strchr(ok, letter1) && strchr(ok, letter2)){
		for (int i = 0; i<7; i++){
			for (int j = 0; j<7; j++){
				if (board[i][j]==letter1){
					*x1 = i;
					*y1 = j;
				}
				if (board[i][j]==letter2){
					*x2 = i;
					*y2 = j;
				}
			}
		}
	}
	else{
		return -1;
	}
	return 0;
}

int isValidMove(const int board[7][7], char *input){
	int x1; int y1; int x2; int y2;
	parseMove(input, &x1, &y1, &x2, &y2);
	if (board[x2][y2]==0){
		if (((x1+2)||(x1-2)==x2)&((y1-y2)==0)){
			if ((x1+2==x2)&(x1+1==1)){
				return 1;
			}
			if ((x1-2==x2)&(x1-1==1)){
				return 1;
			}
		}
		if (((x1+2)||(x1-2)==x2)||((y1+2)||(y1-2)==y2)){
			if (board[x1+1][y1+1]||board[x1+1][y1-1]||board[x1-1][y1+1]||board[x1-1][y1-1]==1){
				return 1;
			}
		}
		if (((y1+2)||(y1-2)==y2)&((x1-x2)==0)){
			if ((y1+2==y2)&(y1+1==1)){
				return 1;
			}
			if ((y1-2==y2)&(y1-1==1)){
				return 1;
			}
		}
	}
	return 0;
}

void effectMove(int board[7][7], char *input){
	int x1; int y1; int x2; int y2;
	parseMove(input, &x1, &y1, &x2, &y2);
	board[x2][y2]=1;
	board[x1][y1]=0;
	if (((x1+2)||(x1-2)==x2)&((y1-y2)==0)){
			if ((x1+2==x2)&(x1+1==1)){
				board[x1+1][y2]=0;
			}
			if ((x1-2==x2)&(x1-1==1)){
				board[x1-1][y2]=0;
			}
		}
		if (((x1+2)||(x1-2)==x2)||((y1+2)||(y1-2)==y2)){
			if (board[x1+1][y1+1]||board[x1+1][y1-1]||board[x1-1][y1+1]||board[x1-1][y1-1]==1){
				if ((x1+2==x2)&(y1+2==y2)){
					board[x1+1][y1+1]=0;
				}
				if ((x1+2==x2)&(y1-2==y2)){
					board[x1+1][y1-1]=0;
				}
				if ((x1-2==x2)&(y1+2==y2)){
					board[x1-1][y1+1]=0;
				}
				if ((x1-2==x2)&(y1-2==y2)){
					board[x1-1][y1-1]=0;
				}
			}
		}
		if (((y1+2)||(y1-2)==y2)&((x1-x2)==0)){
			if ((y1+2==y2)&(y1+1==1)){
				board[x1][y1+1]=0;
			}
			if ((y1-2==y2)&(y1-1==1)){
				board[x1][y1-1]=0;
			}
		}
}

int isWon(const int board[7][7]){
	int counter = 0;
	int goodboard[7][7] ={	{2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {0, 0, 0, 1, 0, 0, 0}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  }; 

	for (int i = 0; i < 7; i++){
		for (int j=0; j < 7; j++){
			if (goodboard[i][j]==board[i][j]){
				counter++;
			}
		}
	}
	
	if (counter==49){
		return 1;
	}
	return 0;
}