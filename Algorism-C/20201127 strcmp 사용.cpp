#include <string.h>
#include <stdio.h>

int main()
{
	char name[10];
	printf(" 이름을 입력하세요 : ");
	scanf("%s", name);

	if (strcmp(name, "김민기") == 0) { // 김민기라고 그냥 설정하자.
		printf("%s, 안녕", name);
	}
	else {
		printf("%s님, 안녕하세요.\n", name);
	}
	return 0;
}