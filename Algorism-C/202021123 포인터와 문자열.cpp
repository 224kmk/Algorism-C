#include <stdio.h>

int main()
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\n';
	printf("���ڿ� st���� \"%s\"�� ����ֽ��ϴ�.\n", st);

	char* pt = "12345";
	printf("������ pt�� \"%s\"�� ����ŵ�ϴ�.\n", pt);


	return 0;
}