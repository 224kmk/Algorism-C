#include <string.h>
#include <stdio.h>

int main()
{
	char name[10];
	printf(" �̸��� �Է��ϼ��� : ");
	scanf("%s", name);

	if (strcmp(name, "��α�") == 0) { // ��α��� �׳� ��������.
		printf("%s, �ȳ�", name);
	}
	else {
		printf("%s��, �ȳ��ϼ���.\n", name);
	}
	return 0;
}