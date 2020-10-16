// 순차곱셉의 결과를 재귀적으로 구합니다.
// n! 팩토리얼 순차곱셈
// 0! = 1
// n > 0이면 n! = n * (n-1)!
#include <stdio.h>

int factorial(int n)
{
    printf("factorial 진입 n : %d\n", n);
    if (n > 0)
    {
        int result = factorial(n - 1);
        printf("factorial 진출 n : %d\n", n);
        return n * result;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int x;
    printf("정수를 입력하세요 : ");
    scanf_s("%d", &x);
    printf("%d의 순차곱셈의 값은 %d 입니다.\n", x, factorial(x));

    return 0;
}