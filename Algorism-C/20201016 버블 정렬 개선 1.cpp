// ���� ���� ����. ��ȯ Ƚ���� üũ�Ͽ� ����Ȯ��.
// ��ȯ�� ������� �ʾҴٸ� ������ ����.
// ex) ppt 12
#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0) 

void bubble(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;			// ��ȯ Ƚ���� üũ���� ������ ����
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0) break;	// ��ȯ�� �������� �ʾҴٸ� ������ ����.
	}
}

int main(void)
{
	int i, nx;
	int* x;			


	printf("���� ����\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);			

	printf("������������ �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}