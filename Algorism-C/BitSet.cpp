// IntSet 소스코드
#include <stdio.h>
#include <stdlib.h>
#include "BitSet.h"

// 집합s에 n이 있는지 확인
int IsMember(BitSet s, int n)
{
    return s & Setof(n);
}

// 집합 s에 n을 추가
void Add(BitSet* s, int n)
{
    *s |= Setof(n);
}

// 집합 s에서 n을 삭제
void Remove(BitSet *s, int n)
{
    *s &= ~Setof(n);
}

// 집합 s의 원소 개수 반환
int Size(BitSet s)
{
    int n = 0;
    for (; s != BitSetNull; n++)
        s &= s - 1;
    return n;
}

// 집합 s의 모든 원소 출력
void Print(BitSet s)
{
    int i;
    printf(" { ");
    for (i = 0; i < BitSetNull; i++)
        if (IsMember(s, i))
            printf("%d", i);
    printf("}");
}

// 집합 s의 모든 원소 출력(줄바꿈 포함)
void Println(BitSet s)
{
    Print(s);
    putchar('\n');
}