// �ð����⵵�� n log n�̴�
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x, x = y, y= t;}

void partition(int a[], int n)
{
    int i;
    int pl;
    int pr = n - 1;
    int x = a[n / 2];
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
    printf("�ǹ��� ���� %d�Դϴ�.\n", x);
    printf("�ǹ� ������ �׷�\n");
    for (i = 0; i <= pl - 1; i++)
        printf("%d ", a[i]);
    printf("");
    if (pl > pr + 1)
    {
        printf("�ǹ��� ��ġ�ϴ� �׷�\n");
        for (i = pr + 1; i <= pl - 1; i++)
            printf("%d ", a[i]);
        printf("");
    }
    printf("�ǹ� �̻��� �׷�\n");
    for (i = pr + 1; i < n; i++)
        printf("%d ", a[i]);
    printf("");
}

int main()
{
    int i, nx;
    int* x;
    printf("�迭�� �����ϴ�.\n");
    printf("��� ���� : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }
    partition(x, nx);
    free(x);

    return 0;
}