#include "asmio.h"
#include <stdlib.h>

int main() {
	asm_print("Enter your name: ");
	char* pointer=(char*)malloc(16);
	asm_inptr(pointer,16);

	asm_print("Hello, ");
	asm_print(pointer);
	asm_print("\n");
	free(pointer);
	return 0;
}
