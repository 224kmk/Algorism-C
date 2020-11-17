// 도수 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>

// 도수 정렬 함수 ( 배열의 요소값은 0 이상 MAX 이하)
void fsort(int a[], int n, int max)
{
    int i;
    int* f = (int*)calloc(max + 1, sizeof(int));   // 도수를 누적시킬 배열을 생성.
    int* b = (int*)calloc(n, sizeof(int));         // 작업용 배열을 생성

    // 도수 정렬의 4단계
    // 1. 도수 분포표 작성
    // 2. 누적도수분포표 작성
    // 3. 목적 배열 만들기
    // 4. 배열 복사
    for (i = 0; i <= max; i++)      // 도수에 값을 입력함 
        f[i] = 0;               // 입력한 값을 도수에 하나씩 넣어줌

    for (i = 0; i < n; i++)         // << 1번
        f[a[i]]++;               // 빈도수를 f 배열의 값에 넣어줌

    for (i = 1; i <= max; i++)      //   << 2번
        f[i] += f[i - 1];         // 누적도수분포로 만드는과정

    for (i = n - 1; i >= 0; i--)   // f배열의 오른쪽부터 시작해서 왼쪽으로 가는 과정 << 3번
        b[--f[a[i]]] = a[i];      // a 배열의 값을 f값의 최대자리를 차고 그 자리의 인덱스 값의 --로 하나씩 넣어줌

    for (i = 0; i < n; i++)         // << 4번
        a[i] = b[i];            // 정리된 b배열의 값을 a에 넣어줌

    free(b);
    free(f);
}

int main()
{
    int i, nx;
    int* x;
    const int max = 100;   // 배열의 최대 값 설정
    puts(" 도수 정렬 ");
    printf("요소 개수 : ");
    scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));
    printf("0~ %d의 정수를 입력하세요. \n", max);

    for (i = 0; i < nx; i++)
    {
        do {
            printf("x[%d] : ", i);
            scanf_s("%d", &x[i]);
        } while (x[i] < 0 || x[i] > max);   // x의 인덱스 0보다 작거나 x의 인덱스가 max보다 클지 않을때 do구문 반복
    }

    fsort(x, nx, max);      // 배열 x를 도수 정렬
    puts("오름차순으로 정렬했습니다.");

    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);

    return 0;
}