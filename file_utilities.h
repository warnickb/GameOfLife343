#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H
/**
 * @author Brendan Warnick
 * @version Winter 2018 CIS 343
 */

int read_file(char* filename, char **buffer);
int write_file(char* filename, char *buffer, int size);

#endif
