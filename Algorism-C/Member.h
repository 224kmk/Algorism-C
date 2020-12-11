// ȸ�� ������ Memeber(���)
#ifndef ___Member
#define ___Member

// ȸ�� ������
typedef struct {
	int no;
	char name[20];
}Member;

#define MEMBER_NO 1 // ��ȣ�� ��Ÿ���� ���� ��
#define MEMBER_NAME 2 // �̸��� ��Ÿ���� ���� ��

// ȸ�� ��ȣ �� �Լ�
int MemberNocmp(const Member* x, const Member* y);

// ȸ�� �̸� �� �Լ�
int MemberNameCmp(const Member* x, const Member* y);

// ȸ�� �����͸� ���(�ٹٲ� X)
void PrintMember(const Member* x);

// ȸ�� �����͸� ���(�ٹٲ� O)
void PrintLnMember(const Member* x);

// ȸ�� �����͸� �о����
Member ScanMember(const char* message, int sw);

#endif
