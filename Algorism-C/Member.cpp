#include <stdio.h>
#include <string.h>
#include "Member.h"

// ȸ�� ��ȣ �� �Լ�
int MemberNocmp(const Member* x, const Member* y) 
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

// ȸ�� �̸� �� �Լ�
int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

// ȸ�� �����͸� ���(�ٹٲ� X)
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}

// ȸ�� �����͸� ���(�ٹٲ� O)
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}

// ȸ�� �����͸� �о����
Member ScanMember(const char* message, int sw)
{
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) { // &�� sw�� MEMBER_NP�� �ִ��� 2������ �̿��Ͽ� ���� ����
		printf("��ȣ : ");
		scanf("%d", &temp.no);
	}
	if (sw & MEMBER_NAME) {
		printf("�̸� : ");
		scanf("%d", &temp.name);
	}
	return temp;
}