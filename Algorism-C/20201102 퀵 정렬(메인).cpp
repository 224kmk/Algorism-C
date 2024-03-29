// 퀵 정렬
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x, x = y, y= t;} while(0)

void quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    do
    {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    if (left < pr) quick(a, left, pr);
    if (pr < right) quick(a, pl, right);
}
int main()
{
    int i, nx;
    int* x;
    printf("퀵 정렬.\n");
    printf("요소 개수 : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }
    quick(x, 0, nx - 1); // 배열 x에 대해서 퀵 정렬합니다.
    printf("오름차순으로 정렬했습니다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}