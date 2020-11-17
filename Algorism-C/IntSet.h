// int�� set ���
#ifndef __IntSet
#define __IntSet

// ������ �����ϴ� ����ü
typedef struct {
    int max;      // ������ ũ��
    int num;      // ������ ���� ����
    int* set;
} IntSet;

// ���� �ʱ�ȭ
int Initialize(IntSet* s, int max);

// ���տ� n�� �ִ��� Ȯ��
int IsMember(const IntSet* s, int n);

// ���� s�� n�߰�
void Add(IntSet* s, int n);

// ���� s���� n����
void Remove(IntSet* s, int n);

// ���� s�� ���� �� �ִ� �ִ� ���� ����
int Capacity(const IntSet* s);

// ���� s�� ���� ����
int Size(const IntSet* s);

// ���� s2�� s1�� ����
void Assign(IntSet* s1, const IntSet* s2);

// ���� s1�� s2�� ������ Ȯ��
int Equal(const IntSet* s1, const IntSet* s2);

// ���� s2�� s3�� �������� s1�� ����
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3);

// ���� s2�� s3�� �������� s1�� ����
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3);

// ���� s2���� s�� �� �������� s1�� ����
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s);

// ���� s�� ��� ���� ���
void Print(const IntSet* s);

// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)
void Println(const IntSet* s);

// ���� ����
void Terminate(IntSet* s);

#endif