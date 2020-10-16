// 버블 정렬 개선. 각각의 패스에서 비교, 교환을 하다가 교환이 수행되지않으면
// 그 보다 앞쪽의 요소는 이미 정렬을 마친 상태.
// 앞쪽 요소 제외한 요소에 대해 비교, 교환 수행
// ex) ppt 16
#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0) 

void bubble(int a[], int n)
{
	int k = 0;			// a[k]보다 앞쪽의 요소는 정렬을 마친 상태를 뜻함.
	while (k < n - 1)
	{
		int j;
		int last = n - 1;	// last를 선언하여 마지막으로 교환을 수행한 위치를 저장
		for (j = n - 1; j > k; j--)
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		k = last;
	}
}

int main(void)
{
	int i, nx;
	int* x;


	printf("버블 정렬\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	printf("오름차순으로 정렬했습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}