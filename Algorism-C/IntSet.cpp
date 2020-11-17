// IntSet 소스코드
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

// 집합 초기화
int Initialize(IntSet* s, int max)
{
    s->num = 0;
    if ((s->set = (int*)calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0;      // 배열 생성 실패
        return -1;
    }
    s->max = max;
    return 0;
}

// 집합s에 n이 있는지 확인
int IsMember(const IntSet* s, int n)
{
    int i;
    for (i = 0; i < s->num; i++)
        if (s->set[i] == n)         // n의 값이 set의 값과 같을때
            return i;            // i 리턴
    return -1;
}

// 집합 s에 n을 추가
void Add(IntSet* s, int n)
{
    if (s->num < s->max && IsMember(s, n) == -1)      // num의 값이 max의 크기보다 작고 들어있지 않을때
        s->set[s->num++] = n;                     // n의 값을 set에 추가
}

// 집합 s에서 n을 삭제
void Remove(IntSet* s, int n)
{
    int idx;
    if ((idx = IsMember(s, n)) != -1)      // 요소 값이 들어있다면
    {
        s->set[idx] = s->set[--s->num];      // 요소값을 제거하고 그 값의 자리에 맨 우측의 값을 삽입
    }
}

// 집합 s에 넣을 수 있는 최대 원소 개수 반환
int Capacity(const IntSet* s)
{
    return s->max;
}

// 집합 s의 원소 개수 반환
int Size(const IntSet* s)
{
    return s->num;
}

// 집합 s2를 s1에 대입
void Assign(IntSet* s1, const IntSet* s2)
{
    int i;
    int n = (s1->max < s2->num) ? s1->max : s2->num;   // 복사하는 원소의 개수
    for (i = 0; i < n; i++)
        s1->set[i] = s2->set[i];      // s2의 값을 s1에 복사
    s1->num = n;   // num에 n값을 대입
}

// 집합 s1과 s2가 같은지 확인
int Equal(const IntSet* s1, const IntSet* s2)
{
    int i, j;
    if (Size(s1) != Size(s2))
        return 0;
    for (i = 0; i < s1->num; i++)
    {
        for (j = 0; j < s2->num; j++)
            if (s1->set[i] == s2->set[j])
                break;
        if (j == s2->num)
            return 0;
    }
    return 1;
}

// 집합 s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
    int i;
    Assign(s1, s2);      // 집합 s2를 s1에 복사
    for (i = 0; i < s3->num; i++)
        Add(s1, s3->set[i]);   // s3의 값을 s1에 하나씩 추가
    return s1;
}

// 집합 s2와 s3의 교집합을 s1에 대입
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
    int i, j;
    s1->num = 0;      // s1을 공집합으로 만듬
    for (i = 0; i < s2->num; i++)
        for (j = 0; j < s3->num; j++)
            if (s2->set[i] == s3->set[j])      // s2의 원소가 s3에 있다면
                Add(s1, s2->set[i]);         // s1에 추가합니다.
    return s1;
}

// 집합 s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
    int i, j;
    s1->num = 0;      // s1을 공집합으로 만듬
    for (i = 0; i < s2->num; i++) {
        for (j = 0; j < s3->num; j++)
            if (s2->set[i] == s3->set[j])   // s2의 원소가 s3에 있다면
                break;                  // break;
        if (j == s3->num)         // 끝에 도달하였다면
            Add(s1, s2->set[i]);   // s1에 추가
    }
    return s1;
}

// 집합 s의 모든 원소 출력
void Print(const IntSet* s)
{
    int i;

    printf(" { ");
    for (i = 0; i < s->num; i++)
        printf("%d ", s->set[i]);
    printf("}");
}

// 집합 s의 모든 원소 출력(줄바꿈 포함)
void Println(const IntSet* s)
{
    Print(s);
    putchar('\n');
}

// 집합 종료
void Terminate(IntSet* s)
{
    if (s->set != NULL)
    {
        free(s->set);         // 배열 해제
        s->max = s->num = 0;
    }
}