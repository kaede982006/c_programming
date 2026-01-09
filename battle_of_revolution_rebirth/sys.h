#ifndef __SYS_H__
#define __SYS_H__
#include <stdio.h>
#define MAX_BUF_LINE 64 
void clear();
void print(const char* format, ...);
void print_with_delay(const char* format, ...);
void console_update(const char* str);
char* get_text_from_file(char* buffer, FILE* file, const char* filename);
#endif
