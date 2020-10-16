#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0) // ������ 3�� �Ͼ

// ������ 3 * n(n-1) / 4 �̱⶧���� �ð����⵵�� O(n^2)�̴�.
void bubble(int a[], int n) // a[]�� �迭�� �Է¸����ֱ⶧���� ���ο��� ũ�⸦ ������
{
	int i, j;
	// ���Ⱑ �߿� ���� ���α׷�
	// �� ó�� n-1�� ��Ƚ���� ����
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])	// if ���� ���̸� ��ȯ�� �Ͼ
				swap(int, a[j - 1], a[j]);
	}
}

int main(void)
{
	int i, nx;
	int* x;			// �迭�� ù ��° ��ҿ� ���� ������

	
	printf("���� ����\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int *)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);			// �迭 x�� ���� ����

	printf("������������ �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}