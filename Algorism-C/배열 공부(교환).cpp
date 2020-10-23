#include <stdio.h>
#include <stdlib.h>
// 역순 정렬 횟수는 요소 횟수의 n/2임.
// 그러므로 요소의 개수가 n개인 배열요소를 역순으로 정렬하는 알고리즘을 간단히 나타내면
// for (i = 0; i < n / 2; i++)임

// 교환.
// 알고리즘 x의 값 t에 보관 y를 x에 대입 t의 x값을 y에 대입. x->t, y->x, t->y
# define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
		swap(int, a[i], a[n - i - 1]); // 역순의 정렬과정에서 a[i] = x, a[n-i-1] = y임. 0부터시작이기때문
}
int main()
{
	int i;
	int* x;
	int nx;

	printf(" 요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("정수의 개수를 입력하세요 : \n");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d]", i);
		scanf_s("%d", &x[i]);
	}

	ary_reverse(x, nx);
	printf("배열의 요소를 역순으로 정렬했습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, &x[i]);
	free(x);

	return 0;
}

