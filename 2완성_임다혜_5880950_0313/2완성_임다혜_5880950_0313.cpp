#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    float num;
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf_s("%f", &num);

    // 32��Ʈ�� �Ǽ� ���� ��Ʈ ������ ����
    uint32_t bits;
    memcpy(&bits, &num, sizeof(bits));  // �Ǽ��� 32��Ʈ ������ ��ȯ

    // ��ȣ, ����, ���� ��Ʈ�� ����
    int sign = (bits >> 31) & 0x1;  // ��ȣ ��Ʈ
    int exponent = (bits >> 23) & 0xFF;  // ���� ��Ʈ (8��Ʈ)
    int fraction = bits & 0x7FFFFF;  // ���� ��Ʈ (23��Ʈ)

    // ��ȣ, ����, ���� ��Ʈ�� ���
    printf("��ȣ ��Ʈ: %d\n", sign);
    printf("���� ��Ʈ: %08X\n", exponent);  // 8��Ʈ 16���� ���
    printf("���� ��Ʈ: ");
    for (int i = 22; i >= 0; i--) {  // 23��Ʈ ���� ���
        printf("%d", (fraction >> i) & 0x1);
    }
    printf("\n");

    return 0;
}
