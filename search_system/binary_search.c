#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int m;
    int n;
} RANGE;

RANGE binary_search(int* arr, int num, int size);

int main() {
    srand(time(NULL));

    int arr[20];
    for(int i=0;i<20;i++) arr[i]=rand()%20;

    for(int i=1;i<20;i++) {
        int j=i-1;
        int temp=arr[i];

        for(;j>=0&&temp<arr[j];j--) {
            arr[j+1]=arr[j];
        }

        arr[j+1]=temp;
    }

    printf("Array: ");
    for(int i=0;i<20;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int num;
    printf("Search for: ");
    scanf("%d", &num);

    RANGE range=binary_search(arr, num, 20);
    printf("range: [%d,%d]\n", range.m, range.n);
    return 0;
}

RANGE binary_search(int* arr, int num, int size) {
    int left=0;
    int right=size-1;
    int mid;

    int temp=0;
    while(left<=right) {
        mid=(left+right)/2;
        if(arr[mid]<arr[num]) left=mid+1;
        else if (arr[mid]>arr[num]) right=mid-1;
        else {
            temp=1;
            break;
        }
    }
    if(temp==0) {
        return (RANGE){-1,0};
    }
    RANGE range;
    range.n=range.m=mid;

    for(int i=mid-1;i>=0&&arr[mid]==arr[i];i--,range.m--);
    for(int i=mid+1;i<size&&arr[mid]==arr[i];i++,range.n++);

    return range;
}
