// 브루트 - 포스법
#include <stdio.h>

// 브루트 - 포스법으로 문자열을 검색하는 함수
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		// txt 커서
	int pp = 0;		// pattern 커서
	while (txt[pt] != '\0' && pat[pp] != '\0')	
	{
		if (txt[pt] == pat[pp]) {	// 일치할때
			pt++;					// 증가
			pp++;					// 증가
		}
		else {					// 일치하지 않을때
			pt = pt - pp + 1;	// 0 -> 1 -> 2 순서대로 증가시켜서 대입
			pp = 0;				// 0으로 초기화하여 처음부터 비교
		}
	}
	if (pat[pp] == '\0')
		return pt - pp;	// 패턴이 시작하는 위치를 리턴
	return -1;
}

int main()
{
	int idx;
	char txt[256];		// 텍스트
	char pattern[256]; // 패턴
	puts("부루트 - 포스법");
	printf("텍스트 : ");
	scanf("%s", txt);
	printf("패턴 : ");
	scanf("%s", pattern);
	idx = bf_match(txt, pattern);	// 텍스트에서 패턴을 브루트 - 포스법으로 검색
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.", idx + 1);

	// 연습문제 9
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