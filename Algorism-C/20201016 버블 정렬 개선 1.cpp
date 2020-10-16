// 버블 정렬 개선. 교환 횟수를 체크하여 정렬확인.
// 교환이 수행되지 않았다면 정렬을 멈춤.
// ex) ppt 12
#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0) 

void bubble(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;			// 교환 횟수를 체크해줄 변수를 선언
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0) break;	// 교환을 수행하지 않았다면 정렬을 멈춤.
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