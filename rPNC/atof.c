#include <stdio.h>
#include <ctype.h>

// #define _TEST

#ifdef _TEST
double atof(char s[]);

int main(void) {
    printf("%f\n", atof(" -12.2324\b"));
    return 0;
}
#endif

// 문자열을 double타입 변수로 변환
double atof(char s[]) {
    double val, power;
    int i, sign;

    // remove white space
    for(i = 0; isspace(s[i]); i++);

    // 부호계산
    sign = (s[i] == '-') ? -1 : 1;

    // -나 +가 나오면 무시
    if((s[i] == '-') || (s[i] == '+')) i++;

    // 소수점 앞에 있는 숫자 계산
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // 소수점 건너뛰기
    if(s[i] == '.') i++;

    // 소수점을 무시한 상태로 계산 (얼마나 뒤로갔는지는 power로 체크)
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // 123.456 -> +1 * 123456 / 1000.0
    return (sign * val / power);
}
