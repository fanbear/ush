#include "ush.h"

char *mx_ush_read_line(void) {
	int bufsize = USH_BUFSIZE;
  	int posn = 0;
  	char *buffer = malloc(sizeof(char) * bufsize);
  	int ds;

	if (!buffer) {
		perror("ush: bad read line");
		exit(EXIT_FAILURE);
	}

  	while (1) {
  		ds = getchar();
    	if (ds == EOF || ds == '\n') {
    		buffer[posn] = '\0';
    		return buffer;
    	}
    	else 
    		buffer[posn] = ds;
    	posn++;
    	if (posn >= bufsize) {
    		bufsize += USH_BUFSIZE;
    		buffer = realloc(buffer, bufsize);
    		if (!buffer) {
				perror("ush: bad read line");
				exit(EXIT_FAILURE);
			}
  	  	}
  	}
  	return buffer;
}
