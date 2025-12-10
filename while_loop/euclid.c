#include <stdio.h>

int main(void) {
    int x,y,r;

    printf("두 개의 정수를 입력하세요: ");
    scanf("%d %d", &x, &y);

    if(x<y) {
        int temp=x;
        x=y;
        y=temp;
    }

    while(y!=0) {
        r=x%y;
        x=y;
        y=r;
    }

    printf("최대 공약수는 %d입니다.\n", x);

    return 0;
}
