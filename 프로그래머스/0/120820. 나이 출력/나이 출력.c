#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int Age)
{
    // 나이 기준은 2022년
    // [출생연도] + Age - 1 = 2022
    // [출생연도] = 2022 - Age + 1
    return 2022 - Age + 1;
}