#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256

char* create_name(char* buffer) {
    buffer=(char*)malloc(MAX_NAME_LENGTH);
}

void query_name(char* name) {
    name=create_name(name); //함수

    printf("What's your name?: "); //출력
    scanf("%s", name); //입력

    printf("Nice to meet you, %s!\n", name);

    free(name);
}
int main() {
    char* name;
    query_name(name);
    return 0;
}