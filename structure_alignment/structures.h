#ifndef STRUCTURES
#define STRUCTURES

#include <malloc.h>
#include <stddef.h>

struct sample_t {
	char first;
	char second;
	char third;
	short fourth;
};
unsigned long long return_size(struct sample_t* var);
void* return_bytes(struct sample_t* var, unsigned char* buffer);

#endif
