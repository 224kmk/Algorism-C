#include <stdio.h>
#include <stdlib.h>

int card(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;	// ��ȯ �� �ڸ���
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x) 
		{
			d[digits++] = dchar[x % n]; // n���� ���� ������. ������ ��. n=8 -> 8������ȯ n=16 -> 16���� ��ȯ
			x /= n;
		}
	return digits;
}

int main()
{
	int i; // �ݺ�������
	unsigned no; // ��ȯ�ϴ� ��
	int cd = 0; // ���� ������ ��ȯ����
	int dno;	// �ڸ���
	char cno[512]; // -> ��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���� �迭
	int retry;

	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf_s("%d", &no);
		do {
			printf("� ������ ��ȯ�ұ��?(2-36) : ");
			scanf_s("%u", &cd);
		} while (cd < 2 || cd>36);
		dno = card(no, cd, cno);
		printf("%d�����δ� ", cd);
		for (i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);
		printf("�Դϴ�.");
		printf("�ѹ� �� �ұ�� ? (1: �ѹ� ��, 0: �ƴϿ�) :");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}
