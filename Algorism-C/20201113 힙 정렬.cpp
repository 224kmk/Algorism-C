// 힙 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x, x = y, y= t;} while(0)

// a[left]를 ~ a[right]로 만드는 함수
static void downheap(int a[], int left, int right)
{
	int temp = a[left];		// 맨위의 부모노드 루트
	int child;				// 자식 노드
	int parent;				// 부모 노드
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1;	// 왼쪽노드는 부모의 노드 두배의 +1
		int cr = cl + 1;			// 오른쪽 노드는 왼쪽 노드의 +1
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl; // 자식노드가 자리를 찾아 올라가는 과정 
		if (temp >= a[child])		// 종료조건 temp가 자식노드보다 커졌을때
			break;
		a[parent] = a[child];		// 자리를 찾을때까지 부모노드와 자식노드를 교환.
	}
	a[parent] = temp;		// 자리를 찾으면 temp에 넣음
}

// 힙 정렬 함수
void heapsort(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)	// 맨 끝의 노드에서 하나씩 -를 하면서 정렬
		downheap(a, i, n - 1);			// 배열 a를 힙 정렬로 변환.
	for (i = n - 1; i > 0; i--)		// 하나를 뺀 후 다시 힙 정렬을 시킴
	{
		swap(int, a[0], a[i]);		// 맨위의 부모노드를 빼서 i위치와 바꿈
		downheap(a, 0, i - 1);		// 이 과정을 반복함.
	}
}

int main()
{
	int i, nx;
	int* x;
	puts("힙 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);	// 배열 x를 힙 정렬함.
	printf("오름차순으로 정렬했습니다. \n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}