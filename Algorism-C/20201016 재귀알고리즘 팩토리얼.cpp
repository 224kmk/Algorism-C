// ���������� ����� ��������� ���մϴ�.
// n! ���丮�� ��������
// 0! = 1
// n > 0�̸� n! = n * (n-1)!
#include <stdio.h>

int factorial(int n)
{
    printf("factorial ���� n : %d\n", n);
    if (n > 0)
    {
        int result = factorial(n - 1);
        printf("factorial ���� n : %d\n", n);
        return n * result;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int x;
    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &x);
    printf("%d�� ���������� ���� %d �Դϴ�.\n", x, factorial(x));

    return 0;
}