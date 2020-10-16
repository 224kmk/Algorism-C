// 최대 공약수 구하기
// 유클리드 호제법을 이용
#include <stdio.h>

// 정수 x, y의 최대공약수를 반환
int gcd(int x, int y)
{
    if (y == 0)
    {
        printf("gcd 진입 : %d\n", x);
        return x;
    }
    else
    {
        printf("gcd 진출 : %d\n", y);
        return gcd(y, x % y);
    }
}

int main()
{
    int x, y;
    printf("최대 공약수를 구합니다.\n");
    printf("정수를 입력하세요 : ");
    scanf_s("%d", &x);
    printf("정수를 입력하세요 : ");
    scanf_s("%d", &y);
    printf("최대공약수는 %d입니다.\n", gcd(x, y));

    return 0;
}