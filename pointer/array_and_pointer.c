#include <stdio.h>
#include <stdlib.h>

// 1. 2차원 배열 테스트 함수
void test_2d_array() {
    printf("\n=== 1. 2차원 배열 (int arr[3][3]) ===\n");
    
    // 메모리에 연속적으로 할당됨 (스택 영역)
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("주소 확인:\n");
    printf("Row 0의 끝 (arr[0][2]): %p\n", (void*)&arr[0][2]);
    printf("Row 1의 시작(arr[1][0]): %p\n", (void*)&arr[1][0]);

    // 주소 차이 계산
    long diff = (long)&arr[1][0] - (long)&arr[0][2];
    printf("-> 주소 차이: %ld 바이트 (int 1개 크기인 4와 같음 -> 연속적!)\n", diff);

    // 포인터 덧셈 테스트 (*(&arr[0][0] + 4))
    // 0행 0열에서 4칸 뒤로 점프하면 1행 1열(값 5)이 나와야 함
    int *base = &arr[0][0];
    int val = *(base + 4); 
    printf("\n[실험] base + 4 위치의 값: %d (예상값: 5) -> 성공!\n", val);
}

// 2. 이중 포인터 테스트 함수
void test_double_pointer() {
    printf("\n=== 2. 이중 포인터 (int **pp) ===\n");

    // 목차(행 포인터들) 할당
    int **pp = (int**)malloc(3 * sizeof(int*));

    // 각 행을 따로따로 할당 (힙 영역, 불연속적일 확률 높음)
    for(int i = 0; i < 3; i++) {
        pp[i] = (int*)malloc(3 * sizeof(int));
        // 값 채우기 (1~9)
        for(int j = 0; j < 3; j++) {
            pp[i][j] = (i * 3) + j + 1; 
        }
    }

    printf("주소 확인:\n");
    printf("Row 0의 끝 (pp[0][2]): %p\n", (void*)&pp[0][2]);
    printf("Row 1의 시작(pp[1][0]): %p\n", (void*)&pp[1][0]);

    // 주소 차이 계산
    long diff = (long)&pp[1][0] - (long)&pp[0][2];
    printf("-> 주소 차이: %ld 바이트 (4가 아님 -> 불연속적!)\n", diff);

    // 포인터 덧셈 테스트
    // 0행 0열에서 4칸 뒤로 점프 시도
    int *base = &pp[0][0];
    
    // 주의: 실제로는 여기서 쓰레기 값이 나오거나 프로그램이 죽을 수도 있음
    // 안전을 위해 값만 확인 (운 좋게 읽힐 수도 있지만 5는 절대 아님)
    int val = *(base + 4); 
    printf("\n[실험] base + 4 위치의 값: %d (예상값 5와 다름/쓰레기값) -> 실패!\n", val);

    // 메모리 해제
    for(int i = 0; i < 3; i++) free(pp[i]);
    free(pp);
}

int main() {
    test_2d_array();
    test_double_pointer();
    return 0;
}
