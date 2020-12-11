// 회원 데이터 Memeber(헤더)
#ifndef ___Member
#define ___Member

// 회원 데이터
typedef struct {
	int no;
	char name[20];
}Member;

#define MEMBER_NO 1 // 번호를 나타내는 정수 값
#define MEMBER_NAME 2 // 이름을 나타내는 정수 값

// 회원 번호 비교 함수
int MemberNocmp(const Member* x, const Member* y);

// 회원 이름 비교 함수
int MemberNameCmp(const Member* x, const Member* y);

// 회원 데이터를 출력(줄바꿈 X)
void PrintMember(const Member* x);

// 회원 데이터를 출력(줄바꿈 O)
void PrintLnMember(const Member* x);

// 회원 데이터를 읽어들임
Member ScanMember(const char* message, int sw);

#endif
