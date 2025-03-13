#include <stdio.h>
#include <stdint.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    float num;
    // �Ǽ� �Է� �ޱ�
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf_s("%f", &num);

    // float ���� 32��Ʈ�� ����ϱ� ���� union ���
    union {
        float f;
        uint32_t i;
    } u;

    u.f = num;

    // ��ȣ 
    int sign = (u.i >> 31) & 0x1;

    // ���� 
    int exponent = ((u.i >> 23) & 0xFF) - 127;

    // ����
    int mantissa = u.i & 0x7FFFFF;

    // ��ȣ, ����, ���� ���
    printf("��ȣ : %d\n", sign);
    printf("����: %02X\n", exponent + 127);  // ���̾�� �߰��Ͽ� ���
    printf("����: %06X\n", mantissa);

    return 0;
}
