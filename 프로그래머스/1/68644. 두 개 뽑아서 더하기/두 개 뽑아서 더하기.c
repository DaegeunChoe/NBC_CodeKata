#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// qsort용 함수
int comp(const void* first, const void* second)
{
    int* a = (int*)first;
    int* b = (int*)second;
    if (*a > *b)
    {
        return 1;
    }
    else if (*a < *b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) 
{
    // 100개의 원소를 서로 더해 나올 수 있는 경우의 수는 100*99/2 = 4950
    int n_add = 0;
    int Adds[4950];
    for (int i = 0; i < numbers_len; i++ )
    {
        for (int j = i + 1; j < numbers_len; j++)
        {
            Adds[n_add] = numbers[i] + numbers[j];
            n_add += 1;
        }
    }
    
    // 정렬
    qsort(Adds, n_add, sizeof(int), comp);
    
    // 중복 제거
    int n_unique = 1;
    int Uniques[4950];
    Uniques[0] = Adds[0];
    for (int i = 1; i < n_add; i++)
    {
        if (Uniques[n_unique - 1] != Adds[i])
        {
            Uniques[n_unique] = Adds[i];
            n_unique += 1;
        }
    }
    
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* Answer = (int*)malloc(sizeof(int) * n_unique);
    for (int i = 0; i < n_unique; i++)
    {
        Answer[i] = Uniques[i];
    }
    return Answer;
}