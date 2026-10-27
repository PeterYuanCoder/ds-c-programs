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

void TestSelectSort() {
    int a[] = { 9,1,2,5,7,4,6,3 };

    PrintArray(a, sizeof(a) / sizeof(int));
    SelectSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}


void TestShellSort() {
    int a[] = { 9,1,2,5,7,4,6,3,5 };
    //int a[] = {9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
    PrintArray(a, sizeof(a) / sizeof(int));
    ShellSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}


void TestQuickSort() {
    int a[] = { 23,44,38,5,47,15,36,26,27,2 };

    PrintArray(a, sizeof(a) / sizeof(int));
    // PartitionDigHole(a, 0, sizeof(a) / sizeof(int) - 1);
    QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
    PrintArray(a, sizeof(a) / sizeof(int));
}



int main()
{
    //TestInsertSort();
    
    //TestShellSort();

    //TestSelectSort();

    TestQuickSort();
    
    return 0;
}