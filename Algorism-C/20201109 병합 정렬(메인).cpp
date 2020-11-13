#include <stdio.h>
#include <stdlib.h>

static int* buff; // �۾��� �迭

static void __mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        int p = 0;         // buff�� ũ��
        int i;            // a�� index�� ���
        int j = 0;         // buff�� index�� ���
        int k = left;      // ���� �ǳ��� �ǹ�
        // ��͸� �̿��Ͽ� ���Ұ� �ϳ� ���������� �ݺ�
        __mergesort(a, left, center);      // �պκп� ���� ���� ����
        __mergesort(a, center + 1, right);   // �޺κп� ���� ���� ����
        for (i = left; i <= center; i++)
            buff[p++] = a[i];         // �迭 a�� �պκ��� buff�� ����
        while (i <= right && j < p)      // �迭�� �������� �������� �ʾ������� �ǹ�
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];   // k�� buff�� a�� ���Ͽ� ������ buff�� index��, ũ�� a�� index�� ����
        while (j < p)
            a[k++] = buff[j++];         // ���� �ϳ��� ������ �����ϰ� �����͵��� �ڿ� ����
    }
}

int mergesort(int a[], int n)
{
    if ((buff = (int*)calloc(n, sizeof(int))) == NULL)
        return -1;
    __mergesort(a, 0, n - 1);      // �迭 ��ü�� ���� ����
    free(buff);
    return 0;
}

int main()
{
    int i, nx;
    int* x;
    puts("���� ����");
    printf("��� ���� : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] :   ", i);
        scanf_s("%d", &x[i]);
    }
    mergesort(x, nx);
    puts("������������ �����߽��ϴ�.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}