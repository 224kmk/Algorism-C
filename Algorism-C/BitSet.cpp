// IntSet �ҽ��ڵ�
#include <stdio.h>
#include <stdlib.h>
#include "BitSet.h"

// ����s�� n�� �ִ��� Ȯ��
int IsMember(BitSet s, int n)
{
    return s & Setof(n);
}

// ���� s�� n�� �߰�
void Add(BitSet* s, int n)
{
    *s |= Setof(n);
}

// ���� s���� n�� ����
void Remove(BitSet *s, int n)
{
    *s &= ~Setof(n);
}

// ���� s�� ���� ���� ��ȯ
int Size(BitSet s)
{
    int n = 0;
    for (; s != BitSetNull; n++)
        s &= s - 1;
    return n;
}

// ���� s�� ��� ���� ���
void Print(BitSet s)
{
    int i;
    printf(" { ");
    for (i = 0; i < BitSetNull; i++)
        if (IsMember(s, i))
            printf("%d", i);
    printf("}");
}

// ���� s�� ��� ���� ���(�ٹٲ� ����)
void Println(BitSet s)
{
    Print(s);
    putchar('\n');
}