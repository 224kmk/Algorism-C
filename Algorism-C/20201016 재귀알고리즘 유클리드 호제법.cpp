// �ִ� ����� ���ϱ�
// ��Ŭ���� ȣ������ �̿�
#include <stdio.h>

// ���� x, y�� �ִ������� ��ȯ
int gcd(int x, int y)
{
    if (y == 0)
    {
        printf("gcd ���� : %d\n", x);
        return x;
    }
    else
    {
        printf("gcd ���� : %d\n", y);
        return gcd(y, x % y);
    }
}

int main()
{
    int x, y;
    printf("�ִ� ������� ���մϴ�.\n");
    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &x);
    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", &y);
    printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));

    return 0;
}