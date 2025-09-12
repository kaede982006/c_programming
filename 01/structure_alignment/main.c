#include <stdio.h>

#include "structures.h"

int main() {
	struct sample_t var;
	unsigned char* buffer=(unsigned char*)malloc(sizeof(var));
	
	var.first='A';
	var.second='B';
	var.third='C';
	var.fourth=765;

	printf("size: %d bytes\n", return_size(&var));
	buffer=(unsigned char*)return_bytes(&var,buffer);

	if(buffer==NULL) return -1;

	for(int i=0;i<sizeof(var); i++) {
		printf("%d ",(unsigned int)*(buffer+i));
	}

	printf("\n");
	free(buffer);
	return 0;
}
