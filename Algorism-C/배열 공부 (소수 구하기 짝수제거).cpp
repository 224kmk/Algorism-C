#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int prime[500];	// 소수를 저장하는 배열
	int ptr = 0;	// 이미 얻은 소수의 개수
	unsigned long counter = 0;
	prime[ptr++] = 2;
	for (n = 3; n <= 1000; n += 2) {	// 2로 나누어지는 수는 소수가 아님.
		for (i = 1; i < ptr; i++) {		// 이미 얻은 소수를 나눔.
			counter++;
			if (n % prime[i] == 0)	// 나누어떨어지므로 소수가 아님.
				break;
		if (ptr == i)			// 마지막까지 나누어떨어지지 않았다면
			prime[ptr++] = n;	// 배열에 저장.
	}
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	printf("나눗셈을 실행한 횟수 %d", counter);
	return 0;
}

	