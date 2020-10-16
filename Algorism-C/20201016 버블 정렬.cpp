#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0) // 연산이 3번 일어남

// 연산이 3 * n(n-1) / 4 이기때문에 시간복잡도는 O(n^2)이다.
void bubble(int a[], int n) // a[]는 배열을 입력만해주기때문에 메인에서 크기를 정해줌
{
	int i, j;
	// 여기가 중요 정렬 프로그램
	// 맨 처음 n-1은 비교횟수를 뜻함
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])	// if 문이 참이면 교환이 일어남
				swap(int, a[j - 1], a[j]);
	}
}

int main(void)
{
	int i, nx;
	int* x;			// 배열의 첫 번째 요소에 대한 포인터

	
	printf("버블 정렬\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int *)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);			// 배열 x를 버블 정렬

	printf("오름차순으로 정렬했습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}