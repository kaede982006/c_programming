#include "sys.h"
#include "game.h"
#include "lo.h"

#include <stdlib.h>
#include <stdio.h>

extern int width;
extern int height;
extern char** buffer;
extern char** out_buffer;
extern int line;

int main() {
    /* initialization */
    {
        system("tput civis");
        line=0;
        width=80;
        height=25;
        buffer=(char**)calloc(height, sizeof(char*));
        for(int i=0;i<height;i++) {
            buffer[i]=(char*)calloc(width, sizeof(char));
        }
        out_buffer=(char**)calloc(height, sizeof(char*));
        for(int i=0;i<height;i++) {
            out_buffer[i]=(char*)calloc(width, sizeof(char));
        }
    }
    /* prolog */
    /*
    {
        print_with_delay("자네, 얼굴이 낯이 익구먼?");
        print_with_delay("우리가 함께 했던 전투에서의 기억을 떠올리며, ");
        print_with_delay("적들을 물리치는 용사가 되어, ");
        print_with_delay("성을 괴멸하고 우리의 승리를 쟁취하세.");
    }
    */
    system("tput cnorm");
    //system("clear");
    return 0;
}
