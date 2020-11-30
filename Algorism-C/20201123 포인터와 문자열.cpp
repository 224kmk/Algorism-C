#include <stdio.h>

int main()
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\n';
	printf("문자열 st에는 \"%s\"가 들어있습니다.\n", st);

	char* pt = "12345";
	printf("포인터 pt는 \"%s\"를 가리킵니다.\n", pt);


	return 0;
}