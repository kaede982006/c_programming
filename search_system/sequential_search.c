#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {FALSE,TRUE} BOOL;
void find_element(int* arr, int num, BOOL* e_arr, int size);

int main(int argc, char** argv) {
    srand(time(NULL));
    int arr[20];

    printf("Your array: ");
    for (int i=0;i<20;i++) {
        arr[i]=rand()%20;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int num;
    printf("Search for: ");
    scanf("%d", &num);

    BOOL e_arr[20]={FALSE,};
    find_element(arr, num, e_arr, 20);

    int count=0;
    for(int i=0;i<20;i++) {
        if(e_arr[i]==TRUE) count++;
    }
    
    if(count==0) {
        printf("Not Found");
    } else {
        printf("Found at ");
        for(int i=0;i<20;i++) {
            if(e_arr[i]==TRUE && count==1) {
                printf("%d", i);
            }
            else if(e_arr[i]==TRUE) {
                printf("%d, ", i);
                count--;
            }
        }
    }
    printf("\n");

    return 0;
}

void find_element(int* arr, int num, BOOL* e_arr, int size) {
    for(int i=0;i<size;i++) {
        if(arr[i]==num) e_arr[i]=TRUE;
    }
}
