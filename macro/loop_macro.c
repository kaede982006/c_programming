#include <stdio.h>

#define m_forrange(v, s, e) for(int v=s;v<e;v++)
#define m_forrangeuu(v, s, e, u) for(int v=s;v<e;v+=u)
#define m_forrangeud(v, s, e, u) for(int v=s;v>e;v-=u)

int main() {
    m_forrange(counter, 0, 10) {
        printf("%d\n", counter);
    }
    m_forrangeuu(counter, 0, 10, 2) {
        printf("%d\n", counter);
    }
    m_forrangeud(counter, 10, -1, 1) {
        printf("%d\n", counter);
    }
    return 0;
}