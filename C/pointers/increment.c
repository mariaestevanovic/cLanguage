#include <stdio.h>

void increment(int **p)
{
    (*p)++;
}

int main()
{
    int v[5] = {10, 20, 30, 40, 55};
    int *p = v;

    printf("%d ", *p);

    increment(&p);
    printf("%d ", *p);

    increment(&p);
    printf("%d ", *p);

    increment(&p);
    printf("%d ", *p);

    increment(&p);
    printf("%d ", *p);

    return 0;
}
