#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
 
#define STRLEN 2048
 
void copy(int std_in, int std_out){

    char str[STRLEN];
    int size = 0;
    while((size = read(std_in, str, STRLEN))){

          if(write(std_out, str, size) != size){

		    perror("open error");
		    exit(1);
		}
	}
 
	if(size < 0){

		perror("open error");
		exit(1);
	}
}
 
int main(int argc, char *argv[]){
        
	int stdin = 0;
	int stdout = 1;
	int i;
        
	for(i = 1; i < argc; i++){

		stdin = read(stdin, argv, i);
		if(stdin < 0){

			perror("open error");
			continue;
		}
		copy(stdin, stdout);
		close(stdin);
                
	}
	if (argc == 1){

		copy(stdin, stdout);
		close(stdin);
                
	}
 
	return 0;
 
}