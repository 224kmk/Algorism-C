#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int i;
	int max = a[0];
	for (i=1; i<n; i++)
		if (a[i] > max) max = a[i];
	return max;
}

int main()
{
	int i=0;
	int* height;
	int number;
	printf("사람의 수 : ");
	scanf_s("%d", &number);
	height = (int *)calloc(number, sizeof(int));
	srand(time(NULL));
	printf("%d의 사람의 키를 입력하세요 : \n", number);
	for (i < 0; i < number; i++)
	{
		height[i] = 100 + rand() % 90; // 랜덤해서 101 ~ 189까지 나타내라
		printf("height[%d] = %d\n ", i, height[i]);
	}

	printf("최대값은 %d입니다. \n", maxof(height, number));
	free(height);

	return 0;
}

