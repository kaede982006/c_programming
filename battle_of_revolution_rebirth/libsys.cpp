#include "sys.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <sys/wait.h>

int line;
int width, height;
wchar_t** buffer;
wchar_t** out_buffer;
extern "C" void clear() {
    printf("\x1b[2J\x1b[H");
    for (int r = 0; r < height; r++) {
        for (int s = 0; s < width; s++) {
            printf("\x1b[41m \x1b[0m");
        }
        printf("\n");
    }
    fflush(stdout);
    line=0;
}
extern "C" void console_update(const wchar_t* str) {
    if (line==height-1) {
        for(int i=0;i<line-1;i++) {
            wcscpy(out_buffer[i], out_buffer[i+1]);
        }
        wcscpy(out_buffer[line], str);
    }
    else {
        wcscpy(out_buffer[line], str);
        line++;
    }
}
extern "C" void print(wchar_t* format, ...) {
    wchar_t out[width+1];
    wchar_t buf[width+16];

    va_list args;
    va_start(args, format);
    vswprintf(out, width+1, format, args);
    va_end(args);

    console_update(out);

    int temp=line; 
    for(int i=0;i<temp;i++) {
        // wchar_t를 char로 변환하여 출력
        char out_str[width+16];
        wcstombs(out_str, out_buffer[i], width+16);
        printf("\033[41;33m\033[%d;%dH%s\033[0m", i+1, 0, out_str);
    }
    line=temp;
    fflush(stdout);
}
extern "C" void print_with_delay(wchar_t* format, ...) {
    wchar_t out[width+1];
    wchar_t buf[width+16];

    va_list args;
    va_start(args, format);
    vswprintf(out, width+1, format, args);
    va_end(args);

    console_update(out);

    int temp=line; 
    for(int i=0;i<temp;i++) {
        // wchar_t를 char로 변환하여 출력
        char out_str[width+16];
        wcstombs(out_str, out_buffer[i], width+16);
        printf("\033[41;33m\033[%d;%dH%s\033[0m", i+1, 0, out_str);
    }
    line=temp;
    fflush(stdout);

    xsleep(wcslen(out)/10 +1);
}
extern "C" wchar_t* get_text_from_file(wchar_t* buffer, FILE* file, const char* filename) {
    setlocale(LC_ALL, "ko_KR.UTF-8");
    file = fopen(filename, "r, ccs=UTF-8");
    if(file == NULL) return NULL;
    
    int total_idx = 0;
    wchar_t in_buffer[81];
    
    while (fgetws(in_buffer, 81, file) != NULL && total_idx < 80*25-1) {
        size_t len = wcslen(in_buffer);
        if (total_idx + len < 80*25-1) {
            wmemcpy(&buffer[total_idx], in_buffer, len);
            total_idx += len;
        } else {
            break;
        }
    }
    buffer[total_idx] = L'\0';
    
    fclose(file);
    return buffer;
}
extern "C" void print_per_line(wchar_t* buffer) {
    wchar_t* line_start = buffer;
    wchar_t* line_end;
    while ((line_end = wcschr(line_start, L'\n')) != NULL) {
        *line_end = L'\0'; // 개행 문자를 널 문자로 대체
        print_with_delay(L"%ls", line_start);
        line_start = line_end + 1; // 다음 줄의 시작 위치로 이동
    }
}
extern "C" void xsleep(unsigned int second) {
    char command[32];
    sprintf(command, "sleep %u", second);
    system(command);
}