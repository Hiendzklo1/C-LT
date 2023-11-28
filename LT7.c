#include <stdio.h>
#include <stdlib.h>
int isDuplicate(int *result, int resultSize, int element) {
    for (int i = 0; i < resultSize; i++) {
        if (result[i] == element) {
            return 1; // Trùng lap
        }
    }
    return 0; // Không trùng lap
}
int* uniqueElements(int arr1[], int size1, int arr2[], int size2, int *resultSize) {
    int maxSize = size1 + size2;
    int *result = (int *)malloc(maxSize * sizeof(int));
    if (!result) {
        fprintf(stderr, "Khong du bo nho\n");
        exit(EXIT_FAILURE);
    }
    *resultSize = 0;
    for (int i = 0; i < size1; i++) {
        if (!isDuplicate(result, *resultSize, arr1[i])) {
            result[*resultSize] = arr1[i];
            (*resultSize)++;
        }
    }
    for (int i = 0; i < size2; i++) {
        if (!isDuplicate(result, *resultSize, arr2[i])) {
            result[*resultSize] = arr2[i];
            (*resultSize)++;
        }
    }
    return result;
}
int main() {
    int size1, size2;
    printf("Nhap kich thuoc cua mang thu nhat: ");
    scanf("%d", &size1);
    int array1[size1];
    printf("Nhap cac phan tu cua mang thu nhat:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Nhap kich thuoc cua mang thu hai: ");
    scanf("%d", &size2);
    int array2[size2];
    printf("Nhap cac phan tu cua mang thu hai:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }
    int resultSize;
    int *resultArray = uniqueElements(array1, size1, array2, size2, &resultSize);
    printf("Cac phan tu khong trung lap la: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", resultArray[i]);
    }
    free(resultArray); // giai phóng bo nho sau khi su dung
    return 0;
}

