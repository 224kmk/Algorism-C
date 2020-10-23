#include <stdio.h>
#include <stdlib.h>

int card(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;	// 변환 후 자릿수
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x) 
		{
			d[digits++] = dchar[x % n]; // n으로 나눈 나머지. 진수의 값. n=8 -> 8진수변환 n=16 -> 16진수 변환
			x /= n;
		}
	return digits;
}

int main()
{
	int i; // 반복돌리기
	unsigned no; // 변환하는 수
	int cd = 0; // 무슨 진수로 변환할지
	int dno;	// 자릿수
	char cno[512]; // -> 변환한 값의 각 자리의 숫자를 저장하는 문자 배열
	int retry;

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf_s("%d", &no);
		do {
			printf("어떤 진수로 변환할까요?(2-36) : ");
			scanf_s("%u", &cd);
		} while (cd < 2 || cd>36);
		dno = card(no, cd, cno);
		printf("%d진수로는 ", cd);
		for (i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);
		printf("입니다.");
		printf("한번 더 할까요 ? (1: 한번 더, 0: 아니오) :");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}
