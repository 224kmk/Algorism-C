#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int prime[500];	// �Ҽ��� �����ϴ� �迭
	int ptr = 0;	// �̹� ���� �Ҽ��� ����
	unsigned long counter = 0;
	prime[ptr++] = 2;	// �Ҽ���
	prime[ptr++] = 3;	// �Ҽ���
	for (n = 5; n <= 1000; n += 2) {	// 2�� ���������� ���� �Ҽ��� �ƴ�. �� Ȧ�����
		int flag = 0;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0) {	// ����������Ƿ� �Ҽ��� �ƴ�.
				flag = 1;
				break;
			}
		}
		if (!flag)
			prime[ptr++] = n;
	}
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	printf("�������� ������ Ƚ�� %d", counter);
	return 0;
}