#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int prime[500];	// �Ҽ��� �����ϴ� �迭
	int ptr = 0;	// �̹� ���� �Ҽ��� ����
	unsigned long counter = 0;
	prime[ptr++] = 2;
	for (n = 3; n <= 1000; n += 2) {	// 2�� ���������� ���� �Ҽ��� �ƴ�.
		for (i = 1; i < ptr; i++) {		// �̹� ���� �Ҽ��� ����.
			counter++;
			if (n % prime[i] == 0)	// ����������Ƿ� �Ҽ��� �ƴ�.
				break;
		if (ptr == i)			// ���������� ����������� �ʾҴٸ�
			prime[ptr++] = n;	// �迭�� ����.
	}
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	printf("�������� ������ Ƚ�� %d", counter);
	return 0;
}

	