#include <stdio.h>
#include <stdlib.h>
// ���� ���� Ƚ���� ��� Ƚ���� n/2��.
// �׷��Ƿ� ����� ������ n���� �迭��Ҹ� �������� �����ϴ� �˰����� ������ ��Ÿ����
// for (i = 0; i < n / 2; i++)��

// ��ȯ.
// �˰��� x�� �� t�� ���� y�� x�� ���� t�� x���� y�� ����. x->t, y->x, t->y
# define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
		swap(int, a[i], a[n - i - 1]); // ������ ���İ������� a[i] = x, a[n-i-1] = y��. 0���ͽ����̱⶧��
}
int main()
{
	int i;
	int* x;
	int nx;

	printf(" ��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("������ ������ �Է��ϼ��� : \n");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d]", i);
		scanf_s("%d", &x[i]);
	}

	ary_reverse(x, nx);
	printf("�迭�� ��Ҹ� �������� �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, &x[i]);
	free(x);

	return 0;
}

