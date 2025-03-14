#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    float num;
    printf("실수를 입력하세요: ");
    scanf_s("%f", &num);

    // 32비트로 실수 값의 비트 패턴을 저장
    uint32_t bits;
    memcpy(&bits, &num, sizeof(bits));  // 실수를 32비트 정수로 변환

    // 부호, 지수, 가수 비트를 추출
    int sign = (bits >> 31) & 0x1;  // 부호 비트
    int exponent = (bits >> 23) & 0xFF;  // 지수 비트 (8비트)
    int fraction = bits & 0x7FFFFF;  // 가수 비트 (23비트)

    // 부호, 지수, 가수 비트를 출력
    printf("부호 비트: %d\n", sign);
    printf("지수 비트: %08X\n", exponent);  // 8비트 16진수 출력
    printf("가수 비트: ");
    for (int i = 22; i >= 0; i--) {  // 23비트 가수 출력
        printf("%d", (fraction >> i) & 0x1);
    }
    printf("\n");

    return 0;
}
