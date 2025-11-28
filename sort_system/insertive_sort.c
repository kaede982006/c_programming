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

    for(int i=1;i<ARRAY_SIZE;i++) {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0 && temp<arr[j];j--) {
            arr[j+1]=arr[j];
        }

        j++;
        arr[j] = temp;
    }

    printf("정렬 후 배열: ");
    for (int i=0;i<ARRAY_SIZE;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
