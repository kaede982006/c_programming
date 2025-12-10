#include <stdio.h>

int main(void) {
    double current_element_amount, original_element_amount;
    unsigned int maximum_life, half_life, current_life=0;

    printf("원소의 양을 입력하세요: "); scanf("%lf", &original_element_amount);
    printf("반감기를 입력하세요: "); scanf("%u", &half_life);
    printf("생존 시간을 입력하세요: "); scanf("%u", &maximum_life);

    current_element_amount = original_element_amount;
    while (maximum_life>=current_life) {
        printf("%u년 경과, 현재 원소 비율: %lf%%\n",\
                current_life, current_element_amount/original_element_amount);
        current_life+=half_life;
        current_element_amount/=2;
    }

    return 0;
}
