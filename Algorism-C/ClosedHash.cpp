// 오픈주소법으로 구현한 해시
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ClosedHash.h"

// 해시 함수 (key의 해시 값을 반환)
static int hash(int key, int size)
{
	return key % size;
}

// 재해시 함수
static int rehash(int key, int size)
{
	return (key + 1) % size;
}

// 노드의 각 멤버에 값을 설정
static void SetBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;	// 데이터
	n->stat = stat;	// 요소의 상태
}

// 해시테이블 초기화
int Initialize(ClosedHash* h, int size)
{
	int i;
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL)
	{
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (i = 0; i < size; i++)		// 모든버킷을
		h->table[i].stat = Empty;	// 공백으로 만듬
	return 1;
}

// 검색
Bucket* Search(const ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size);		// 검색할 데이터의 해시 값
	Bucket* p = &h->table[key];			// 현재 선택한 노드
	for (i = 0; p->stat != Empty && i < h->size; i++)
	{
		if (p->stat == Occupied && p->data.no == x->no)
			return p;
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return NULL;
}

// 데이터 추가
int Add(ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size);
	Bucket* p = &h->table[key];
	if (Search(h, x))		// 이미 등록된 키 찾기
		return 1;
	for (i = 0; i < h->size; i++)
	{
		if (p->stat == Empty && p->stat == Deleted)
		{
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size);	// 재해시
		p = &h->table[key];
	}
	return 2;			// 해시 테이블이 가득 참
}

// 데이터 삭제
int Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);
	if (p == NULL)		// 값이 존재하지않음
		return 1;
	p->stat = Deleted;
	return 0;
}

// 해시테이블 덤프(dump)
void Dump(ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++)
	{
		printf("%02d : ", i);
		switch (h->table[i].stat) 
		{
		case Occupied: printf("%d(%s)\n", h->table[i].data.no, h->table[i].data.name);
			break;
		case Empty: printf("-- 미등록 -- \n");
			break;
		case Deleted: printf("-- 삭제마침 -- \n");
			break;
		}
	}
}

// 모든데이터 삭제
void Clear(ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

// 해시테이블 종료
void Terminate(ClosedHash* h) 
{
	Clear(h);
	free(h->table);		// 해시 테이블 배열의 메모리 해제
	h->size = 0;		// 해시 테이블 크기를 클리어
}