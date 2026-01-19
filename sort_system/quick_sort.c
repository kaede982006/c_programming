#include <stdio.h>

void quick_sort(int arr[], int n) {
    if (arr == NULL || n <= 1) return;

    int left = 0;
    int right = n - 1;
    int pivot = arr[n / 2];
    int temp;

    while (left <= right) {
        while (left < n && arr[left] < pivot) left++;
        while (right >= 0 && arr[right] > pivot) right--;

        if (left <= right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    if (right > 0) quick_sort(arr, right + 1);
    if (left < n - 1) quick_sort(arr + left, n - left);
}

int main(void) {
    int data[10] = { 2, 9, 4, 18, 5, 1, 7, 8, 15, 12 };
    printf(" --정렬 전 순서--\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");
    quick_sort(data, sizeof(data)/sizeof(data[0]));
    printf(" --정렬 후 순서--\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
