#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

// 큐 초기화
int Initialize(IntQueue* q, int max) {
    q->num = q->front = q->rear = 0; // 데이터 front rear의 값을 0으로 초기화
    if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

// 큐에서 데이터를 인큐
int Enque(IntQueue* q, int x) {
    if (q->num >= q->max)   // que가 가득 찼는지 확인
        return -1;         // que가 가득차면 -1리턴
    else {
        q->num++;      // 들어갈때마다 하나씩 늘림
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

// 큐에서 데이터를 디큐
int Deque(IntQueue* q, int* x) {
    if (q->num <= 0)   // que가 비어있음
        return -1;
    else {
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

// 큐에서 데이터를 피크
int Peek(const IntQueue* q, int* x) {
    if (q->num <= 0)   // 큐가 비어있음.
        return -1;
    *x = q->que[q->front];
    return 0;
}

// 모든 데이터 삭제
void Clear(IntQueue* q) {
    q->num = q->front = q->rear = 0;      // 0으로 초기화
}

// 큐의 최대 용량
int Capacity(const IntQueue* q) {
    return q->max;
}

// 큐에 있는 데이터의 개수
int Size(const IntQueue* q) {
    return q->num;
}

// 큐가 비어있나
int IsEmpty(const IntQueue* q) {
    return q->num <= 0;
}

// 큐가 가득 찼나
int IsFull(const IntQueue* q) {
    return q->num >= q->max;
}

//  큐의 검색
int Search(const IntQueue* q, int x) {
    int i, idx;
    for (i = 0; i < q->num; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)      // 현재 검색하는 위치의 인덱스를 구하는 식 (i + q->front) % q->max 나머지를 구함으로서 인덱스 위치 파악
            return idx;         // 검색 성공
    }
    return -1;      // 검색 실패
}

// 큐의 출력
void Print(const IntQueue* q) {
    int i;
    for (i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

// 큐의 종료
void Terminate(IntQueue* q) {
    if (q->que != NULL)
        free(q->que);      // 메모리 공간에 할당한 배열 해제
    q->max = q->num = q->front = q->rear = 0;
}