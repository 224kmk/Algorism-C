// ��Ʈ���� ���� BitSet ���
#ifndef __BitSet
#define __BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0		// ������
#define BitSetBits (32)				// ��ȿ ��Ʈ ��
#define Setof(no) ((BitSet)1 <<(no))	// ���� (no)


// ���տ� n�� �ִ��� Ȯ��
int IsMember(BitSet s, int n);

// ���� s�� n�߰�
void Add(BitSet* s, int n);

// ���� s���� n����
void Remove(BitSet* s, int n);

// ���� s�� ���� ����
int Size(BitSet s);

// ���� s�� ��� ���� ���
void Print(BitSet s);

// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)
void Println(BitSet s);

#endif