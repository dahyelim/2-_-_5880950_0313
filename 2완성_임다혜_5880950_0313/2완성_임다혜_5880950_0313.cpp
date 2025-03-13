#include <stdio.h>
#include <stdint.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    float num;
    // 실수 입력 받기
    printf("실수를 입력하세요: ");
    scanf_s("%f", &num);

    // float 값을 32비트로 취급하기 위해 union 사용
    union {
        float f;
        uint32_t i;
    } u;

    u.f = num;

    // 부호 
    int sign = (u.i >> 31) & 0x1;

    // 지수 
    int exponent = ((u.i >> 23) & 0xFF) - 127;

    // 가수
    int mantissa = u.i & 0x7FFFFF;

    // 부호, 지수, 가수 출력
    printf("부호 : %d\n", sign);
    printf("지수: %02X\n", exponent + 127);  // 바이어스를 추가하여 출력
    printf("가수: %06X\n", mantissa);

    return 0;
}
