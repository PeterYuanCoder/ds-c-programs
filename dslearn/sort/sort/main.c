#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"


void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestInsertSort() {
    int a[] = { 2,4,1,7,8,3,9,2 };
    InsertSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
    TestInsertSort();
    return 0;
}