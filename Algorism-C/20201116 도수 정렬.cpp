// ���� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

// ���� ���� �Լ� ( �迭�� ��Ұ��� 0 �̻� MAX ����)
void fsort(int a[], int n, int max)
{
    int i;
    int* f = (int*)calloc(max + 1, sizeof(int));   // ������ ������ų �迭�� ����.
    int* b = (int*)calloc(n, sizeof(int));         // �۾��� �迭�� ����

    // ���� ������ 4�ܰ�
    // 1. ���� ����ǥ �ۼ�
    // 2. ������������ǥ �ۼ�
    // 3. ���� �迭 �����
    // 4. �迭 ����
    for (i = 0; i <= max; i++)      // ������ ���� �Է��� 
        f[i] = 0;               // �Է��� ���� ������ �ϳ��� �־���

    for (i = 0; i < n; i++)         // << 1��
        f[a[i]]++;               // �󵵼��� f �迭�� ���� �־���

    for (i = 1; i <= max; i++)      //   << 2��
        f[i] += f[i - 1];         // �������������� ����°���

    for (i = n - 1; i >= 0; i--)   // f�迭�� �����ʺ��� �����ؼ� �������� ���� ���� << 3��
        b[--f[a[i]]] = a[i];      // a �迭�� ���� f���� �ִ��ڸ��� ���� �� �ڸ��� �ε��� ���� --�� �ϳ��� �־���

    for (i = 0; i < n; i++)         // << 4��
        a[i] = b[i];            // ������ b�迭�� ���� a�� �־���

    free(b);
    free(f);
}

int main()
{
    int i, nx;
    int* x;
    const int max = 100;   // �迭�� �ִ� �� ����
    puts(" ���� ���� ");
    printf("��� ���� : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));
    printf("0~ %d�� ������ �Է��ϼ���. \n", max);

    for (i = 0; i < nx; i++)
    {
        do {
            printf("x[%d] : ", i);
            scanf_s("%d", &x[i]);
        } while (x[i] < 0 || x[i] > max);   // x�� �ε��� 0���� �۰ų� x�� �ε����� max���� Ŭ�� ������ do���� �ݺ�
    }

    fsort(x, nx, max);      // �迭 x�� ���� ����
    puts("������������ �����߽��ϴ�.");

    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}