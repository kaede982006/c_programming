#include "sys.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int line;
int width, height;
char** buffer;
char** out_buffer;
void clear() {
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
void console_update(const char* str) {
    if (line==height-1) {
        for(int i=0;i<line-1;i++) {
            strcpy(out_buffer[i], out_buffer[i+1]);
        }
        strcpy(out_buffer[line], str);
    }
    else {
        strcpy(out_buffer[line], str);
        line++;
    }
}
void print(const char* format, ...) {
    char out[width+1];
    char buf[width+16];

    va_list args;
    va_start(args, format);
    vsnprintf(out, sizeof(out), format, args); // 실제 출력 문자열 생성
    va_end(args);

    console_update(out);

    int temp=line; clear();
    for(int i=1;i<=temp+1;i++) {
        printf("\033[41;33m\033[%d;%dH%s\033[0m", i, 0, out_buffer[i-1]);
        sprintf(buffer[i-1], "\033[41;33m\033[%d;%dH%s\033[0m", i, 0, out_buffer[i-1]);
    }
    line=temp;
}
void print_with_delay(const char* format, ...) {
    char out[width+1];
    char buf[width+16];

    va_list args;
    va_start(args, format);
    vsnprintf(out, sizeof(out), format, args); // 실제 출력 문자열 생성
    va_end(args);

    console_update(out);

    int temp=line; clear();
    for(int i=1;i<=temp+1;i++) {
        printf("\033[41;33m\033[%d;%dH%s\033[0m", i, 0, out_buffer[i-1]);
        sprintf(buffer[i-1], "\033[41;33m\033[%d;%dH%s\033[0m", i, 0, out_buffer[i-1]);
    }
    line=temp;
    fflush(stdout);

    unsigned sec = (unsigned)(strlen(out) / 10);
    if (sec == 0) sec = 1;
    sleep(sec);
}

