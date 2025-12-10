#include <stdio.h>

int main(void) {
    int grade, n;
    float sum, average;

    sum=n=grade=0;

    printf("성적 입력을 종료하려면 음수를 입력하세요\n");

    while(grade>=0) {
        printf("성적을 입력하세요: ");
        scanf("%d", &grade);

        sum+=grade; n++;
    }

    sum-=grade; n--;
    average = sum/n;
    printf("성적의 평균은 %f입니다.\n",average);

    return 0;
}
