#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10000

int main() {
    srand(time(NULL));
    int arr[ARRAY_SIZE];

    printf("정렬 전 배열: ");
    for (int i=0;i<ARRAY_SIZE;i++) {
        arr[i]=rand()%ARRAY_SIZE;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i=0;i<ARRAY_SIZE-1;i++) {
        int min_value = i;
        for(int j=i+1;j<ARRAY_SIZE;j++) {
            if(arr[min_value]>arr[j]) min_value=j;
        }
        int temp = arr[i];
        arr[i] = arr[min_value];
        arr[min_value] = temp;
    }

    printf("정렬 후 배열: ");
    for (int i=0;i<ARRAY_SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
