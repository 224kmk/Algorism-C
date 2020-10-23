#include <stdio.h>

int main() 
{
	int i, n;
	int sum;
	// while 문은 기존에 숫자를 정해놓고 초기화 해야함
	// ex) i = 1; sum = 0;
	for (i = 1; i <= n; i++) 
	{
		sum += i;
		i++;
	}
	// do {
	// } while (no < 10 || no>99); 의 식과
	// do {
	// } while !(no >= 10 || no<=99); 식과 같다.
}
// 최댓값구하기
int max3(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
} // 이런식의 함수도 구현가능

int med3(int a, int b, int c)
{
	if (a >= b) // a와 b 비교
		if (b >= c) // b 와 c 비교
			return b; // a > b > c 순
		else if (a <= c) // a와 c 비교 
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}
// 다르게 식을 정렬하면
int med3(int a, int b, int c)
{
	if ((a <= b && a>=c) || (a>=b && a <= c)) // a가 b보다 작고 c보다는 클때, a가 b보다는 크고 c보다는 작을때
		return a;	// a값 반환
	else if ((b > a && b < c) || (b < a && b > c)) // 위의 값에서 b의 크기 비교
		return b;
	else
		return c;
}
