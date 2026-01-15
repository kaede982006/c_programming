#ifndef __SYS_H__
#define __SYS_H__
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

#define MAX_BUF_LINE 64 
extern void clear();
extern void print(wchar_t* format, ...);
extern void print_with_delay(wchar_t* format, ...);
extern void print_per_line(wchar_t* buffer);
extern void console_update(const wchar_t* str);
extern wchar_t* get_text_from_file(wchar_t* buffer, FILE* file, const char* filename);
extern void xsleep(unsigned int second);
#endif
