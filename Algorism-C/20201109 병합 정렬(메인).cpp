#include <stdio.h>
#include <stdlib.h>

static int* buff; // 작업용 배열

static void __mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        int p = 0;         // buff의 크기
        int i;            // a의 index로 사용
        int j = 0;         // buff의 index로 사용
        int k = left;      // 왼쪽 맨끝을 의미
        // 재귀를 이용하여 원소가 하나 남을때까지 반복
        __mergesort(a, left, center);      // 앞부분에 대한 병합 정렬
        __mergesort(a, center + 1, right);   // 뒷부분에 대한 병합 정렬
        for (i = left; i <= center; i++)
            buff[p++] = a[i];         // 배열 a의 앞부분을 buff에 넣음
        while (i <= right && j < p)      // 배열이 끝에까지 도달하지 않았을때를 의미
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];   // k에 buff와 a랑 비교하여 작으면 buff의 index를, 크면 a의 index를 넣음
        while (j < p)
            a[k++] = buff[j++];         // 둘중 하나가 끝까지 도달하고 남은것들을 뒤에 넣음
    }
}

int mergesort(int a[], int n)
{
    if ((buff = (int*)calloc(n, sizeof(int))) == NULL)
        return -1;
    __mergesort(a, 0, n - 1);      // 배열 전체를 병합 정렬
    free(buff);
    return 0;
}

int main()
{
    int i, nx;
    int* x;
    puts("병합 정렬");
    printf("요소 개수 : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] :   ", i);
        scanf_s("%d", &x[i]);
    }
    mergesort(x, nx);
    puts("오름차순으로 정렬했습니다.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}