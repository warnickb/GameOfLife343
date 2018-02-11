#include <stdio.h>
#include <stdlib.h>

#include "file_utilities.h"
/**
 * @author Brendan Warnick
 * @version Winter 2018 CIS 343
 */

/**
 * generates board from file
 * used: https://stackoverflow.com/questions/18942719/reading-from-a-text-file-and-storing-in-a-2d-array for help
 */

void gameBoard(char* filename){
	int i = 0, j = 0;
	size_t count;
	int totalNums, totalNum;
	int *line;
	int numbers[100][100];
	FILE *textFile;
	char* buffer;
	textFile = fopen(read_file(filename, &buffer), "r");
	
	while(getline(&line, &count, textFile) != 1){
		for (; count > 0; count--, j++){
			sscanf(line, "%d", &numbers[i][j]);
			i++;
	}}
	
	totalNums = i;
	totalNum = j;
	for(i=0; i<totalNums; i++){
		for(j=0; j<totalNum; j++){
			printf("%d", numbers[i][j]);
		}
	}
	
}

/**
 * game of life logic
 * refrence to http://rosettacode.org/wiki/Conway%27s_Game_of_Life#C and original game
 */

void nextTurn(){

}

/**
 * check if spaces have a neighbor
 * used http://www.dreamincode.net/forums/topic/325812-neighbour-cell-detection-in-2d-array/
 */

/**figure out how to use my array
 * Occupied?
int neighborCount(int x, int y){
	int count = 0;
	for(int i = -1; i <= 1; i++){
		for(int j = -1, j <= 1; j++){
			if(Board[x+1, y+1] == Occupied) 
				count++;
		}	
	}
	if(Board[x,y] == Occupied)
		count--;
	return count;
}
*/

/**
 * takes input and performs action
 * used https://stackoverflow.com/questions/41903072/user-input-yes-or-no-in-c
 * for reference of taking user input
 */
void gameTurn(char file[]){
	char* gameBuffer;
	int gameSize = 0;
        read_file(file, &gameBuffer);
	printf("Save file(S), Load File(F), Next Generation(N), Next Number of Generations (G), Quit(Q)");
	char* userInput;
	scanf("%s", userInput);
	if(*userInput == 'S'){
		write_file(file, gameBuffer, gameSize);
	}
	else if(*userInput == 'F'){
		read_file(file, gameBuffer);
	}
	else if(*userInput == 'N'){
		nextTurn();
	}
	else if(*userInput == 'G'){
		printf("How many generations?");
		int gens = 0;
		scanf("%d", &gens);
		nextTurn();
	}
	else if(*userInput == 'Q'){
		exit(0);
	}
	else{
		printf("That was not a valid entry");
		gameTurn(file);
	}

	
}
/**
 * main
 * used help from slack
 */
int main(int a, char **b){
	gameTurn(b[1]);

}

