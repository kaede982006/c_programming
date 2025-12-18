#include <stdio.h>

/*
%d -> 10진수 정수 (4바이트) -> int
%ld -> 10진수 정수 (8바이트) -> long
%f -> 실수형 (4바이트) -> float
%lf -> 실수형 (8바이트) -> double
%c -> 문자 -> char
*/

int main() {
    int i=0;
    printf("%d\n", i);
    short s=10; long l=20L;
    printf("%d %ld\n", s, l);
    char ca='A';
    char cb=65;
    printf("%d %c %d %c\n", ca, ca, cb, cb);

    double d=1.0; float f=1.0f;
    printf("%lf %f", d, f);

    return 0;
}