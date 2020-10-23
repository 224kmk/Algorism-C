// �ܼ� ���� ���� : ���� ������Һ��� ������ �ƶ��� ��ġ�� �Űܼ� ������� ����

void selection(int a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int min = i;            // �迭�� ù ��Ҹ� i�� ����
        for (j = i + 1; j < n; j++)   //* �߿�
            if (a[j] < a[min])
                min = j;
        swap(int, a[i], a[min]);
    }
}

// �ܼ� ���� ���� : ������ ��Ҹ� �׺��� �� ������ �˸��� ��ġ�� �����ϴ� �۾��� �ݺ��Ͽ� ����
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

int main()
{
    int i, nx;
    int* x;
    printf("�ܼ� ���� ����\n");

    printf("��� ���� : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }

    insertion(x, nx);

    printf("������������ �����߽��ϴ�.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}