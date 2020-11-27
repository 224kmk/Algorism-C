// 비트벡터 집합 BitSet 헤더
#ifndef __BitSet
#define __BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0		// 공집합
#define BitSetBits (32)				// 유효 비트 수
#define Setof(no) ((BitSet)1 <<(no))	// 집합 (no)


// 집합에 n이 있는지 확인
int IsMember(BitSet s, int n);

// 집합 s에 n추가
void Add(BitSet* s, int n);

// 집합 s에서 n삭제
void Remove(BitSet* s, int n);

// 집합 s의 원소 개수
int Size(BitSet s);

// 집합 s의 모든 원소 출력
void Print(BitSet s);

// 집합 s의 모든 원소를 출력(줄 바꿈 문자 포함)
void Println(BitSet s);

#endif