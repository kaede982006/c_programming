#include "structures.h"

unsigned long long return_size(struct sample_t* var) {
	return sizeof(*var);
}

void* return_bytes(struct sample_t* var, unsigned char* buffer) {
	if (malloc_usable_size(buffer)/sizeof(int)!=return_size(var)) return NULL;
	unsigned char* ptr=(unsigned char*)var;
	for(int i=0; i<sizeof(*var);i++) {
		buffer[i]=ptr[i];
	}
	return buffer;
}
