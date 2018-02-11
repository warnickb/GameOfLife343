#include <stdio.h>
#include <stdlib.h>

#include "file_utilities.h"
/**
 * @author Brendan Warnick
 * @version Winter 2018 CIS 343
 */
/**
 * write file
 * used slack messages and http://www.zentut.com/c-tutorial/c-write-text-file/ for help
 * and https://stackoverflow.com/questions/11573974/write-to-txt-file
 */
int write_file(char* filename, char *buffer, int size){
	FILE *newFile = fopen("test.txt", "wb");
	fwrite(buffer, sizeof(char), sizeof(buffer), newFile);
	fclose(newFile);
	return 0;
}

/**
 * read file 
 * used slack messages and https://www.programmingsimplified.com/c-program-read-file
 * for help
 * and https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
 */
int read_file(char* filename, char **buffer){
	FILE *gameFile;
	size_t nread;
		
	gameFile = fopen(filename, "r");
	if (gameFile){
		while((nread = fread(buffer, 1, sizeof buffer, gameFile)) > 0)
			fwrite(buffer, 1, nread, stdout);
	if(ferror(gameFile)){
		printf("Error reading file");
		exit(0);
	}}
}





