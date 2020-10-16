// 20201012 Queue
// int�� ť IntQueue�� ����ϴ� ���α׷�
#include <stdio.h>
#include "IntQueue.h"

int main() {
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        printf("ť�� ������ �����Ͽ����ϴ�.\n");
        return 1;
    }
    while (1) {
        int m, x;
        printf("���� ������ �� %d %d \n", Size(&que), Capacity(&que));
        printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)���� : ");
        scanf_s("%d", &m);

        if (m == 0)break;
        switch (m) {
        case 1:      // ��ť
            printf("������ : ");
            scanf_s("%d", &x);
            if (Enque(&que, x) == -1)
                printf("\a���� : ��ť�� �����߽��ϴ�.\n");
            break;

        case 2:      // ��ť
            if (Deque(&que, &x) == -1)
                printf("\a���� : ��ť�� �����߽��ϴ�.\n");
            else
                printf("��ť�� �����ʹ� %d �Դϴ�.\n", x);
            break;

        case 3:
            if (Peek(&que, &x) == -1)
                printf("\a���� : ��ũ�� �����߽��ϴ�.\n");
            else
                printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4:
            Print(&que);
            break;
        }
    }
    Terminate(&que);
    return 0;
}