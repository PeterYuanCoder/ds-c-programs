#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // 外层循环控制排序轮数
    for (i = 0; i < n - 1; i++) {
        // 内层循环进行相邻元素比较
        for (j = 0; j < n - 1 - i; j++) {
            // 如果前一个元素大于后一个，则交换
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 打印数组
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("排序后: ");
    printArray(arr, n);
    
    return 0;
}