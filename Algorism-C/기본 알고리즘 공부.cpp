#include <stdio.h>

int main() 
{
	int i, n;
	int sum;
	// while ���� ������ ���ڸ� ���س��� �ʱ�ȭ �ؾ���
	// ex) i = 1; sum = 0;
	for (i = 1; i <= n; i++) 
	{
		sum += i;
		i++;
	}
	// do {
	// } while (no < 10 || no>99); �� �İ�
	// do {
	// } while !(no >= 10 || no<=99); �İ� ����.
}
// �ִ񰪱��ϱ�
int max3(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
} // �̷����� �Լ��� ��������

int med3(int a, int b, int c)
{
	if (a >= b) // a�� b ��
		if (b >= c) // b �� c ��
			return b; // a > b > c ��
		else if (a <= c) // a�� c �� 
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}
// �ٸ��� ���� �����ϸ�
int med3(int a, int b, int c)
{
	if ((a <= b && a>=c) || (a>=b && a <= c)) // a�� b���� �۰� c���ٴ� Ŭ��, a�� b���ٴ� ũ�� c���ٴ� ������
		return a;	// a�� ��ȯ
	else if ((b > a && b < c) || (b < a && b > c)) // ���� ������ b�� ũ�� ��
		return b;
	else
		return c;
}
