// 단순 선택 정렬 : 가장 작은요소부터 선택해 아랒은 위치로 옮겨서 순서대로 정렬

void selection(int a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int min = i;            // 배열의 첫 요소를 i로 정의
        for (j = i + 1; j < n; j++)   //* 중요
            if (a[j] < a[min])
                min = j;
        swap(int, a[i], a[min]);
    }
}

// 단순 삽입 정렬 : 선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 삽입하는 작업을 반복하여 정렬
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

int main()
{
    int i, nx;
    int* x;
    printf("단순 삽입 정렬\n");

    printf("요소 개수 : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf_s("%d", &x[i]);
    }

    insertion(x, nx);

    printf("오름차순으로 정렬했습니다.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

    return 0;
}