#include <stdio.h>
#include <string.h>
#include "Member.h"

// 회원 번호 비교 함수
int MemberNocmp(const Member* x, const Member* y) 
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

// 회원 이름 비교 함수
int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

// 회원 데이터를 출력(줄바꿈 X)
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}

// 회원 데이터를 출력(줄바꿈 O)
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}

// 회원 데이터를 읽어들임
Member ScanMember(const char* message, int sw)
{
	Member temp;
	printf("%s하는 데이터를 입력하세요.\n", message);
	if (sw & MEMBER_NO) { // &는 sw에 MEMBER_NP가 있느냐 2진법을 이용하여 논리곱 연산
		printf("번호 : ");
		scanf("%d", &temp.no);
	}
	if (sw & MEMBER_NAME) {
		printf("이름 : ");
		scanf("%d", &temp.name);
	}
	return temp;
}