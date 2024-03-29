// int형 스택 instack(소스)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

// 스택 초기화
int Initialize(IntStack* s, int max) {
    s->ptr = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

// 데이터 푸시
int Push(IntStack* s, int x) {
    if (s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

// 데이터 팝
int Pop(IntStack* s, int* x) {
    if (s->ptr <= s->max)
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

// 데이터 피크
int Peek(const IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

// 스택 클리어
void Clear(IntStack* s) {
    s->ptr = 0;
}

// 스택 용량
int Capacity(const IntStack* s) {
    return s->max;
}

// 스택에 쌓여있는 데이터 수
int Size(const IntStack* s) {
    return s->ptr;
}

// 스택이 비어있는가
int IsEmpty(const IntStack* s) {
    return s->ptr <= 0;
}

// 스택이 가득찼는지 확인
int IsFull(const IntStack* s) {
    return s->ptr >= s->max;
}

// 스택에서 검색
int Search(const IntStack* s, int x) {
    int i;
    for (i = s->ptr - 1; i >= 0; i--)   //  top -> bottom으로 선형 검색
        if (s->stk[i] == x)
            return i;
    return -1;
}

// 모든 데이터 출력
void Print(const IntStack* s) {
    int i;
    for (i = 0; i < s->ptr; i++)
        printf("%d ", s->stk[i]);
    putchar('\n');
}

void Terminate(IntStack* s) {
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}

stack의 검색
for (i=s->ptr -1; i>=0; i--) top에서 바텀으로 선형검색
    if (s->stk[i] == x)
        return i
return -1
