// ���Ʈ - ������
#include <stdio.h>

// ���Ʈ - ���������� ���ڿ��� �˻��ϴ� �Լ�
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		// txt Ŀ��
	int pp = 0;		// pattern Ŀ��
	while (txt[pt] != '\0' && pat[pp] != '\0')	
	{
		if (txt[pt] == pat[pp]) {	// ��ġ�Ҷ�
			pt++;					// ����
			pp++;					// ����
		}
		else {					// ��ġ���� ������
			pt = pt - pp + 1;	// 0 -> 1 -> 2 ������� �������Ѽ� ����
			pp = 0;				// 0���� �ʱ�ȭ�Ͽ� ó������ ��
		}
	}
	if (pat[pp] == '\0')
		return pt - pp;	// ������ �����ϴ� ��ġ�� ����
	return -1;
}

int main()
{
	int idx;
	char txt[256];		// �ؽ�Ʈ
	char pattern[256]; // ����
	puts("�η�Ʈ - ������");
	printf("�ؽ�Ʈ : ");
	scanf("%s", txt);
	printf("���� : ");
	scanf("%s", pattern);
	idx = bf_match(txt, pattern);	// �ؽ�Ʈ���� ������ ���Ʈ - ���������� �˻�
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.", idx + 1);

	// �������� 9
	//while (txt[pt] != '\0' && pat[pp] != '\0')
	//{
	//	if (pp == 0) {
	//		printf("%d", pt);
	//	}
	//	else{
	//		printf(" ");
	//	}
	//}

	//int opt = 0;

	//if (txt[pt] == pat[pp]) {
	//	printf("+");
	//	pt++;
	//	pp++;
	//}
	//else{
	//printf("|");
	//pt = pt - pp + 1;
	//pp = 0;
	//}

	return 0;
}