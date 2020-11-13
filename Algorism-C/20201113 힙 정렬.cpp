// �� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x, x = y, y= t;} while(0)

// a[left]�� ~ a[right]�� ����� �Լ�
static void downheap(int a[], int left, int right)
{
	int temp = a[left];		// ������ �θ��� ��Ʈ
	int child;				// �ڽ� ���
	int parent;				// �θ� ���
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1;	// ���ʳ��� �θ��� ��� �ι��� +1
		int cr = cl + 1;			// ������ ���� ���� ����� +1
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl; // �ڽĳ�尡 �ڸ��� ã�� �ö󰡴� ���� 
		if (temp >= a[child])		// �������� temp�� �ڽĳ�庸�� Ŀ������
			break;
		a[parent] = a[child];		// �ڸ��� ã�������� �θ���� �ڽĳ�带 ��ȯ.
	}
	a[parent] = temp;		// �ڸ��� ã���� temp�� ����
}

// �� ���� �Լ�
void heapsort(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)	// �� ���� ��忡�� �ϳ��� -�� �ϸ鼭 ����
		downheap(a, i, n - 1);			// �迭 a�� �� ���ķ� ��ȯ.
	for (i = n - 1; i > 0; i--)		// �ϳ��� �� �� �ٽ� �� ������ ��Ŵ
	{
		swap(int, a[0], a[i]);		// ������ �θ��带 ���� i��ġ�� �ٲ�
		downheap(a, 0, i - 1);		// �� ������ �ݺ���.
	}
}

int main()
{
	int i, nx;
	int* x;
	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);	// �迭 x�� �� ������.
	printf("������������ �����߽��ϴ�. \n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}