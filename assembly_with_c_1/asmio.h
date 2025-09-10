#ifndef ASMIO
#define ASMIO

extern void asm_print(const char* msg);
//extern char* asm_inptr(unsigned long long size);
extern void asm_inptr(char* buffer,unsigned long long size);
#endif
